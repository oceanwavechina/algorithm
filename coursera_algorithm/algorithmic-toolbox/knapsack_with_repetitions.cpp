/*
 * knapsack_with_repetitions.cpp
 *
 *  Created on: Sep 18, 2016
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

/*
 * 终于调试对了，变量命名太相似真是害死人啊。。。
 *
 */
int knapsack_with_repetitions(int W, std::vector<int> weights, std::vector<int> values) {
	std::cout << std::endl;

	std::vector<int> target_value(W+1); //命名成value，就和values容易混淆
	int n = weights.size();

	for(int w=1; w<=W; ++w) {
		target_value[w] = 0;

		// 下面这个for循环就是寻找最优解
		for(int i=1; i<=n; ++i) {

			if(weights[i] <= w) {
				// 这也是一个类似递归的步骤
				int val = target_value[w-weights[i]] + values[i];
				std::cout << "val=" << val << ", value[w-weights[i]]=" << target_value[w-weights[i]] << std::endl;
				if(val > target_value[w]){
					target_value[w] = val;
					std::cout << "values["<< w <<"]=" << target_value[w] << std::endl;
				}
			}
		}
		std::cout << "-------------  values["<< w <<"]=" << target_value[w] << std::endl;
	}

	return target_value[W];
}


int main() {

	std::vector<int> weights = {0, 6, 3, 4, 2};
	std::vector<int> values  = {0, 30, 14, 16, 9};

	std::cout << "knapsack with repetitions: " << knapsack_with_repetitions(9, weights, values) << std::endl;

	return 0;
}

