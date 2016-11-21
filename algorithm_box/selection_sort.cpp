/*
 * simple_selection_sort.cpp
 *
 *  Created on: Nov 20, 2016
 *      Author: liuyanan
 */


#include <iostream>
#include <sstream>
#include <vector>
#include <cstdint>

using namespace std;


template <typename T>
std::string display(T val) {
	std::stringstream ss;
	for (auto v : val) {
		ss << v << ' ';
	}

	return ss.str();
}

void simple_selection_sort(vector<int> &A)
{
	for (int i=0; i<A.size(); ++i) {

		// 选择最小的元素
		int k = i;
		for(int j=i+1; j<A.size(); ++j) {
			if (A[j] < A[k]) {
				k = j;
			}
		}

		// 将最小的元素和当前元素交换
		if (k != i) {
			int tmp = A[i];
			A[i] = A[k];
			A[k] = tmp;
		}

	}
}

/*
void bi_selection_sort(vector<int> &A)
{
	int i, j, min, max, tmp;

	for (i=1; i< A.size()/2; ++i) {
		min = i; max = i;
		for(j=i+1; j<=A.size()-i; ++j) {
			if(A[j] > A[max]) {
				max = j;
				continue;
			}
			if (A[j] < A[min]) {
				min = j;
			}
		}

		tmp = A[i-1]; A[i-1] = A[min]; A[min] = tmp;
		tmp = A[A.size()-i]; A[A.size()-i] = A[max]; A[max] = tmp;
	}
}
*/

int main()
{
	// vector<int>  A = {3, 1, 5, 7, 2, 4, 9, 6};
	vector<int>  A = {1, 2, 3, 4, 5, 6};

	cout << "original data:" << display(A) << endl;
	simple_selection_sort(A);
	cout << "sorted data (simple_selection_sort):" << display(A) << endl;

	cout << endl;
//
//	// vector<int>  B = {3, 1, 5, 7, 2, 4, 9, 6};
//	vector<int>  B = A;
//
//	cout << "original data:" << display(B) << endl;
//	bi_selection_sort(B);
//	cout << "sorted data (bi_selection_sort):" << display(B) << endl;

	return 0;
}



