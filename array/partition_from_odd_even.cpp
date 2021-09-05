/*
 * partition_from_odd_even.cpp
 *
 *  Created on: Sep 5, 2021
 *      Author: liuyanan
 */

#include <iostream>
#include <vector>

using namespace std;

/*
 	问题：
 		输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
 			使得所有的奇数位位于数组的前半部分， 所有偶数位于数组的后半部分。

 	玩法：
 		双指针
 */

bool is_odd(long num)
{
	return num % 2 == 1;
}

bool is_even(long num)
{
	return num % 2 == 0;
}


void reorder(vector<long>& data)
{
	assert(!data.empty());

	int left = 0;
	int right = data.size() - 1;

	while(left < right) {

		if(is_odd(data[left])) {
			++left;
		}

		if(is_even(data[right])) {
			-- right;
		}

		if(left < right) {
			swap(data[left], data[right]);
		}
	}
}

void display(const vector<long>& data, const string& msg)
{
	cout << msg << ": ";

	for(auto i: data) {
		cout << i << ", ";
	}

	cout << endl;
}

int main(int argc, char **argv) {

	vector<long> data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	display(data, "origin data");

	reorder(data);

	display(data, "after reorder");

	return 0;
}
