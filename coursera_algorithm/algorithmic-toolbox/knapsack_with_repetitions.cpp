/*
 * knapsack_with_repetitions.cpp
 *
 *  Created on: Sep 18, 2016
 *      Author: liuyanan
 */


/*
 * Dynamic Programming Algorithm
 *
 * discrete_knapsack 分为 with_repeat 和 without_repeat 的情况，
 * 			这两种情况都不能用 greedy algorithm 解决， 需要引入动态规划算法
 *
 * input:
 * 		weights w1, ..., wn and values v1, ..., vn of n items; total weight W
 *
 * output:
 * 		the maximum value of items whose weight does not exceed W.
 * 		Each item can be used any number of times;
 *
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

	/* 从 1 到 W  遍历一次，找到每个点的最大值，因为每个点的最大值，是根据之前的点计算得来的（注意，是按整数连续遍历）
	 * 这里的 wi 指的是重量
	 */
	for(int wi=1; wi<=W; ++wi) {
		target_value[wi] = 0;


		/* 下面这个for循环就是寻找最优解, 通过遍历所有物品
		 * 	ATTENTION: 思路就是遍历每个物品，找到可以与之组成最优组合的之前的点
		 */
		for(int j=1; j<=n; ++j) {

			if(weights[j] <= wi) { // 条件1 重量比当前的重量小，或是刚好等于

				// 重点就是这个 wi-weights[j]，就是之前的某个重量X（这个X的value已经是最优的了）
				int val = target_value[wi-weights[j]] + values[j];

				// debug
				{
					std::cout << "val=" << val << ", value[" << wi-weights[j] << "]=" << target_value[wi-weights[j]] << std::endl;
				}

				if(val > target_value[wi]){	// 条件2，价值比当前的价值大
					target_value[wi] = val;
					std::cout << "values["<< wi <<"]=" << target_value[wi] << std::endl;
				}
			}
		}
		std::cout << "-------------  iterator "<< wi <<"-------------" << target_value[wi] << std::endl << std::endl;
	}

	// debug
	{
		std::cout << "goods_weight:\t";
		for(int wi=1; wi<weights.size(); ++wi) {
			std::cout << weights[wi] << "\t";
		}
		std:: cout << std::endl;

		std::cout << "goods_value:\t";
		for(int wi=1; wi<values.size(); ++wi) {
			std::cout << values[wi] << "\t";
		}
		std:: cout << std::endl << std::endl;


		std::cout << "ret_weight:\t";
		for(int wi=1; wi<=W; ++wi) {
			std::cout << wi << "\t";
		}
		std:: cout << std::endl;

		std::cout << "ret_value:\t";
		for(int wi=1; wi<=W; ++wi) {
			std::cout << target_value[wi] << "\t";
		}
		std:: cout << std::endl;
	}

	std:: cout << std::endl;

	return target_value[W];
}


int main() {

	std::vector<int> weights = {0, 6, 3, 4, 2};
	std::vector<int> values  = {0, 30, 14, 16, 9};

	int ret = knapsack_with_repetitions(9, weights, values);
	std::cout << "knapsack with repetitions, result: " << ret << std::endl;

	return 0;
}

