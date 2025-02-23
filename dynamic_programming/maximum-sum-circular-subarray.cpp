/*
 * maximum-sum-circular-subarray.cpp
 *
 *  Created on: Feb 23, 2025
 *      Author: liuyanan
 */
#include <iostream>
#include <string>
#include <vector>


using namespace std;


/*
    给定一个长度为 n 的环形整数数组 nums ，返回 nums 的非空 子数组 的最大可能和 。
    环形数组 意味着数组的末端将会与开头相连呈环状。形式上， nums[i] 的下一个元素是 nums[(i + 1) % n] ， nums[i] 的前一个元素是 nums[(i - 1 + n) % n] 。
    子数组 最多只能包含固定缓冲区 nums 中的每个元素一次。形式上，对于子数组 nums[i], nums[i + 1], ..., nums[j] ，不存在 i <= k1, k2 <= j 其中 k1 % n == k2 % n 。

    示例 1：
        输入：nums = [1,-2,3,-2]
        输出：3
        解释：从子数组 [3] 得到最大和 3

    示例 2：
        输入：nums = [5,-3,5]
        输出：10
        解释：从子数组 [5,5] 得到最大和 5 + 5 = 10

    示例 3：
        输入：nums = [3,-2,2,-3]
        输出：3
        解释：从子数组 [3] 和 [3,-2,2] 都可以得到最大和 3
*/


int maxSubarraySumCircular(vector<int>& nums) {

    int global_sum = 0, global_min_sum = 0, global_max_sum = INT16_MIN;
    int cur_min_sum = 0, cur_max_sum = 0;

    for(int num : nums) {
        cur_max_sum = std::max(num, cur_max_sum+num);
        global_max_sum = std::max(cur_max_sum, global_max_sum);

        cur_min_sum = std::min(num, cur_min_sum+num);
        global_min_sum = std::min(cur_min_sum, global_min_sum);

        global_sum += num;
    }

    return global_sum == global_min_sum ?  global_max_sum : std::max(global_max_sum, global_sum-global_min_sum);
}



int main(int argc, char **argv) {

    vector<int> nums{1,-2,3,-2};

    cout << "max sum: " << maxSubarraySumCircular(nums) << endl;

    return 0;
}



/*
    要解决这个问题，我们需要考虑环形数组的特性。环形数组的最大子数组和可能出现在以下两种情况之一：
    最大子数组和出现在数组的中间部分：这种情况下，问题可以转化为普通的数组最大子数组和问题。
    最大子数组和跨越数组的边界：这种情况下，最大子数组和可能包含数组的开头和结尾部分。
    为了处理第二种情况，我们可以考虑计算数组的最小子数组和，然后用数组的总和减去这个最小子数组和，得到跨越边界情况下的最大子数组和。

    实现步骤：
        计算数组的总和 total_sum。

        使用 Kadane 算法计算数组的最大子数组和 max_sum。

        使用 Kadane 算法计算数组的最小子数组和 min_sum。

        如果 min_sum 等于 total_sum，说明所有元素都是负数，直接返回 max_sum。

        否则，返回 max(max_sum, total_sum - min_sum)。
 */
