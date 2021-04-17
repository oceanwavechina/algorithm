/*
 * recursive_linear_search.cpp
 *
 *  Created on: Sep 5, 2016
 *      Author: liuyanan
 */

#include <iostream>
#include <vector>

/* 没想到一个线性搜索还能整成递归的
 * 这个办法的目的是告诉我们，这个问题可以分解成很多类型相同的小问题，也就是满足 divid 的要求
 *
 * worst-case time:
 * 		T(n) = T(n-1) + c
 */

int recursive_linear_search(std::vector<int> A, int low, int high, int key) {
	// 这里的 high < low 指的是元素，而不是元素的值，因为这里是index，不是value
	if (high < low)
		return -1;
	if(A[low] == key)
		return low;

	return recursive_linear_search(A, low+1, high, key);
}


int main() {
	std::vector<int> A = {2, 3, 9, 5, 1, 6};

	std::cout << "target position is:" << recursive_linear_search(A, 0, A.size()-1, 5) << std::endl;

	return 0;
}
