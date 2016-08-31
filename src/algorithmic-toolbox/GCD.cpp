/*
 * GCD.cpp
 *
 *  Created on: Aug 31, 2016
 *      Author: liuyanan
 */

#include <iostream>
#include <ctime>


long long NaivaGCD(long long a, long long b) {

	long long ret = 0;
	for (int i = 1; i<= a+b; ++i) {
		if (a % i == 0 && b % i == 0) {
			ret = i;
		}
	}

	return ret;
}


/*
 * 辗转相除法， 又名欧几里德算法
 */
long long EuclidGCD(long long a, long long b) {
	if (0 == b)
		return a;

	return EuclidGCD(b, a%b);
}


int main() {
	int a, b;
	std::cin >> a;
	std::cin >> b;
	std::time_t start, end;

	start = std::time(nullptr);
//	std::cout << "NaivaGCD for " << a << "," << b <<":" << NaivaGCD(a, b) << ", with time:" << std::time(nullptr)-start << "seconds\n";
	std::cout << "EuclidGCD for " << a << "," << b <<":" << EuclidGCD(a, b) << ", with time:" << std::time(nullptr)-start << "seconds\n";
}



