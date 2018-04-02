/*
 * single_number.cpp
 *
 *  Created on: Apr 2, 2018
 *      Author: liuyanan
 */

#include <iostream>
#include <vector>

using namespace std;


/*
	Given an array of integers, every element appears twice except for one. Find that single one.

	Note:
	Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?


	这个因为是只有一个数出现了一次，可以考虑用异或，但是现实中用这种方法，太有局限性了，只要需求稍一变动，代码就失效了
	异或: 相异则为真
	同或: 相同则为真
 */


int get_single_num(vector<int> nums)
{
	int ret = 0;

	for(auto num : nums) {
		ret ^= num;
	}

	return ret;
}


int main(int argc, char **argv) {

	vector<int> nums = {2, 2, 3, 3, 44, 44, 10, 10, -1, -1, 0,  -2, -2 , 999};

	int target = get_single_num(nums);

	cout << "target single num: " << target << endl;

	return 0;
}
