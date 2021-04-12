/*
 * @Author: liuyanan 
 * @Date: 2019-01-09 15:55:34 
 * @Last Modified by: liuyanan
 * @Last Modified time: 2019-01-09 17:06:21
 */


/*
    这个是根据 sum=0 题想到的更一般的情况
    Given an array, print all subarrays in the array which has sum X.

    Examples:
        Input:  
            idx = [0, 1,  2,  3, 4,  5, 6]
            arr = [6, 3, -1, -3, 5, -2, 2]
        Output:  
            Subarray found from Index 2 to 4
            Subarray found from Index 2 to 6
            
    思路：
        是一个动态规划， 有个技巧就是，判断subarray和为X的方式
        因为满足条件的 suarray 可能是从中间开始的，所以问题就是我们如何记录中间开始的subarray
        方法就是计算差， 比如sum[0-2] = 8 , 而且 sum[0-4] = 8, 那这两个子数组公共的部分的和就是0
            注意这个公共的部分是半开半闭区间，不包括前一个数组的最后一个元素
        我们计算所有从start开始的和，然后找到和相等的子数组，找到公共的部分
*/

#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>

using namespace std;

typedef vector< pair<uint32_t, uint32_t> > RangeVec;


RangeVec find_all_subarray_with_x_sum(vector<int32_t> nums, int32_t s) 
{
    RangeVec all_pos;

    // 存放所有从index=0 开始的子数组的和
    unordered_map<int32_t, vector<uint32_t>> sum_with_endpos_map;

    // 累加的和
    int sum = 0;
    
    for(int i=0; i<nums.size(); ++i) {
        sum += nums[i];

        // 找到了一个满足条件的，直接放入结果中
        if(sum == s) {
            all_pos.push_back({0, i});
        }

        // 这里如果s=0，也就是和等于0的情况
        auto pre_same_sums = sum_with_endpos_map.find(sum-s);
        if(pre_same_sums != sum_with_endpos_map.end()) {
            for(auto pre_pos : pre_same_sums->second) {
                all_pos.push_back({pre_pos+1, i});
            }
        }

        sum_with_endpos_map[sum].push_back(i);
    }

    return all_pos;
}

void display_pos(RangeVec poses)
{
    cout << "Range:\n\t";
    for( auto pos : poses ) {
        cout << "(" << pos.first << ", " << pos.second << ")\t";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    vector<int32_t> nums = {6, 3, -1, -3, 5, -2, 2};
    cout << "Array:\n\tidx: ";
    for(auto idx=0; idx<nums.size(); ++idx) {
        cout << idx << "\t";
    }
    cout << "\n\tarr: ";
    for(auto num : nums) {
        cout << num << "\t";
    }
    cout << endl;

    RangeVec all_pos = find_all_subarray_with_x_sum(nums, 2);
    display_pos(all_pos);
    
    return 0;
}