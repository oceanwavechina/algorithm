/*
 * @Author: liuyanan 
 * @Date: 2019-01-09 15:55:34 
 * @Last Modified by: liuyanan
 * @Last Modified time: 2019-01-09 17:06:33
 */


/*
    Given an array, print all subarrays in the array which has sum 0.

    Examples:
        Input:  
            arr = [6, 3, -1, -3, 4, -2, 2, 4, 6, -12, -7]
        Output:  
            Subarray found from Index 2 to 4
            Subarray found from Index 2 to 6          
            Subarray found from Index 5 to 6
            Subarray found from Index 6 to 9
            Subarray found from Index 0 to 10
            
    思路：
        是一个动态规划， 有个技巧就是，判断subarray和为0的方式
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


RangeVec find_all_subarray_with_0_sum(vector<int32_t> nums) 
{
    RangeVec all_pos;

    // 存放所有从index=0 开始的子数组的和
    unordered_map<int32_t, vector<uint32_t>> sum_with_endpos_map;

    // 累加的和
    int sum = 0;
    
    for(int i=0; i<nums.size(); ++i) {
        sum += nums[i];

        // 找到了一个满足条件的，直接放入结果中
        if(sum == 0) {
            all_pos.push_back({0, i});
        }

        auto pre_same_sums = sum_with_endpos_map.find(sum);
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
    // 前后两个0也是可以的
    vector<int32_t> nums = {0, 6, 3, -1, -3, 4, -2, 2, 4, 6, -12, -7, 0};
    cout << "Array:\n\tidx: ";
    for(auto idx=0; idx<nums.size(); ++idx) {
        cout << idx << "\t";
    }
    cout << "\n\tarr: ";
    for(auto num : nums) {
        cout << num << "\t";
    }
    cout << endl;

    RangeVec all_pos = find_all_subarray_with_0_sum(nums);
    display_pos(all_pos);
    
    return 0;
}

