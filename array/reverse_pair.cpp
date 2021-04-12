/*
 * reverse_pair.cpp
 *
 *  Created on: Aug 10, 2018
 *      Author: liuyanan
 */


/*
	在数组中的两个数字如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。给你一个数组，求出这个数组中逆序对的总数。
		概括：如果a[i] > a[j] 且 i < j， a[i] 和 a[j] 构成一个逆序对。

	序列 [7, 5, 6, 4] 中，有 3 个逆序对 (7, 6), (7, 5), (7, 4), (6, 4), (5, 4)，则返回 5 。

 */

#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>

using namespace std;

using DataVec = vector<int>;

string display(DataVec data)
{
	ostringstream oss;

	for(auto i: data) {
		oss << i << ", ";
	}

	return oss.str();
}


DataVec merge(DataVec A, DataVec B)
{
	DataVec C;
	int len_a = A.size();
	int len_b = B.size();

	int i = 0;
	int j = 0;

	while(!A.empty() && !B.empty())
	{
		cout << "A: " << display(A) << endl;
		cout << "B: " << display(B) << endl << endl;
		if(A[0] <= B[0]) {
			C.push_back(A[0]);
			A.erase(A.begin());
		} else {
			C.push_back(B[0]);
			B.erase(B.begin());
		}
	}

	cout << endl;

	for(auto i : A) {
		C.push_back(i);
	}

	for(auto i : B) {
		C.push_back(i);
	}

	return C;
}

DataVec merge_sort(DataVec data)
{
	if(data.size() <= 1)
		return data;

	int mid = (int)floor(double(data.size() / 2.0));

	DataVec A = merge_sort(DataVec(data.begin(), data.begin()+mid));
	DataVec B = merge_sort(DataVec(data.begin()+mid, data.end()));

	return  merge(A, B);
}


int main(int argc, char **argv) {

	// std::vector<int> data = {6,2,7,3,4,9,1,8,5};

	DataVec data = {2, 4, 1, 3, 5};
	std::cout << "original data: " << display(data) << std::endl;
	std::cout << "hint ans: (2, 1), (4, 1), (4, 3)" << std::endl;

	DataVec result = merge_sort(data);
	std::cout << "sorted data: " << display(result) << std::endl;


	return 0;
}
