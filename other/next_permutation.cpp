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
	//	思路：
	//		详见 pic/next-permutation.png
	//

	cout << "current number: " << sequence << endl;

	// 1 从右到左，找到第一个非增的元素 partition_num
	int partition_num_pos = sequence.size() - 1;
	while(partition_num_pos >= 0) {
		if(sequence[partition_num_pos] < sequence[partition_num_pos + 1]) {
			break;
		}
		--partition_num_pos;
	}
	cout << "partiton number: " << sequence[partition_num_pos] << ", pos: " << partition_num_pos << endl;

	if(partition_num_pos >= 0) {

		// 2. 从左到右，找到第一个比 partition_num 大的元素 change_num
		int change_num_pos = sequence.size() - 1;
		while(change_num_pos>= 0) {
			if(sequence[change_num_pos] > sequence[partition_num_pos]) {
				break;
			}
			--change_num_pos;
		}
		cout << "change number: " << sequence[change_num_pos] << ", pos: " << change_num_pos << endl;

		// 3. 交换 partition_num 和 change_num
		swap(sequence[change_num_pos], sequence[partition_num_pos]);
	}

	// 4. 翻转 partition_num 右边的所有元素
	int start = ++partition_num_pos;
	int end = sequence.size() - 1;
	while(start < end) {
		swap(sequence[start], sequence[end]);
		++start;
		--end;
	}
	cout << "next permutation: " << sequence << "\n\n" << endl;
}

int main(int argc, char **argv)
{
	string sequece("123");
	for(int i=0; i<10; ++i) {
		next_permutation(sequece);
	}

	return 0;
}
