/*
 * maximum_swap.cpp
 *
 *  Created on: Jul 27, 2018
 *      Author: liuyanan
 */

#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;


/*
	给定一个非负整数，你至多可以交换一次数字中的任意两位。返回你能得到的最大值。

	示例 1 :
		输入: 2736
		输出: 7236
		解释: 交换数字2和数字7。

	示例 2 :
		输入: 9973
		输出: 9973
		解释: 不需要交换。

	注意:
		给定数字的范围是 [0, 10^8]

	思路:
		找到 除最高有效位外，最大的一位数，如果大于最高有效位就和他交换，否则返回数字本身
		这个题目主要考察的是字符串和数字之间的转换
 */

int64_t maximum_swap(int64_t num)
{
	string str_num = to_string(num);

	int idx = 0;
	char max = str_num[0];

	for(int i=0; i<str_num.size(); ++i) {
		if(str_num[i] > max) {
			idx = i;
			max = str_num[i];
		}
	}

	std::swap(str_num[0], str_num[idx]);

	return atoll(str_num.c_str());
}



int main(int argc, char **argv) {

	vector<int64_t> nums = {2736, 9973};
	for(auto num : nums) {
		cout << "max num of " << num << " is: " << maximum_swap(num) << endl;
	}

	return 0;
}
