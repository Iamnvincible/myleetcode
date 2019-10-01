#ifndef SOLUTION_96
#define SOLUTION_96
/*
Given n, how many structurally unique BST's (binary search trees) that store
values 1 ... n?
给出n个节点，求n个节点能构造出几种结构不同的二叉查找树

对于根节点为i的二叉查找树，所有可能数量为
左子树的构造数量×右子树的构造数量
给定节点数，构造数量是确定的
空树 1种
1个节点 1种
2个节点 数量=1为根节点时的构造数量+2为根节点时的构造数量
1为根节点时的数量为左子树为空，数量为1 乘上右子树只有1个节点，数量为1，积为1
2为根节点时数量为1
加起来总数为2
3个节点 数量为=1为根节点+2为根节点+3为根节点
......
已经算过的可以用一个数组存下来，后面直接取
 */
#include <vector>
class Solution_96 {
 public:
  int numTrees(int n) {
    //或 int f[n+1]={0};
    std::vector<int> f(n + 1, 0);
    f[0] = 1;
    f[1] = 1;
    for (int i = 2; i <= n; i++) {
      for (int k = 0; k < i; k++) {
        f[i] += f[k] * f[i - k - 1];
      }
    }
    return f[n];
  }
};
#endif