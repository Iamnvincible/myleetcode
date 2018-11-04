#ifndef SOLUTION_4
#define SOLUTION_4
/*
**Median of Two Sorted Arrays
*/
#include <iostream>
#include <vector>

class Solution_4
{
public:
  double findMedianSortedArrays(std::vector<int> &nums1,
                                std::vector<int> &nums2)
  {
    int m = nums1.size();
    int n = nums2.size();
    if ((m + n) % 2 == 0)
    {
      double l = findKth(nums1, 0, nums2, 0, (m + n) / 2);
      double r = findKth(nums1, 0, nums2, 0, (m + n) / 2 + 1);
      return (l + r) / 2;
    }
    else
    {
      return findKth(nums1, 0, nums2, 0, (m + n) / 2 + 1);
    }
  }
  void test()
  {
    std::vector<int> nums1{1,2};
    std::vector<int> nums2{1,2};
    double res = findMedianSortedArrays(nums1, nums2);
    std::cout << res << std::endl;
  }

private:
  double findKth(std::vector<int> a, int s, std::vector<int> b, int t, int k)
  {
    // k is the natural index
    int m = a.size() - s;
    int n = b.size() - t;
    if (m == 0)
    {
      return b[k - 1];
    }
    if (n == 0)
    {
      return a[k - 1];
    }
    if (k == 1)
    {
      return a[s] < b[t] ? a[s] : b[t];
    }
    int aidx = m > k / 2 ? k / 2 - 1 : m - 1;
    int bidx = n > k / 2 ? k / 2 - 1 : n - 1;
    if (a[aidx + s] < b[bidx + t])
    {
      // std::vector<int> aslice(a.begin() + aidx + 1, a.end());
      return findKth(a, s + aidx + 1, b, t, k - aidx - 1);
    }
    else
    {
      // std::vector<int> bslice(b.begin() + bidx + 1, b.end());
      return findKth(a, s, b, t + bidx + 1, k - bidx - 1);
    }
  }
};
#endif