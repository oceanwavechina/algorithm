/*
 * top_k_numbers.cpp
 *
 *  Created on: Jul 6, 2021
 *      Author: liuyanan
 */


#include <iostream>
#include <vector>
#include <string>

/*
  题目： 输入 n 个整数， 找出其中最小的 k 个数。
  比如， 输入 4 5 1 6 2 3 7 8， 最小的四个数字是 1 2 3 4

  （当然题目还可以换成是 找到其中最大的 k 个数， 思想都是一样的）

	两种方案：
		1. 用 quick-sort 中 partition 的思想， 可以修改当前数组
		2. 用辅助的排序结构，比如堆，红黑树等
 */

void display(std::vector<int>& array, const std::string& msg)
{
	std::cout << msg << " ";
	for(auto item : array) {
		std::cout << item << " ";
	}

	std::cout << "\n" << std::endl;
}


int partition(std::vector<int>& array, int start, int end)
{
	// 这里的 start / end 都是闭区间

	int pivot_pos = start;
	int pivot_val = array[start];
	end += 1;

	while(1) {

		do {
			++start;
		} while(array[start] < pivot_val);

		do {
			--end;
		} while(array[end] > pivot_val);

		if(start >= end) {
			break;
		}

		std::swap(array[start], array[end]);
	}

	// 为什么 pivot 要跟 end 交换，可以看上边循环的结束的两种情况
	// 	1. 当 start == end 时，跟谁 start/end 中的任意一个交换都行
	//  2. 当 start < end 时，end在小的这边了，也就是 array[end] <= pivot_val, 所以交换之后仍满足 partition 的要求
	//  假设跟 start 交换， 如果跳出循环时，array[start] >= pivot_val, 那交换后就违反了 partition 的要求
	std::swap(array[pivot_pos], array[end]);

	display(array, "after partition");

	return start;
}


std::vector<int> TopKNumbers_UsingPartition(std::vector<int>& array, int k)
{
	std::vector<int> ret;

	if(array.empty() || k <= 0 || k > array.size()) {
		return ret;
	}

	int pivot = partition(array, 0, array.size()-1);

	while(pivot != k-1) {

		if(pivot > k-1) {
			pivot = partition(array, 0, pivot-1);
		} else {
			pivot = partition(array, pivot+1, array.size()-1);
		}
	}

	for (int i=0; i<= pivot; ++i) {
		ret.push_back(array[i]);
	}

	return ret;
}


int main(int argc, char **argv)
{
	std::vector<int> array {4, 5, 1, 6, 2, 3, 7, 8};

	display(array, "origin array:");

	std::vector<int> topk = TopKNumbers_UsingPartition(array, 4);

	display(topk, "topk:");

	return 0;
}
