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

	int pivot = start;

	while(start < end) {

		while(start < end && array[start] <= array[pivot]) {
			++start;
		}

		while(start < end && array[end] > array[pivot]) {
			--end;
		}

		if(start < end) {
			std::swap(array[start], array[end]);
		}
	}

	std::swap(array[start], array[pivot]);

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
