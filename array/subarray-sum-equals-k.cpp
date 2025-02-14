#include <utility>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;


/*
    给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k 的子数组的个数 。
    子数组是数组中元素的连续非空序列。

    示例 1：
        输入：nums = [1,1,1], k = 2
        输出：2

    示例 2：
        输入：nums = [1,2,3], k = 3
        输出：2

    提示：
        1 <= nums.length <= 2 * 104
        -1000 <= nums[i] <= 1000
        -107 <= k <= 107
*/


int64_t subarray_with_given_sum(const vector<int64_t>& array, int k)
{
    if(array.empty()) {
        return 0;
    }

    // {1, 4, 20, 3, 10, 5}, sum = 33
    // Ouptut: Sum found between indexes 2 and 4

    int64_t ret = 0;
    int64_t pre_sum = 0;

    unordered_map<int64_t/*pre_sum*/, int64_t/*cnt*/> mp;
    mp[0] = 1;

    for(int64_t num : array) {
        pre_sum += num;

//        cout << "mp.count(" << pre_sum - k << "):" << mp.count(pre_sum - k) <<  ", pre_sum:" << pre_sum << endl;

        if(mp.count(pre_sum - k)) {
            ret += mp[pre_sum-k];
//            cout << "found pre_sum:" << pre_sum << endl;
        }

        mp[pre_sum] += 1;
//        cout << "push_back, pre_sum:" << pre_sum << ", num=" << num << endl;
    }

    return ret;
}

void display_array(const vector<int64_t>& array) {
    for(auto item : array) {
        cout << item << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    vector<int64_t> array = {1, 2, 3};
    int k = 3;

    cout << "Target Array:" << endl << '\t';
    display_array(array);

    int64_t cnt = subarray_with_given_sum(array, k);
    cout << " cnt: " << cnt << endl;

    return 0;
}






/*

    错误思路：
        以为是连续的，所以我们只有有连个指针指向start和end，像滑动窗口一样遍历一次就可以了
        所以时间复杂度是O(1), 空间复杂度是O(1)

    思路：
        使用前缀和，配合map解决

 */
