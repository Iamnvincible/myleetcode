#ifndef SOLUTION_136
#define SOLUTION_136
/* Given a non-empty array of integers,
every element appears twice except for one.
Find that single one.
数组中除了一个元素出现了一次，其余元素都出现了两次
找出出现了一次的元素。
异或，相同数字结果为0，
异或有结合律，想象所有出现了两次的元素先异或
结果是0，最后和一次的元素异或得到其本身
出现了偶数次的元素都能清除
*/
#include <vector>
class Solution_136 {
public:
    int singleNumber(std::vector<int>& nums) {
        int res=nums[0];
        for(int i=1;i<nums.size();i++){
            res^=nums[i];
        }
        return res;
    }
};
#endif