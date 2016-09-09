/*
 * quik_sort.cpp
 *
 *  Created on: Sep 9, 2016
 *      Author: liuyanan
 */


#include <iostream>
#include <sstream>
#include <vector>
#include <cstdint>
#include <utility>

template <typename T>
std::string display(T val) {
	std::stringstream ss;
	for (auto v : val) {
		ss << v << ' ';
	}

	return ss.str();
}


/* 1. 每次掉用partition就相当于把 pivot 放对了地方
 * 2. 把数组按照 pivot 左右划分
 * 3. 涉及到的问题有：
 * 		a. Unbalanced Partition： 这样的话，如果还取第一个元素作为pivot，当数组是倒序排的时候，每个元素都要移动一次了
 * 			此时的时间复杂度就是： T(n) = n + T(n-1)， T(n) = n + (n-1) + (n-2) + ... = θ(n^2)
 * 			之所以是 T(n-1), 是因为 left part 只有一个元素，right part 有 n-1 个元素
 * 		b. Balanced Partition: T(n) = 2T(n/2) + n = θ( nlog(n) )
 */
int partition(std::vector<int>& A, int l, int r) {

	int x = A[l];
	int j = l;

	for(int i=l+1; i<=r; ++i) {
		if(A[i] <= x) {
			++j;  						// 这里的 j 只有当需要往 “小值” 队列里追加的时候才会 +1 , 而且是先加 1
			std::swap(A[j], A[i]);
		}
	}

	std::swap(A[l], A[j]);				// 把 pivot 放在它应该的位置上，这就是partition的第二个用途

	return j;
}


void quick_sort(std::vector<int>& A, int l, int r) {

	if (l >=r )
		return;

	int m = partition(A, l, r);

	quick_sort(A, l, m-1);
	quick_sort(A, m+1, r);
}



int main() {

	std::vector<int> A= {6, 4, 8, 2, 9, 3, 9, 4, 7, 6, 1};

	std::cout << "original data:\t" << display(A) << std::endl;

	quick_sort(A, 0, A.size()-1);

	std::cout << "sorted data:\t" << display(A) << std::endl;

	return 0;
}


