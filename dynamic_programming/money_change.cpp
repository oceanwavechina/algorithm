/*
 * money_change.cpp
 *
 *  Created on: Sep 18, 2016
 *      Author: liuyanan
 */


#include <iostream>
#include <sstream>
#include <vector>
#include <cstdint>
#include <cmath>


/*
 * 动态规划算法：找零钱问题
 *
 */


template <typename T>
std::string display(T val) {
	std::stringstream ss;
	for (auto v : val) {
		ss << v << ' ';
	}

	return ss.str();
}


/*
 * 这个就是遍历所有的可能的组合，然后选出最小的那个
 */
int recursive_change(int money, std::vector<int> coins) {

	if(0 == money) {
		return 0;
	}

	int MinNumCoins = INT32_MAX;

	for(auto coin : coins) {
		if(money >= coin) {
			int NumCoins = recursive_change(money-coin, coins);
			if (NumCoins + 1 < MinNumCoins)
				MinNumCoins =  NumCoins + 1;
		}
	}

	return MinNumCoins;
}


/*
 * 似乎是有点明白了。。。
 * http://www.cs.usfca.edu/~galles/visualization/DPChange.html
 */
int DPChange(int money, std::vector<int> coins) {
	std::vector<int> MinNumCoins(money);

	for(int m=1; m<=money; ++m) {
		MinNumCoins[m] = INT32_MAX;

		for(auto coin : coins) {
			if(m >= coin) {
				int NumCoins = MinNumCoins[m-coin] + 1;
				if(NumCoins < MinNumCoins[m]){
					MinNumCoins[m] = NumCoins;
				}
			}
		}
	}

	return MinNumCoins[money];
}


int main() {

	std::vector<int> data = {6, 5, 1};


	std::cout << "minmum number of conins for change(recursive): " << recursive_change(9, data) << std::endl;
	std::cout << "minmum number of conins for change(dynamic programming): " << DPChange(9, data) << std::endl;

	return 0;
}

