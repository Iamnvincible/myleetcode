#ifndef SOLUTION_71
#define SOLUTION_71
/*
Given an absolute path for a file (Unix-style), simplify it. Or in other words,
convert it to the canonical path.

In a UNIX-style file system, a period . refers to the current directory.
Furthermore, a double period .. moves the directory up a level. For more
information, see: Absolute path vs relative path in Linux/Unix

Note that the returned canonical path must always begin with a slash /, and
there must be only a single slash / between two directory names. The last
directory name (if it exists) must not end with a trailing /. Also, the
canonical path must be the shortest string representing the absolute path.

给出一个合法的unix绝对路径，对其进行简化
要求：地址以/开始，.表示当前目录，..表示上一级目录，
注意只有一个点两个点表示目录级别，三个点时可以作为合法目录的
连续的/简化成一个/
返回简化后的目录字符串
*/
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
class Solution_71 {
 public:
  std::string simplifyPath(std::string path) {
    std::string res;
    //存储路径名，当作一个栈
    std::vector<std::string> road;
    //存储当前正要处理的路径名
    std::string cur;
    //在路径末尾加上一个/，因为下面判断是依据/，同时可以在循环结束后减少判断
    path.push_back('/');
    for (int i = 0; i < path.size(); i++) {
      if (path[i] == '/') {
        //在遇到/时处理cur中的字符
        //..即向上一级目录，进行出栈操作，注意vector为空时判断
        if (cur == ".." && road.size() > 0) {
          road.pop_back();
        }
        //当cur中非空且是一个普通目录名称时入栈
        else if (!cur.empty() && cur != "." && cur != "..") {
          road.push_back(cur);
        }
        //处理完成后清除cur
        cur.clear();
      } else {
        cur.push_back(path[i]);
      }
    }
    //栈中为空
    if (road.size() == 0) {
      return "/";
    }
    //将栈中元素还原成字符串
    for (int j = 0; j < road.size(); j++) {
      res.push_back('/');
      res.append(road[j]);
    }
    return res;
  }
};
class Solution_71_bak {
 public:
  std::string simplifyPath(std::string path) {
    std::vector<std::string> dirs;  //当作栈
    for (auto i = path.begin(); i != path.end();) {
      ++i;
      //找出第一次出现/的位置
      auto j = std::find(i, path.end(), '/');
      //截取两个//之间的字符串
      auto dir = path.substr(i - path.begin(), j - i);
      //当有连续/时，dir为空
      if (!dir.empty() && dir != ".") {
        if (dir == "..") {
          if (!dirs.empty()) dirs.pop_back();
        } else {
          dirs.push_back(dir);
        }
        i = j;
      }
    }
    std::stringstream out;
    if (dirs.empty()) {
      out << "/";
    } else {
      for (auto dir : dirs) out << '/' << dir;
    }
    return out.str();
  }
};
#endif