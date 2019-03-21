#ifndef SOLUTION_84
#define SOLUTION_84
#include <algorithm>
#include <stack>
#include <vector>
/*
找出最高和最低元素，
从最低元素高度开始找矩形
O(n^2)的复杂度，会超时
*/
class Solution_84 {
 public:
  int largestRectangleArea(std::vector<int>& heights) {
    int largest = 0;
    if (heights.size() <= 0) {
      return 0;
    }
    auto heightest = *std::max_element(heights.begin(), heights.end());
    auto lowest = *std::min_element(heights.begin(), heights.end());
    for (int i = lowest; i <= heightest; i++) {
      int start = 0;
      for (int j = 0; j < heights.size(); j++) {
        int val = heights[j];
        if (val >= i) {
          largest = std::max(largest, i * (j - start + 1));
        } else {
          start = j + 1;
        }
      }
    }
    return largest;
  }
};
/*
维护一个递增栈，栈中记录遇到比栈顶元素更高的元素
从左到右处理直方
如果遇到的直方高度小于栈顶元素，说明栈顶元素目前是最高的，
保留这个较小高度的位置，
计算最高直方与当前遇到直方之前所有直方可以围成的矩形的面积，
每计算一次矩形面积时，将栈顶元素出栈，表示用来构成矩形用到的最远的直方
如果这个较小位置任然比栈顶元素低，继续出栈，
计算这次出栈元素到较小位置之间能构成的矩形的面积。
依次类推，直到这个较小高度比栈顶元素高后入栈，
对于高度小的直方，能够依靠其他比它高的直方（这些比它高的直方之间不能有比它低的直方隔开）来构造尽可能大的矩形
对于高度高的直方，凭一己之力构造自身大小的矩形
事先需要在直方最后加上一个0高度的直方，以便计算所有栈中剩余元素能构成矩形的面积
非常巧妙！

*/
class Solution_84_bak {
 public:
  int largestRectangleArea(std::vector<int>& heights) {
    std::stack<int> s;
    heights.push_back(0);
    int result = 0;
    int i = 0;
    while (i < heights.size()) {
      //如果直方高度比栈顶元素大则入栈
      if (s.empty() || heights[i] > heights[s.top()]) {
        s.push(i++);
      } else {
        //直方高度不大于栈顶元素，出栈
        //出栈后如果栈为空，计算较高高度和当前位置之间矩形面积
        //如果栈不为空，以当前栈顶高度*到当前遍历位置获得矩形面积，直到i位置不再是最低位置
        int tmp = s.top();  //记录栈顶元素
        s.pop();            //出栈当前最高元素
        result =
            std::max(result, heights[tmp] * (s.empty() ? i : i - s.top() - 1));
        //注意i没有+=1
      }
    }
    return result;
  }
};
#endif