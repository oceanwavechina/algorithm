/*
 * problility.cpp
 *
 *  Created on: Oct 9, 2016
 *      Author: liuyanan
 */


#include <iostream>
#include <random>
#include <ctime>
#include <cstdlib>


/*
 * Question:
 * 		已知函数 f() 返回 0， 1的概率分别是 0.1 和 0.9
 * 		实现一个函数g(): 通过调用f(), 使得g() 返回0, 1 的概率分别是 0.5 和 0.5
 *
 * Hint:
 * 		找到两个概率相等的情况， (0,0)的概率是0.01;  (0,1)的概率是0.09;  (1,0)的概率是0.09;  (1,1)的概率是0.81
 * 		这样(0,1)  和 (1,0) 的概率是相等的，这就是问题的入口
 *
 * Note:
 * 		虽然，思路是这样的，但实际运行时，很难跑到概率相等的情况
 */



/*
 *  返回 0, 1 的概率分别是 0.1 和 0.9 （大约）
 */
int f() {
	return std::rand() % 10 == 0 ? 0 : 1;
}


int g() {
	int a[2] = {0, 0};

	a[0] = f();
	a[1] = f();

	while(1) {
		if (a[0]==0 && a[1]==1) {
			std::cout  << "ok" << std::endl;
			return 0;
		}
		else if (a[0]==1 && a[1]==0) {
			std::cout  << "ok" << std::endl;
			return 1;
		}
		else{
//			std::cout  << "skip: a[0]=" << a[0] << ", a[1]=" << a[1] << std::endl;
			continue;
		}
	}

}


int main() {

	std::srand(std::time(0));

	int zero_counter = 0;

	for(int i=0; i<10000; ++i) {
		if (f() == 0)
			++zero_counter;
	}

	std::cout << "got " << zero_counter << " times <0> in 10000 call f()" << std::endl;


	for(int i=0; i<10; ++i) {
		if (g() == 0)
			++zero_counter;
	}

	std::cout << "got " << zero_counter << " times <0> in 10 call g()" << std::endl;
}


