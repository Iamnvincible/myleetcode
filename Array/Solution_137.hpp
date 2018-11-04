#ifndef SOLUTION_137
#define SOLUTION_137
/* Given a non-empty array of integers,
every element appears twice except for one.
Find that single one.
数组中除了一个元素出现了一次，其余元素都出现了三次
找出出现了一次的元素。
记录二进制位每个位置1出现的次数
如果是3的倍数，就说明出现了一次的数在那个位是0
不是3的倍数说明在这个位置是1

可以巧妙使用位运算
用2位可以表示3种状态
00--没有出现或出现3次可以清零
01--出现1次
10--出现2次
需要2位，可以用两个int的对应位来表示
对每种情况下输入位和输出位进行列举，列出真值表
得出逻辑表达式
由于需要出现1次的数，那么只需要返回2位数中表示后面一位的int数

还可以用二进制表示三进制
*/
#include <vector>
class Solution_137 {
 public:
  int singleNumber(std::vector<int>& nums) {
    int count[sizeof(int) * 8] = {0};
    int res = 0;
    for (int i = 0; i < nums.size(); i++) {
      int bit = 0;
      while (nums[i] != 0 && bit < sizeof(int) * 8) {
        if ((nums[i] & 1) == 0) {
          nums[i] = nums[i] >> 1;
          bit++;
        } else {
          nums[i] = nums[i] >> 1;
          count[bit++]++;
        }
      }
    }
    for (int i = 0; i < sizeof(int) * 8; i++) {
      if (count[i] % 3 == 0)
        continue;
      else
        res += 1 << i;
    }
    return res;
  }
};
class Solution_137_bak1 {
 public:
  int singleNumber(std::vector<int>& nums) {
    int low = 0, high = 0;
    for (int i = 0; i < nums.size(); i++) {
      int templow = (low ^ nums[i]) & ~high;
      high = (high & ~low & ~nums[i]) | (~high & low & nums[i]);
      low = templow;
    }
    return low;
  }
};
//对上一种优化
class Solution_137_bak2 {
 public:
  int singleNumber(std::vector<int>& nums) {
    int low = 0, high = 0;
    for (int i = 0; i < nums.size(); i++) {
      low = (low ^ nums[i]) & ~high;
      high = (high ^ nums[i]) & ~low;
    }
    return low;
  }
};
class Solution_137_bak3 {
 public:
  int singleNumber(std::vector<int>& nums) {
    int one = 0, two = 0, three = 0;//1出现1次的数位，1出现2次的数位，1出现3次的数位
    for (int i = 0; i < nums.size(); ++i) {
      two |= one & nums[i];//与过仍为1的出现2次
      one ^= nums[i];//异或只记录出现奇数次的1的位置
      three = one & two;//出现1次又出现2次，就是出现3次
      one &= ~three;//出现3次清零
      two &= ~three;//出现3次清零
    }
    return one;
  }
};
#endif