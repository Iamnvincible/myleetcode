## Two Pointers 1

数组有序后，左右位置指针从数组前后靠近，利用数组单调特点，排除无效数据，更新目标。

- 167 [Two Sum II - Input array is sorted](https://github.com/Iamnvincible/myleetcode/blob/master/Search/Solution_167.hpp)
- 15 [3Sum](https://github.com/Iamnvincible/myleetcode/blob/master/Array/Solution_15.hpp)
- 2824 [Count Pairs Whose Sum is Less than Target](https://github.com/Iamnvincible/myleetcode/blob/master/Search/Solution_2824.hpp)
- 16 [3Sum Closest](https://github.com/Iamnvincible/myleetcode/blob/master/Array/Solution_16.hpp)
- 18 [4Sum](https://github.com/Iamnvincible/myleetcode/blob/master/Array/Solution_18.hpp)
- 611 [Valid Triangle Number](https://github.com/Iamnvincible/myleetcode/blob/master/Search/Solution_611.hpp)

## Two Pointers 2

数组不可以排序，但两个位置指针也从两边向里靠近。利用题目给出条件，更新目标。

- 11 [Container With Most Water](https://github.com/Iamnvincible/myleetcode/blob/master/Gready/Solution_11.hpp)
- 42 [Trapping Rain Water](https://github.com/Iamnvincible/myleetcode/blob/master/Array/Solution_42.hpp)

## Sliding Window

也需要两个位置指针，但指针都从一边向另一边移动。两个指针之间的范围构成一个窗口，随着两个指针位置变化，窗口在数组上滑动。

左指针一直不超过右指针。右指针控制外循环，向右扩展窗口；左指针用于从左边缩短窗口。

扩展窗口后，需要判断目标条件（最长/最小等）。满足条件后，考虑缩短窗口。

- 209 [Minimum Size Subarray Sum](https://github.com/Iamnvincible/myleetcode/blob/master/Search/Solution_209.hpp)
- 3 [Longest Substring Without Repeating Characters](https://github.com/Iamnvincible/myleetcode/blob/master/Gready/Solution_3.hpp)
- 713 [Subarray Product Less Than K](https://github.com/Iamnvincible/myleetcode/blob/master/Search/Solution_713.hpp)
- 76 [Minimum Window Substring](https://github.com/Iamnvincible/myleetcode/blob/master/Search/Solution_76.hpp)
