/*
 * FibRecurs.cpp
 *
 *  Created on: Aug 31, 2016
 *      Author: liuyanan
 */

#include <iostream>
#include <ctime>
#include <vector>

/*
 * 1. 视频上讲的是 n<=1, 说的是数值，实际编码起来，n应该是个数
 * 2. 像这种递归掉用的时间复杂度该怎么分析呢，看不懂：http://www.cnblogs.com/python27/archive/2011/12/09/2282486.html
 */
long long fibcurs(int n) {
	if (n <= 2)
	// if (n <= 1)
		return n;
	else
		return fibcurs(n-1) + fibcurs(n-2);
}

/*
 * 1. 需要注意的是，返回类型是 long long， 不然太大了就溢出了
 * 2. 因为数组是从 0 开始的，前两个元素是1， 1; 注意下标的转换
 * 3. 这样做的问题是，空间复杂度也是线性的，有多少个元素就要分配多大的空间
 */
long long fiblinear(int n) {
	std::vector<long long> array(n);
	array[0] = 1;
	array[1] = 1;

	for (int i=2; i<=n; ++i) {
		array[i] = array[i-1] + array[i-2];
	}

	return array[n];

}

int main() {
	int n;
	std::cin >> n;
	std::time_t start, end;
	start = std::time(nullptr);
//	std::cout << "fibcurs1 for " << n <<":" << fibcurs(n) << ", with time:" << std::time(nullptr)-start << "seconds\n";
	std::cout << "fiblinear for " << n <<":" << fiblinear(n) << ", with time:" << std::time(nullptr)-start << "seconds\n";
}
