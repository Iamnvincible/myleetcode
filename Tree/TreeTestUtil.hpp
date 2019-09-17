#include <algorithm>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include "TreeNode.h"
/*
清除字符串input左侧空白字符
input:字符串
 */

void trimLeftTrailingSpaces(std::string& input) {
  input.erase(input.begin(), std::find_if(input.begin(), input.end(),
                                          [](int ch) { return !isspace(ch); }));
}
/*
清除字符串input右侧空白字符
input:字符串
 */
void trimRightTrailingSpaces(std::string& input) {
  input.erase(
      find_if(input.rbegin(), input.rend(), [](int ch) { return !isspace(ch); })
          .base(),
      input.end());
}
/*
将代表树的字符串转换为树的数据结构
input:字符串，格式为[1,2,3,4],用方括号代表的整数数组，以逗号为分隔符
返回值:树的根节点
思路：
输入的字符串是以一种特殊的层序遍历二叉树字符串，
相比完全二叉树，当某一个子树为空时，用null表示空子树，更下层不存在的节点不必表示
以层序输入就以层序构造二叉树，用队列实现
注意保存根节点指针
 */
TreeNode* stringToTreeNode(std::string input) {
  ///清除输入字符串两边空格
  trimLeftTrailingSpaces(input);
  trimRightTrailingSpaces(input);
  //输入为[]形式
  //获得[]中的字符串
  input = input.substr(1, input.length() - 2);
  //空树判断
  if (!input.size()) {
    return nullptr;
  }

  std::string item;
  std::stringstream ss;  //字符串流
  ss.str(input);         //用input替换ss的内容
  //从ss中以分隔符‘,’，读取第一个分隔符前的字符串，放入item中
  getline(ss, item, ',');
  //创建根节点
  TreeNode* root = new TreeNode(stoi(item));
  //根节点入队列
  std::queue<TreeNode*> nodeQueue;
  nodeQueue.push(root);

  while (true) {
    TreeNode* node = nodeQueue.front();
    nodeQueue.pop();
    //读取一个节点，getline为EOF时推出循环
    if (!getline(ss, item, ',')) {
      break;
    }
    //附到node的左子树
    trimLeftTrailingSpaces(item);
    //当节点不为空时，向出栈节点左指针赋值
    //当节点为空时，不需要赋值，因为new出来节点初始化时左右指针为空
    if (item != "null") {
      //初始化节点
      int leftNumber = stoi(item);
      node->left = new TreeNode(leftNumber);
      //并将新节点加入队列（也就是node的左子树）
      nodeQueue.push(node->left);
    }
    //读取节点，附到右子树
    if (!getline(ss, item, ',')) {
      break;
    }
    trimLeftTrailingSpaces(item);
    if (item != "null") {
      int rightNumber = stoi(item);
      node->right = new TreeNode(rightNumber);
      nodeQueue.push(node->right);
    }
  }
  return root;
}
/*
特殊的层序遍历二叉树，输出结果到方括号数组中
正常层序遍历按层输出有值的节点的值
而此函数输出时，对于某一子树为空时输出一次null，该子树下层的空节点不再输出
root:二叉树根节点
 */
std::string treeNodeToString(TreeNode* root) {
  if (root == nullptr) {
    return "[]";
  }

  std::string output = "";  //结果字符串，读取节点在后面附加字符
  std::queue<TreeNode*> q;  //队列，用于层序遍历
  q.push(root);             //初始情况，根节点入队
  while (!q.empty()) {
    //读取队列头，并出队
    TreeNode* node = q.front();
    q.pop();
    //先读取节点本身值
    //再先后将左右子树指针入队，以满足层序遍历次序

    //这是一种特殊的层序遍历
    //如果某一子树为空，输出至多一次null
    if (node == nullptr) {
      output += "null, ";
      continue;
    }
    output += std::to_string(node->val) + ", ";
    q.push(node->left);
    q.push(node->right);
  }
  //返回时去除末尾的“, ”
  return "[" + output.substr(0, output.length() - 2) + "]";
}
TreeNode* generate_tree(std::string line) {
  std::stringstream s(line);
  TreeNode* root = stringToTreeNode(line);
  return root;
}
void print_tree(TreeNode* root) {
  std::string out = treeNodeToString(root);
  std::cout << out << std::endl;
}