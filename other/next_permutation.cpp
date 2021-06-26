/*
 * next_permutation.cpp
 *
 *  Created on: Aug 3, 2018
 *      Author: liuyanan
 */


/*
	题目：
		实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
		如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
		必须原地修改，只允许使用额外常数空间。
		以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
			1,2,3 → 1,3,2
			3,2,1 → 1,2,3
			1,1,5 → 1,5,1

	思路:


 */

#include <iostream>
#include <vector>

using namespace std;

void next_permutation(string& sequence)
{
	if(sequence.size() < 2) {
		return ;
	}

	//
	//  输入的数组
	//		1      2      3
	//			   ^      ^
	//			 left   right
	//

	int right = sequence.size() - 1;
	int left = right - 1;

	while(left >= 0) {
		if(sequence[left] < sequence[right]) {
			swap(sequence[left], sequence[right]);
			return;
		}
		--left;
		--right;
	}

	left = 0;
	right = sequence.size() - 1;
	while(left < right) {
		swap(sequence[left], sequence[right]);
		++left;
		--right;
	}
}

int main(int argc, char **argv)
{
	string sequece("123");
	cout << sequece << endl;
	for(int i=0; i<10; ++i) {
		next_permutation(sequece);
		cout << sequece << endl;
	}

	return 0;
}
