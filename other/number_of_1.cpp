/*
 * number_of_1.cpp
 *
 *  Created on: Jul 12, 2021
 *      Author: liuyanan
 */

#include <iostream>

using namespace std;


/*
  Question:
  	  实现一个函数，输入一个整数， 输出该数二进制中 1 的个数
  	  比如，把 9 表示成二进制是1001， 有两个 1 ， 所以如果输入是9， 则该函数输出是2
 */


//
//	注意这个函数的问题在哪里
//		因为我们修改的是传入参数，而参数是可以为负数的
//		注意计算机表示负数是最高位是1， 所以当是负数时，到最后会陷入死循环
//
int number_of_1_wrong ( int n)
{
	int counter = 0;

	while (n) {

		if(n & 1) {
			++ counter;
		}

		n = n >> 1;
		cout << "cur n: " << n << endl;
//		if(n == -1) {
//			return 0;
//		}
	}

	return counter;
}


//
//	常规解法
//		我们不修改传入的参数，而是修改我们自定义的数，可以保证是正数，不会发生溢出
//		但是这种方法会循环字节长度
//
int number_of_1 (int n)
{
	int counter = 0;
	unsigned int flag = 1;

	while(flag) {

		if(n & flag) {
			++counter;
		}

		flag = flag << 1;
		cout << "cur flag:" << flag << endl;
	}

	return counter;
}


//
//	注意这里的技巧，n 每次 减一， 当减1后，低位的那几个就没用了，所以才有 (n-1) & n
//
int number_of_1_efficient(int n)
{
	int counter = 0;

	while(n) {
		++counter;

		n = (n-1) & n;
	}

	return counter;
}


int main(int argc, char **argv)
{
	int n = 0x80000000;
	// int count = number_of_1_wrong(n);
	// int count = number_of_1(n);
	int count = number_of_1_efficient(n);
	cout << n << " contain " << count << " 1" << endl;

	return 0;
}
