/*
 * FibRecurs.cpp
 *
 *  Created on: Aug 31, 2016
 *      Author: liuyanan
 */

#include <iostream>
#include <ctime>

/*
 * 1. 视频上讲的是 n<=1, 说的是数值，实际编码起来，n应该是个数
 */
long long fibcurs(int n) {
	if (n <= 3)
	// if (n <= 1)
		return n;
	else
		return fibcurs(n-1) + fibcurs(n-2);
}

int main() {
	int n;
	std::cin >> n;
	std::time_t start, end;
	start = std::time(nullptr);
	std::cout << "fibcurs for " << n <<":" << fibcurs(n) << ", with time:" << std::time(nullptr)-start << "seconds\n";
}
