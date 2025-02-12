/*
 * @Author: liuyanan 
 * @Date: 2019-01-09 14:38:18 
 * @Last Modified by: liuyanan
 * @Last Modified time: 2019-01-09 15:05:16
 */


/*
    Problem:
        A zero-indexed array A consisting of N integers is given. 
        An equilibrium index of this array is any integer P such that 0 ≤ P < N 
            and the sum of elements of lower indices is equal to the sum of elements of higher indices, 
            i.e. A[0] + A[1] + ... + A[P−1] = A[P+1] + ... + A[N−2] + A[N−1]. 
            Sum of zero elements is assumed to be equal to 0. 
        This can happen if P = 0 or if P = N−1.

    Example:
        consider the following array A consisting of N = 8 elements:
            A = [-1, 3,-4, 5, 1,-6, 2, 1]
        
        P = 1 is an equilibrium index of this array, because:
            A[0] = −1 = A[2] + A[3] + A[4] + A[5] + A[6] + A[7]
        
        P = 3 is an equilibrium index of this array, because:
            A[0] + A[1] + A[2] = −2 = A[4] + A[5] + A[6] + A[7]
        
        P = 7 is also an equilibrium index, because:
            A[0] + A[1] + A[2] + A[3] + A[4] + A[5] + A[6] = 0
        
        and there are no elements with indices greater than 7.
            P = 8 is not an equilibrium index, because it does not fulfill the condition 0 ≤ P < N.
*/





#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

typedef vector<int64_t> Indices;

Indices equilibrium_index(vector<int64_t> array)
{
    Indices idxs;

    int64_t total_sum = 0;
    int64_t left_sum = 0;

    // 先计算总和
    for(auto a : array) {
        total_sum += a;
    }

    // 比较
    for(int i=0; i<array.size(); ++i) {

        if(left_sum == total_sum - left_sum - array[i]) {
            idxs.push_back(i);
        }
        left_sum += array[i];
    }

    return idxs;
}


Indices equilibrium_index_20250212(vector<int64_t> nums) {

    int64_t total_sum = std::accumulate(nums.begin(), nums.end(), 0);

    int64_t left_partial_sum = 0;

    Indices ret;

    for(size_t i = 0; i< nums.size(); ++i) {

        int64_t right_partial_sum = total_sum - left_partial_sum - nums[i];
        if(left_partial_sum == right_partial_sum) {
            ret.push_back(i);
        }

        left_partial_sum += nums[i];
    }

    return ret;
}

int main(int argc, char const *argv[])
{
    vector<int64_t> array = {-1, 3,-4, 5, 1,-6, 2, 1};

    cout << "Target Arrya is:";
    for(auto i : array) {
        cout << " " << i;
    }
    cout << endl;
    
//    Indices idxs = equilibrium_index(array);
    Indices idxs = equilibrium_index_20250212(array);

    cout << "Equilibrium Index is:";
    for(auto i : idxs) {
        cout << " " << i;
    }
    cout << endl;

    return 0;
}








/*
     思路：
        要注意的是这个题，不是要求左右两边是对称的，而是要求以index为分割点(不含)两端的和一样
        遍历两遍，先计算出总和，然后在遍历比较左右两部分的和，时间复杂度O(n)
 */
