/*
 * @Author: liuyanan 
 * @Date: 2019-01-08 16:29:27 
 * @Last Modified by: liuyanan
 * @Last Modified time: 2019-01-08 16:43:29
 */

/*
    Question：
        Problem : Given an unsorted array of nonnegative integers, 
                    find a continous subarray which adds to a given number.
    TestCase
        Input: arr[] = {1, 4, 20, 3, 10, 5}, sum = 33 
        Ouptut: Sum found between indexes 2 and 4

        Input:  arr[] = {1, 4, 0, 0, 3, 10, 5}, sum = 7
        Ouptut: Sum found between indexes 1 and 4
*/

#include <utility>
#include <vector>
#include <iostream>

using namespace std;

typedef pair<int64_t, int64_t> RangePos;
typedef vector<RangePos> RangePosVec;

RangePosVec subarray_with_given_sum(const vector<int64_t>& array, int sum)
{
    if(array.empty()) {
        return { {-1, -1} };
    }

    uint64_t start = 0;
    uint64_t end =0;
    int64_t cur_range_sum = array[0];
    RangePosVec allpos;

    while(end < array.size() && start < array.size()) {
        if(cur_range_sum == sum) {
            allpos.push_back({start, end});
            end += 1;
            cur_range_sum += array[end];
            cur_range_sum -= array[start];
            start += 1;
        } else if (cur_range_sum < sum) {
            end += 1;
            cur_range_sum += array[end];
        } else {
            cur_range_sum -= array[start];
            start += 1;
        }
    }

    return allpos;
}

void display_array(const vector<int64_t>& array) {
    for(auto item : array) {
        cout << item << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    vector<int64_t> array = {1, 4, 20, 3, 10, 5};
    int sum = 5;

    cout << "Target Array:" << endl << '\t';
    display_array(array);

    cout << "poses of subarray_sum=" << sum << ":" << endl;
    RangePosVec poses = subarray_with_given_sum(array, sum);
    for(auto item : poses) {
        cout << "\t( " << item.first << ", " << item.second << " )" << "\n";
    }

    cout << endl;

    return 0;
}




/*
     思路：
        以为是连续的，所以我们只有有连个指针指向start和end，像滑动窗口一样遍历一次就可以了
        所以时间复杂度是O(1), 空间复杂度是O(1)
 */
