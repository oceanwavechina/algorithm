/*
 * longest-consecutive-sequence.cpp
 *
 *  Created on: Feb 23, 2025
 *      Author: liuyanan
 */

#include <iostream>
#include <vector>
#include <unordered_set>

/*
    给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。

    请你设计并实现时间复杂度为 O(n) 的算法解决此问题。

    示例 1：
        输入：nums = [100,4,200,1,3,2]
        输出：4
        解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。

    示例 2：
        输入：nums = [0,3,7,2,5,8,4,6,0,1]
        输出：9

    示例 3：
        输入：nums = [1,0,1,2]
        输出：3
 */


int longest_consecutive(const std::vector<int>& nums) {

    int max_len = 0;
    std::unordered_set<int> num_set(nums.begin(), nums.end());

    for(int num : num_set) {

        if(num_set.count(num-1)) {
            continue;
        }

        int cur_num = num;
        int cur_len = 1;
        while(num_set.count(++cur_num)) {
            cur_len += 1;
        }

        max_len = std::max(max_len, cur_len);
    }

    return max_len;
}



int main(int argc, char **argv) {

    std::vector<int> nums{100,4,200,1,3,2};

    std::cout << "max len:" << longest_consecutive(nums) << std::endl;

    return 0;
}


/*
 方法思路
    哈希集合存储元素：首先将数组中的所有元素存入哈希集合中，以便在O(1)时间内检查元素是否存在。

    寻找连续序列起点：遍历哈希集合中的每个元素，如果当前元素的前一个元素不在集合中，则说明当前元素可能是一个连续序列的起点。

    计算序列长度：从起点开始，依次检查后续连续元素是否存在，并计算序列长度。记录最长序列的长度。

 这种方法确保每个元素最多被访问两次（一次作为起点检查，一次作为序列的一部分），因此时间复杂度为O(n)。
 */
