/*
 * maximum-subarray.cpp
 *
 *  Created on: Feb 23, 2025
 *      Author: liuyanan
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
    给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
    子数组是数组中的一个连续部分。

    示例 1：
        输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
        输出：6
        解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。

    示例 2：
        输入：nums = [1]
        输出：1

    示例 3：
        输入：nums = [5,4,-1,7,8]
        输出：23
 */



int maxSubArray(vector<int>& nums) {
    int global_max = 0;
    int current_max = 0;

    for(size_t i=0; i<nums.size(); ++i) {
        current_max = std::max(nums[i], nums[i]+current_max);
        global_max = std::max(current_max, global_max);
    }

    return global_max;
}


int main(int argc, char **argv) {

    vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};

    int max_sum = maxSubArray(nums);

    cout << "max sum:" << max_sum << endl;

    return 0;
}


/*
    Kadane算法是一种用于在数组中寻找最大子数组和的动态规划算法。它的时间复杂度为O(n)，非常高效。
 */
