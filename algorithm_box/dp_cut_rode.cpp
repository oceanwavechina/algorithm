/*
 * @Author: liuyanan 
 * @Date: 2020-04-28 16:43:43 
 * @Last Modified by: liuyanan
 * @Last Modified time: 2020-04-28 19:36:42
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

/*
    Cutting a Rod | DP-13
    Given a rod of length n inches and an array of prices that contains prices of all pieces of size smaller than n. 
    Determine the maximum value obtainable by cutting up the rod and selling the pieces. 
    
    For example, if length of the rod is 8 and the values of different pieces are given as following, 
    then the maximum obtainable value is 22 (by cutting in two pieces of lengths 2 and 6)

    length   | 1   2   3   4   5   6   7   8  
    --------------------------------------------
    price    | 1   5   8   9  10  17  17  20


    And if the prices are as following, 
    then the maximum obtainable value is 24 (by cutting in eight pieces of length 1)

    length   | 1   2   3   4   5   6   7   8  
    --------------------------------------------
    price    | 3   5   8   9  10  17  17  20


    根据dp的思想，把每一步最优的情况都记录下来，遍历所有元素
*/


typedef map<long/*length*/, long/*price*/> TPrice;


long naive_cut_rod(TPrice& price, long total_length)
{
    if (total_length == 0) {
        return 0;
    } else {
        long max_value = 0;
        for(long i = 1; i <= total_length; ++i) {
            max_value = max(max_value, price[i] + naive_cut_rod(price, total_length - i));
        }
        return max_value;
    }    
}

long dp_cut_rod(TPrice& price, long total_length)
{
    vector<long> values_trace(total_length + 1, 0);
    
    // 一段一段的累计，分别计算每一步的最大值
    for(long i = 1; i <= total_length; ++i) {
        long max_value = INT_MIN;
        
        // 计算出当前步的最大值，并保存下来
        for(int j=0; j <= i; ++j) {
            max_value = max(max_value, price[j] + values_trace[i-j]);
        }

        values_trace[i] = max_value;
    }

    return values_trace[total_length];
}


int main(int argc, char const *argv[])
{
    TPrice prices {{1, 1}, {2, 5}, {3, 8}, {4, 9}, {5, 10}, {6, 17}, {7, 17}, {8, 20}};
    
    cout << "max_value(naive): " << naive_cut_rod(prices, 8) << endl;
    
    cout << "max_value(dp): " << dp_cut_rod(prices, 8) << endl;

    return 0;
}
