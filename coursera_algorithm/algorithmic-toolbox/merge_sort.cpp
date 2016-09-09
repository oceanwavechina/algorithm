/*
 * merge_sort.cpp
 *
 *  Created on: Sep 9, 2016
 *      Author: liuyanan
 */



#include <iostream>
#include <sstream>
#include <vector>
#include <cstdint>
#include <cmath>


template <typename T>
std::string display(T val) {
	std::stringstream ss;
	for (auto v : val) {
		ss << v << ' ';
	}

	return ss.str();
}


std::vector<int> merge(std::vector<int> B, std::vector<int> C) {

	std::vector<int> D;

	while(!B.empty() && !C.empty()) {
		int b = B.front();
		int c = C.front();

		if(b<=c) {
			D.push_back(b);
			B.erase(B.begin());
		} else {
			D.push_back(c);
			C.erase(C.begin());
		}
	}

	for(auto i : B)
		D.push_back(i);

	for(auto i : C)
		D.push_back(i);

	return D;
}


std::vector<int> merge_sort(std::vector<int> A) {

	int n = A.size();

	if(n==1)
		return A;

	int m = std::floor(n/2);

	std::vector<int> B = merge_sort(std::vector<int>(A.begin(), A.begin()+m));
	std::vector<int> C = merge_sort(std::vector<int>(A.begin()+m, A.end() ));

	std::vector<int> A1 = merge(B, C);

	return A1;
}



int main() {

	std::vector<int> data = {8, 4, 2, 5, 2};

	std::cout << "original data: " << display(data) << std::endl;

	std::cout << "sorted data: " << display(merge_sort(data)) << std::endl;

	return 0;
}


