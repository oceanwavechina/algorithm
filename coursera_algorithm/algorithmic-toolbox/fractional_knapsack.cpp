/*
 * fractional_knapsack.cpp
 *
 *  Created on: Sep 5, 2016
 *      Author: liuyanan
 */



/*
 * greedy algorithm 还是用排好序的数据处理方便
 *
 * knapsack 分为两种：fractional_knapsack 和 discrete_knapsack
 * 这里我们要讨论的是 fractional_knapsack
 *
 * input:
 * 		weights w1, ..., wn and values v1, ..., vn of n items; capacity W.
 * output:
 * 		the maximum total value of fractions of items that fit into a bag of capacity W.
 */


#include <iostream>
#include <sstream>
#include <vector>
#include <tuple>
#include <algorithm>

template <typename T>
std::string display(T val) {
	std::stringstream ss;
	for (auto v : val) {
		ss << v << ' ';
	}

	return ss.str();
}


int knapsack(int W, std::vector<int> w, std::vector<int> v, std::vector<int>& A, int& V) {
	V = 0;

	if (w.size() != v.size())
		return -1;
	int n = w.size();

	for (int i=0; i<n; ++i) {
		if(W == 0)
			return 0;

		int a = std::min(w[i], W); // w[i] 是该件物品的总重量，这一行看似不起眼，实际上还是挺巧妙的

		V += a * (v[i] / w[i]);
		std::cout << "total value = " << V << ", value of curent goods = " << a * (v[i] / w[i]) << ", count of current goods = " << a << std::endl;

		w[i] -= a;
		A[i] += a;
		W -= a;

		std::cout << "end one iteration" << std::endl;
	}

	return 0;
}


int main() {
	int bag_weight = 7;
	std::vector<int> goods_weight = {2, 3, 4};
	std::vector<int> goods_value= {14, 18, 20};

	// 一定要指定vector的大小
	std::vector<int> A(goods_weight.size());
	int V = 0;

	if (0 == knapsack(bag_weight, goods_weight, goods_value, A, V)) {
		std::cout << "goods in bag:" << display(A) << ", with value:" << V << std::endl;
	}

	return 0;
}

