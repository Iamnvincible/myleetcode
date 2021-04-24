/*
 * @Author: Jie Lin
 * @Date: 2021-04-23 21:28:25
 * @LastEditTime: 2021-04-23 22:32:01
 * @LastEditors: Jie Lin
 * @Description:Word Ladder
 * @FilePath: \myleetcode\BFS\Solution_127.hpp
 *
 */
#ifndef SOLUTION_127
#define SOLUTION_127
/**
 * @brief
 * 单词转换序列，给出一个开始词，如果能通过查询一个词典，找到一个和开始词中字母只相差一个的单词，重复若干次，得到给定的结束词
 * 返回这个变换过程用到的单词个数，如果不能通过开始词变换得到结束词，返回0
 * 除开始词外，所有可用的单词必须在词典中，且词典中每个单词的长度和开始词相同
 * 开始词不等于结束词
 * @note
 * @retval None
 */
#include <algorithm>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
class Solution_127 {
 public:
  int ladderLength(std::string beginWord, std::string endWord,
                   std::vector<std::string>& wordList) {
    std::unordered_set<std::string> wordSet(wordList.begin(), wordList.end());
    if (!wordSet.count(endWord)) return 0;
    std::unordered_map<std::string, int> pathCnt{{{beginWord, 1}}};
    std::queue<std::string> q{{beginWord}};
    while (!q.empty()) {
      std::string word = q.front();
      q.pop();
      //对单词中逐个字母进行替换
      for (size_t i = 0; i < word.size(); i++) {
        std::string newWord = word;
        //对每个位置上的字母替换
        for (char ch = 'a'; ch <= 'z'; ch++) {
          newWord[i] = ch;
          //如果字典中存在这个替换单词，并且替换单词就是endWord
          if (wordSet.count(newWord) && newWord == endWord) {
            return pathCnt[word] + 1;
          }
          //如果字典中存在这个替换单词，并且查找路径pathCnt中不存在这个新单词
          if (wordSet.count(newWord) && !pathCnt.count(newWord)) {
            q.push(newWord);
            pathCnt[newWord] = pathCnt[word] + 1;
          }
        }
      }
    }
    return 0;
  }
};
#endif