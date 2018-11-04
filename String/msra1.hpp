/*
给定一个字符串，里面包含了用.分割的整数
但是这个字符串被混入了一些字母、符号
找出这个字符串中所有合法的ipv4地址，
即被打乱后的字符串中存在的所有合法ipv4地址(0.0.0.0~255.255.255.255)
数字中间存在非.字符的地方就中断匹配
例子
-112.34..a45.67.4abcd5af.3-2.394.-2003.3.4.340.4.6.45.45.66.445.
返回结果
4.6.45.45
6.45.45.66
 */
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
class msra
{
  public:
    std::vector<std::vector<int>> findip(std::string IP)
    {
        std::vector<std::vector<int>> res;
        std::unordered_map<int, int> temp;
        int count = 0;
        std::string s;
        for (size_t i = 0; i < IP.length(); i++)
        {
            if (IP[i] >= '0' && IP[i] <= '9')
            {
                s.push_back(IP[i]);
            }
            else if (IP[i] == '.')
            {
                if (s.length() > 0)
                {
                    int num = stoi(s);
                    if (num <= 255)
                    {
                        temp[count++] = num;
                    }
                    else
                    {
                        temp[count++] = -1;
                    }
                }
                s.clear();
            }
            else
            {
                temp[count++] = -1;
                s.clear();
            }
        }
        //看一下最后s还有数字没
        if (s.length() > 0)
        {
            int num = stoi(s);
            if (num <= 255)
            {
                temp[count++] = num;
            }
            else
            {
                temp[count++] = -1;
            }
        }
        s.clear();
        //拼接合法ip
        for (size_t i = 0; i < count; i++)
        {
            if (i + 4 >= count)
            {
                break;
            }
            int a = temp[i];
            int b = temp[i + 1];
            int c = temp[i + 2];
            int d = temp[i + 3];
            if (a == -1 || b == -1 || c == -1 || d == -1)
            {
                continue;
            }
            else
            {
                res.push_back({a, b, c, d});
            }
        }

        return res;
    }
    void test()
    {
        std::string ip{"-112.34..a45.67.4abcd5af.3-2.394.-2003.3.4.340.4.6.45.45.66.445adsl34]['/"};
        auto m = findip(ip);
        for (auto i : m)
        {
            for (auto j : i)
            {
                std::cout << j << " ";
            }
            std::cout << std::endl;
        }
    }
};
