/*
 * max_sum_of_continuous_subarray.cpp
 *
 *  Created on: Sep 6, 2021
 *      Author: liuyanan
 */

#include <iostream>
#include <vector>

using namespace std;


/*
 问题：
 	 输入一个整形数组， 数组里边有正数也有负数。数组中一个或连续多个元素组成一个子数组。
 	 求所有子数组的和的最大值。要求时间复杂度为 O(n)
 */

int find_greatest_sum(vector<int> data)
{
	int max_ret = INT_MIN;

	vector<int> max_vals(data.size(), 0);

	int cur_sum = 0;
	for (int i=0; i<data.size(); ++i) {

		// 当 cur_sum <=0 的时候我们就要开启一个新的子数组了
		if(cur_sum <= 0) {
			max_vals[i] = data[i];
		} else {
			max_vals[i] = cur_sum + data[i];
		}

		cur_sum = max_vals[i];

		if(cur_sum > max_ret) {
			max_ret = cur_sum;
		}
	}
	cout << endl;

	return max_ret;
}



int main(int argc, char **argv) {

	vector<int> data = {1, -2, 3, 10, -4, 7, 2, -5};

	cout << "array: ";
	for(auto i: data)
		cout << i << "\t";
	cout << endl;

	int max_sum = find_greatest_sum(data);

	cout << "max sum of sub array: " << max_sum << endl;

	return 0;
}


/*
 玩法是这样的：
    这个题目跟 max_sum_of_arbitrary_subarray 的区别是：要求数组是连续的

    应用动态规划算法，记录从开始到当前位置的所有连续数组的最大值，
    注意如果 f(i-1) 的值小于等于0， 那 f(i) = i,
        因为我们不可能把之前小于0的也算进来
 */
