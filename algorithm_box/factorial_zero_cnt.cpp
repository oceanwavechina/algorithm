/*
 * factorial_zero_cnt.cpp
 *
 *  Created on: Mar 14, 2018
 *      Author: liuyanan
 */

/*
 	 计算 100 的阶乘后边有几个零
 	 思路：
 	 	 5的倍数 和 2的倍数 就可以产生 0， {0-100}中2的倍数比5的倍数要多的多，因为每隔一个就有一个偶数，而要没间隔4个数才能有一个5的倍数。
 	 	 所以先要找到有多少个5的倍数，每5个数就有一个，所以100里边有100/5个 5的倍数，
 	 	 而25，50，75，100，125...., 这些包含两个5 ，所以每遇到一个这样的就要在额外加一个
 	 	 即
 	 	 	 5的倍数： 100/5 	 	= 20
 	 	 	 25的倍数： 100/25 	= 4
 	 	 	 总共有 24个 0
 */

#include<iostream>

using namespace std;


unsigned factorial_zero_cnt(int n)
{
	int cnt = 0;

	for(int i=5; n/i != 0; i*=5) {
		cnt += n/i;
	}

	return cnt;
}


int main(int argc, char **argv) {

	int number = 200;

	cout << "zero cnt of " << number << ": " << factorial_zero_cnt(number) << endl;

	return 0;
}
