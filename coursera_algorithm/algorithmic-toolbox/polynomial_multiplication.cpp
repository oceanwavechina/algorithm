/*
 * polynomial_multiplication.cpp
 *
 *  Created on: Sep 5, 2016
 *      Author: liuyanan
 */


#include <iostream>
#include <vector>
#include <sstream>

template <typename T>
std::string display(T val) {
	std::stringstream ss;
	for (auto v : val) {
		ss << v << ' ';
	}

	return ss.str();
}


std::vector<int> naive_mult_poly(std::vector<int> A, std::vector<int> B, int n) {

	std::vector<int> product(2*n - 1);

	// i, j的上限要搞清楚
	for (int i=0; i<n; ++i) {
		for(int j=0; j<n; ++j)
			product[i+j] = product[i+j] + A[i]*B[j];
	}

	return product;
}


int main() {

	// (15, 13, 33, 9, 10)
	std::vector<int> A = {3, 2, 5};
	std::vector<int> B = {5, 1, 2};

	std::cout << "result=" << display(naive_mult_poly(A, B, 3)) << std::endl;

	return 0;
}
