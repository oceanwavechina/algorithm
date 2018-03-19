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
 * 这里我们要讨论的是 fractional_knapsack,
 * 		这个即，物品是可以分割的，也就是说我可以取0.12，1.42， 这样的小数，而不必是整个物品都拿来
 *
 * input:
 * 		weights: 	w1, ..., wn of n items;
 * 		values:  	v1, ..., vn of n items;
 * 		capacity:  	W.
 * output:
 * 		the MAXINUM-TOTAL-VALUE of fractions of items that fit into a bag of capacity W.
 */


/*
 knapsack
 	 1. fraction_knapsack: 物品个数允许是小数，比如可以取 1.3 个
 	 	 用贪婪算法解决，有点需要注意的是，在处理前，我们要对物品根据单位价值排序

 	 2. discrete_knapsack:物品数量必须是整数，即不允许分割
 	 	 这类问题要用动态规划算法处理
 	 	 2.1 with_repeat：可以重复取用
 	 	 2.2 without_repeat:物品不允许重复
*/



#include <iostream>
#include <sstream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <map>

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

void sort_by_valueperweight(std::vector<int>& goods_weight, std::vector<int>& goods_value)
{
	std::map<int/*vpw*/, std::pair<int/*weight*/, int/*value*/>, std::greater<int>> data;

	for(int i=0; i<goods_weight.size(); ++i) {
		int vpw = goods_value[i] / goods_weight[i];
		data[vpw] = std::pair<int,int>(goods_weight[i], goods_value[i]);
	}

	goods_weight.clear();
	goods_value.clear();
	for(auto it = data.begin(); it != data.end(); ++it) {
		goods_weight.push_back(it->second.first);
		goods_value.push_back(it->second.second);
	}
}

int main() {
	int bag_weight = 7;

	// NOTE: 注意我们的输入，都是按单位价值递增排序的
//	std::vector<int> goods_weight = {2, 3, 4};
//	std::vector<int> goods_value= {14, 18, 20};

	std::vector<int> goods_weight = {4, 2, 3};
	std::vector<int> goods_value= {20, 14, 18};

	std::cout << "before sort:" << std::endl;
	for(int i=0; i<goods_weight.size(); ++i) {
		std::cout << goods_weight[i] << "\t"	<< goods_value[i] << std::endl;
	}

	sort_by_valueperweight(goods_weight, goods_value);

	std::cout << "after sort:" << std::endl;
	for(int i=0; i<goods_weight.size(); ++i) {
		std::cout << goods_weight[i] << "\t"	<< goods_value[i] << std::endl;
	}

	// 一定要指定vector的大小
	std::vector<int> A(goods_weight.size());
	int V = 0;

	if (0 == knapsack(bag_weight, goods_weight, goods_value, A, V)) {
		std::cout << "goods in bag:" << display(A) << ", with value:" << V << std::endl;
	}

	return 0;
}

