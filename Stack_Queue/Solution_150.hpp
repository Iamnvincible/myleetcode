#ifndef SOLUTION_150
#define SOLUTION_150
/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another
expression.

给出一个合法的逆波兰式，计算其值
就是一个多项式按树的形式，得到后续遍历后的结果，算出其值

 */
#include <stack>
#include <string>
#include <vector>
/*
一个栈用于存放操作数，一个符号存放操作符
从前往后遍历，判断是不是操作数，是数字则入栈
不是数字就是操作符
当栈中有至少两个操作数且有操作符的的条件下
出两个数字，用操作符计算结果，注意两个数字的顺序
栈中最后留下的就是计算结果
 */
class Solution_150 {
 public:
  int evalRPN(std::vector<std::string> &tokens) {
    std::stack<int> val;
    char nota = '0';
    for (int i = 0; i < tokens.size(); i++) {
      auto s = atoi(tokens[i].data());
      if (s) {
        val.push(s);
      } else {
        if (tokens[i] == "0") {
          val.push(0);
        } else
          nota = *tokens[i].data();
      }
      if (val.size() >= 2 && nota != '0') {
        auto right = val.top();
        val.pop();
        auto left = val.top();
        val.pop();
        val.push(cal(left, right, nota));
        nota = '0';
      }
    }
    return val.top();
  }

 private:
  int cal(int a, int b, char nota) {
    switch (nota) {
      case '+':
        return a + b;
      case '-':
        return a - b;
      case '*':
        return a * b;
      case '/':
        return a / b;
    }
    return 0;
  }
};
/*
递归
从后往前找两个数字，计算结果
由逆波兰式的特点，递归式正确，很巧妙
 */
class Solution_150_bak {
 public:
  int evalRPN(std::vector<std::string> &tokens) {
    int x, y;
    //获取最后一个符号
    auto token = tokens.back();
    tokens.pop_back();
    //如果是操作符，递归寻找数字
    if (is_operator(token)) {
      y = evalRPN(tokens);
      x = evalRPN(tokens);
      if (token[0] == '+')
        x += y;
      else if (token[0] == '-')
        x -= y;
      else if (token[0] == '*')
        x *= y;
      else
        x /= y;
    } else {
      size_t i;
      x = stoi(token, &i);
    }
    return x;
  }

 private:
  bool is_operator(const std::string &op) {
    return op.size() == 1 && std::string("+-*/").find(op) != std::string::npos;
  }
};
#endif