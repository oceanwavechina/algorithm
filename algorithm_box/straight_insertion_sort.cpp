/*
 * straight_insertion_sort.cpp
 *
 *  Created on: Nov 20, 2016
 *      Author: liuyanan
 */

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

/*
 * 1. 如果碰见一个和插入元素相等的，那么插入元素把想插入的元素放在相等元素的后面。
 * 		所以，相等元素的前后顺序没有改变，从原无序序列出去的顺序就是排好序后的顺序，
 * 		所以插入排序是稳定的。
 *
 * 2. 时间复杂度：O（n^2）.
 *
 * 3. 打扑克时，就是用的插入排序
 */

template <typename T>
std::string display(T val) {
	std::stringstream ss;
	for (auto v : val) {
		ss << v << ' ';
	}

	return ss.str();
}

void insertion_sort(vector<int> &A)
{
	int x;
	for (int i=1; i<A.size(); ++i) { 	// i 从 1 ，开始，因为第0个元素已是排好序的了
		if (A[i] < A[i-1]) {
			int j = i-1;				// 记录要被移动的上一个元素
			x = A[i];					// 保存当前元素的值

			while(x < A[j]) {
				A[j+1] = A[j];
				--j;
			}

			A[j+1] = x;					// 因为上边的while循环中 --j;
		}
	}
}

int main()
{
	vector<int>  A = {3, 1, 5, 7, 2, 4, 9, 6};

	cout << "original data:" << display(A) << endl;
	insertion_sort(A);
	cout << "sorted data:" << display(A) << endl;

	return 0;
}



