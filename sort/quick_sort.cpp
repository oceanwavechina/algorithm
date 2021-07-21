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
#include <random>
#include <tuple>

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
	int lower = l;

	/*
	  i: 是遍历整个parition
	  j: 指向最右端那个比 哨兵值 小的元素，
	  所以在遍历i遍历完后，就应该把j指向的元素与哨兵互换。从而实现哨兵左边小于等于哨兵，哨兵右边大于哨兵
	 */
	for(int higher=l+1; higher<=r; ++higher) {
		if(A[higher] <= x) {
			++lower;  						// 这里的 j 只有当需要往 “小值” 队列里追加的时候才会 +1 , 而且是先加 1
			std::swap(A[lower], A[higher]);
		}
	}

	std::swap(A[l], A[lower]);				// 把 pivot 放在它应该的位置上，这就是partition的第二个用途

	return lower;
}


void quick_sort(std::vector<int>& A, int l, int r) {

	if (l >=r )
		return ;

	int m = partition(A, l, r);

	quick_sort(A, l, m-1);
	quick_sort(A, m+1, r);
}


void randomized_quick_sort(std::vector<int>& A, int l, int r) {
	if (l >= r)
		return ;

	std::random_device rd;
	int k = l + rd() % (r-l); // 这个是［l,r］之间的某个值，而不是[0,A.size()) 间的某个值
	std::cout  << "random position:" << k << std::endl;
	std::swap(A[l], A[k]);

	int m = partition(A, l, r);

	randomized_quick_sort(A, l, m-1);
	randomized_quick_sort(A, m+1, r);
}

void quick_sort_iteration(std::vector<int>& A, int l, int r) {

	while(l < r) {
		int m = partition(A, l, r);

		if((m-l) < (r-m)) {
			quick_sort_iteration(A, l, m-1);
			l = m + 1;
		} else {
			quick_sort_iteration(A, m+1, r);
			r = m - 1;
		}
	}

}



int main() {

	std::vector<int> A= {6, 4, 8, 2, 9, 3, 9, 4, 7, 6, 1};
//	std::vector<int> A= {6, 6, 6, 6, 6, 6, 6};

	std::cout << "original data:\t" << display(A) << std::endl;

//	quick_sort(A, 0, A.size()-1);
//	randomized_quick_sort(A, 0, A.size()-1);
	quick_sort_iteration(A, 0, A.size()-1);

	std::cout << "sorted data:\t" << display(A) << std::endl;

	return 0;
}


