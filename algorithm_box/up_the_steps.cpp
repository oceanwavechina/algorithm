/*
 * up_the_steps.cpp
 *
 *  Created on: Feb 17, 2017
 *      Author: liuyanan
 */


#include <iostream>

using namespace std;



/*
 * 楼梯有n阶台阶，上楼可以一步上1阶，也可以一步上2阶, 有多少种不同的走法
 *
 * 问题解析:
 * 		我们现在想象自己已经站在第n级台阶上了，那么我们上一个位置只能在第n-1或者n-2级台阶上。
 * 		比如我们在第3级台阶上，我们上一个位置就在第1或者第2级台阶上。
 * 		也就是说我们到达第3级台阶有两种情况，分别计算着两种情况并相加即可，即到达第1级台阶的方式数加上到达第2级台阶的方式数，结果等于3。
 * 		同理到达第n级台阶的放法数就等于到达第n-1级台阶与到达第n-2级台阶数之和。这就是一个递归的过程（自己调用自己只是传入参数不一样），递推方程为：
 *
 *				|-> 1, 					n=1
 *		F(n)  = |-> 2,					n=2
 *				|-> F(n-1) + F(n-2), 	n>2
 */
int recursive_count(int n) {

	if(n < 0) {
		return 0;
	}

	cout << n << ' ';
	if (n <= 2) {
		cout << endl;
		return n;
	}

	return recursive_count(n-1) + recursive_count(n-2);
}

int climb_staires(int n) {
	/*
	 * 想着挺简单，写起来，边界判断还挺值得注意的
	 */
	int pre = 0;
	int cur = 1;

	for(int i=1; i<=n; ++i) {
		int tmp = cur;
		cur = pre + cur;
		pre = tmp;
	}

	return cur;
}


int main(int argc, char **argv) {

	// recursive_count(7);
//	cout << recursive(7) << endl;

	cout << climb_staires(2) << endl;

	return 0;
}
