/*
 * find_greatest_sum_of_subarray.cpp
 *
 *  Created on: Mar 8, 2018
 *      Author: liuyanan
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 	 输入整形数组（有正有负）， 在所有可能的子数组的和中，找到最大的那个和
 	 这就是根据k线买股票差不多啊

 	 动态规划：
 	 	 比价每一元素之前的和 与 当前元素，来确定，到目前元素为止的最大值是多少
 	 	 思想就是，到每个元素时，我们都依赖之前的计算结果
 */

int find_greatest_sum(vector<int> data)
{
	int max_ret = INT_MIN;

	int cur_sum = 0;
	cout << "c_sum: ";
	for (int i=0; i<data.size(); ++i) {

		cur_sum = max(data[i], data[i]+cur_sum);
		max_ret = max(cur_sum, max_ret);
		cout << cur_sum << "\t";
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
