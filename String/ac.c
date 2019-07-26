/*
Aho–Corasick算法
wiki:https://zh.wikipedia.org/zh-hans/AC%E8%87%AA%E5%8A%A8%E6%9C%BA%E7%AE%97%E6%B3%95
类似于KMP的字符串匹配算法,区别在于AC算法能够同时匹配多个模式串，效率更高
算法分为三个步骤
1. 构建由模式串构成的TRIE树结构
2. 构建节点的失配指针，通过当前匹配字符串的部分后缀找到以此后缀为前缀的字符串
3. 查询，给定匹配字符串，查询模式串的出现位置
********************************
Jay Lin
2019/07/27@Beijing
********************************
 */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int word = 26;  //英文字母数
struct Node {
  struct Node* fail;        //失配指针
  struct Node* next[word];  //后继指针，最多26个，没有的为NULL
  int count;  //记录节点是否是字符串的结尾字符，-1为默认值，其他非负值作为模式串下标
};
struct Node* Queue[50000];  //简易队列
int head = 0, tail = 0;     //队列头尾标志
/*
向Trie树中插入新模式串
string:新模式字符串
root:Trie树根节点
index:插入串的下标
 */
void insert(char* string, struct Node* root, int index) {
  struct Node* p = root;
  int i = 0;
  while (string[i]) {
    if (isalpha(string[i])) {
      char c = tolower(string[i]);
      int index = c - 'a';
      //如果还没有这个字母节点
      if (p->next[index] == NULL) {
        //分配新节点
        p->next[index] = (struct Node*)malloc(sizeof(struct Node));
        memset(p->next[index]->next, 0, sizeof(&root) * word);
        p->next[index]->count = -1;
        p->next[index]->fail = NULL;
      }
      //创造节点之后就可以赋值了
      p = p->next[index];
      i++;
    }
  }
  //记录这个节点为字符串的结尾字符
  // count>0就可以了
  p->count = index;
}
/*
在Trie树中构建节点失配指针
root:Trie树的根节点
 */
void build_fail(struct Node* root) {
  head = 0;
  //根节点的失配指针指向自身
  root->fail = root;
  //将根节点入队列
  Queue[tail++] = root;
  //当队列不为空
  while (head != tail) {
    // temp作为父节点,从队列出队
    // printf("out of queue num = %d\n", head);
    struct Node* temp = Queue[head++];
    // f作为父节点的失配指针
    struct Node* f = temp->fail;
    //遍历所有子节点指针，找到非空的子节点
    for (size_t i = 0; i < word; i++) {
      if (temp->next[i]) {
        //广度优先遍历，将子节点入队列
        // printf("in queue num = %d:%c\n", tail, i + 'a');
        Queue[tail++] = temp->next[i];
        //根节点的所有子节点的失配指针指向根节点
        if (temp == root) {
          temp->next[i]->fail = f;  //=root
        } else {
          //默认所有上一层节点的失配指针已经求出，所以f!=NULL
          //如果temp不是根节点的子节点
          //尝试将新字符加入
          //如果加入失败，则继续找失配节点的失配节点
          while (f->next[i] == NULL) {
            if (f == root) {
              temp->next[i]->fail = root;
              break;
            }
            f = f->fail;
          }
          if (f->next[i]) {
            temp->next[i]->fail = f->next[i];
          }
        }
      }
    }
  }
}
/*
在string中查找预先构建好的模式串，模式串结构由Trie树确定
string:供查找的字符串
root:构建好的模式串Trie树
paterns:模式串数组

返回值：成功匹配到的模式串数量
 */
int query(char* string, struct Node* root, char** patterns) {
  int i = 0;
  int ans = 0;
  struct Node* p = root;
  while (string[i]) {
    if (isalpha(string[i])) {
      char c = tolower(string[i]);
      //获得下标
      int index = c - 'a';
      struct Node* temp = NULL;
      //尝试通过下标访问字符节点
      //两种情况
      // 1. 如果访问结果为NULL，说明新字符不能和模式串匹配
      // 2. 如果不为NULL，新字符得到匹配
      temp = p->next[index];

      // 情况1
      // temp == NULL
      //尝试fail指针，直到走到root节点
      // temp = p->fail->next[index]
      //另外要注意：
      //状态转移后的状态前缀可能和当前所处字符的后缀相符
      //同时该前缀是一个字符串的结尾（一个匹配成功状态）
      // p->fail!=root && p->fail->count>0
      //这种情况应该比下面尝试转移到失败指针后一个节点的情况的优先
      //但是这种情况其实包含再下面情况2中，在匹配成功一个字符串时会去检查失配指针
      //只要记录了匹配成功时的指针，在循环检查失配指针完成后
      //将temp指针指回先前记录的指针即可
      while (temp == NULL && p != root) {
        temp = p->fail->next[index];
        p = p->fail;
      }
      //尝试完以后有两种情况
      // 1. 可能找到子串了,temp!=NULL,p!=root
      //如果找到了temp!=NULL不会到下面的判断，直接到下面的的匹配成功情况
      // 2. p走到root了，彻底没有找到，temp==NULL, p==root
      //这时不能让temp进到下面匹配成功的循环中
      //将其置为root即可
      if (temp == NULL) {
        temp = root;
      }

      // 2. 匹配到了，且是一个模式串的终止字符处
      // temp!=root,temp->count>0
      struct Node* flag = temp;
      while (temp != root && temp->count >= 0) {
        // printf("count = %d index = %d\n", temp->count, index);
        printf("Found target pattern at position[%d],pattern [%s]\n", i,
               patterns[temp->count]);
        ans++;
        // temp->count = -1;
        //在匹配到的情况下，再找以当前匹配成功字符串后缀为前缀的模式串
        temp = temp->fail;
        //此外，如果当前位置之后的一位也可以匹配
        //应该记录一下循环开始时的节点位置
      }
      temp = flag;
      //可能找到字串，但字串不是终止字符 temp!=root temp!=NULL temp->count==0
      if (temp != root && temp != NULL) {
        p = temp;
      }
      //下标后移
      i++;
    }
  }
  return ans;
}

int main(int argc, char const* argv[]) {
  //模式串，全部为小写字母
  char* patterns[] = {"nihao", "hao", "hs", "hsr", "he", "ao", "h"};
  //匹配串，全部为小写字母
  char* s = "sdmfhsgnshejfgnihaofhsrnihao";
  // Trie树根节点
  struct Node root;
  //初始化
  root.count = -1;
  root.fail = NULL;
  int size = sizeof(patterns) / sizeof(char*);
  memset(root.next, 0, sizeof(&root) * word);
  //向树中插入并构建模式串
  for (size_t i = 0; i < size; i++) {
    insert(patterns[i], &root, i);
  }
  //构建失配指针
  build_fail(&root);
  printf("%s\n", s);
  //查询，返回成功匹配的个数
  int ans = query(s, &root, patterns);
  printf("ans = %d\n", ans);
  return 0;
}