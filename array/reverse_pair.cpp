/*
 * reverse_pair.cpp
 *
 *  Created on: Aug 10, 2018
 *      Author: liuyanan
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>

using namespace std;

/*
	在数组中的两个数字如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。给你一个数组，求出这个数组中逆序对的总数。
		概括：如果a[i] > a[j] 且 i < j， a[i] 和 a[j] 构成一个逆序对。

	例如：
		序列 [7, 5, 6, 4] 中，有 5 个逆序对 (7, 6), (7, 5), (7, 4), (6, 4), (5, 4)，则返回 5 。


	玩法是这样的：
		用暴力方法的话对于每个元素，都跟其他元素比较。时间复杂度是 O(n^2)

		优化后的是变化时，对于已经比较过的两个元素，就不在进行比较。方法就是比较过的两个元素进行排序处理，使用的是归并排序：先是递归分解，然后排序合并

		比如，原数组递归分解后有：

								[7, 5, 6, 4]
							   /  		  	\
							[7, 5]        [6, 4]
							/	 \		  /	    \
						  [7]	 [5]	[6]	 	[4]

		其实重点是如何排序合并，以及计算逆序对的：

			1. 合并是从最底层开始的。比如 7 > 5， 所以 [7, 5] 组成一个逆序对。同理 [6, 4] 也是

			2. 进行排序合并，排序后为 [5，7] 和 [4, 6] 量部分。注意每部分内部不在比较，而是两部分之间进行比较
			 	 这也就是使用归并排序，减少比较次数的原因

		当合并最下层后，接着上图有：

								[7, 5, 6, 4]
							   /  		  	\
							[7, 5]        [6, 4]
							/	 \		  /	    \
						  [7]	 [5]	[6]	 	[4]
						  	\    /		  \		/
						  	[5, 7]         [4, 6]
						  		^			   ^
						  	 <- p1			<- p2


		单个元素的比较很简单。接下来才是一般性步骤，也是比较复杂的地方。比较跟合并 [5, 7] [4, 6] 两部分：

			1. 在比较的时候，我们会从最大的开始(因为只有从大的开始，才能找到所有)， 两部分的两个指针分别依次从右往左移动(即，从大往小移动)，并比较

			2. 例如，初始状态，两个指针分别指向各自最末(最大)的元素，即 p1 和 p2 分别指向 7 和 6

			3. 此时有 7 > 6, 因为两部分都已经排好序了，所以 7 大于 第二部分的任何一个元素。

				此时产生的逆序对的个数是 从 p2 指针(含) 到 第二部分起始元素， 也就是 p2 - section2begin + 1

	 		4. 当比较完 7 和 6 之后， 此时 7 就在比较的价值了，把 7 放到排序数组最后一个，因为它是最大的嘛， 然后 p1 往前移动到元素 5 的位置

	 		5. 此时有 6 > 5, 继续按第三步的逻辑执行。直到当前部分的元素都放到排序数组里边

 */


using DataVec = vector<int>;

string display(DataVec data)
{
	ostringstream oss;

	for(auto i: data) {
		oss << i << ", ";
	}

	return oss.str();
}

int g_count = 0;

DataVec merge(DataVec part1, DataVec part2)
{

	/*
	 这里有几个容易出错的点需要注意下：
		1. 在往 sorted 数组里边插入的时候是从后往前插入的，也就是新插入到 sorted 数组的元素在前边。 因为我们总是先插入最大的。
	 	2. 如果 part2 中的元素 大于 part1 中的元素，是不累加逆序对个数的，因为 part2 中的元素就应该大于 part1 中的元素
		3. 每比较一次，必然会至少有一个元素放到 sorted 里边，并且至少会有一个指针向前移动

	 */

	DataVec sorted;

	std::cout << "current part1: " << display(part1) << std::endl;
	std::cout << "current part2: " << display(part2) << std::endl;

	int p1 = part1.size() - 1;		// 指向 part1 中最大的元素
	int p2 = part2.size() - 1;		// 指向 part2 中最大的元素


	while(p1 >= 0 && p2 >= 0) {

		if(part1[p1] > part2[p2]) {

			g_count += p2 + 1;
			sorted.insert(sorted.begin(), part1[p1]);
			cout << "reverse pair cnt: " << p2 + 1 << ", max: " << part1[p1] << endl;
			--p1;

		} else if (part2[p2] > part1[p1]) {

//			g_count += p1 + 1;
//			cout << "reverse pair cnt: " << p1 + 1 << ", max: " << part2[p1] << endl;

			sorted.insert(sorted.begin(), part2[p2]);
			--p2;

		} else {
			sorted.insert(sorted.begin(), part1[p1]);
			sorted.insert(sorted.begin(), part2[p2]);
			--p1;
			--p2;
		}
	}

	while(p1 >= 0) {
		sorted.insert(sorted.begin(), part1[p1]);
		--p1;
	}

	while(p2 >= 0) {
		sorted.insert(sorted.begin(), part2[p2]);
		--p2;
	}

	std::cout << "current C: " << display(sorted) << std::endl << endl;

	return sorted;
}

DataVec merge_sort(DataVec data)
{
	if(data.size() <= 1)
		return data;

	int mid = data.size() / 2;

	DataVec part1 = merge_sort(DataVec(data.begin(), data.begin()+mid));
	DataVec part2 = merge_sort(DataVec(data.begin()+mid, data.end()));

	return  merge(part1, part2);
}


int main(int argc, char **argv) {

	DataVec data = {7, 5, 6, 4};
	std::cout << "original data: " << display(data) << std::endl;

	DataVec result = merge_sort(data);
	std::cout << "sorted data: " << display(result) << std::endl;

	cout << "reverse pairs count: " << g_count << endl;

	return 0;
}
