/*
 * binary_search.cpp
 *
 *  Created on: Sep 5, 2016
 *      Author: liuyanan
 */


#include <iostream>
#include <vector>
#include <cmath>


int binary_search_recursive(std::vector<int> A, int low, int high, int key) {
	// 这个算法需要注意的就是边界，因为第一个判断就是中值，所以之后的两个分支中，不包括这个中间的index
	// 还有就是注意之前说的，我们什么时候用元素，什么时候用元素的值
	if (high < low)
		return low -1;

	int mid = std::floor(low + (high-low)/2);

	if (key == A[mid]) {
		return mid;
	} else if (key < A[mid]) {
		return binary_search_recursive(A, low, mid-1, key);
	} else {
		return binary_search_recursive(A, mid+1, high, key);
	}
}

int binary_search_iterative(std::vector<int> A, int low, int high, int key) {
	/* 递归变成迭代的步骤就是：
		1. 首先找到循环的是什么: 就是递归掉用时的 结束条件的 反条件，比如递归中是 high < low, 迭代中循环的条件就是 low <= high
		2. 找到每次迭代的 step大小 是多少
	*/
	while (low <= high) {
		int mid = std::floor(low + (high-low)/2);

		if (key == A[mid]) {
			return mid;
		} else if (key < A[mid]) {
			high = mid -1;
		} else {
			low = mid + 1;
		}
	}

	return low - 1;
}


int main() {
	std::vector<int> A = {0, 2, 3, 4, 5, 7, 8, 9};

//	std::cout <<  "target index of 5 is: " << binary_search_recursive(A, 0, A.size()-1, 5) << std::endl;
//	std::cout <<  "target index of 6 is: " << binary_search_recursive(A, 0, A.size()-1, 6) << std::endl;
//	std::cout <<  "target index of -1 is: " << binary_search_recursive(A, 0, A.size()-1, -1) << std::endl;

	std::cout <<  "target index of 5 is: " << binary_search_iterative(A, 0, A.size()-1, 5) << std::endl;
	std::cout <<  "target index of 6 is: " << binary_search_iterative(A, 0, A.size()-1, 6) << std::endl;
	std::cout <<  "target index of -1 is: " << binary_search_iterative(A, 0, A.size()-1, -1) << std::endl;

	return 0;
}
