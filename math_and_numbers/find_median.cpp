/*
 * find_median.cpp
 *
 *  Created on: Apr 3, 2018
 *      Author: liuyanan
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
	Median is the middle value in an ordered integer list. If the size of the list is even,
	there is no middle value. So the median is the mean of the two middle value.

	Examples:
		[2,3,4] , the median is 3
		[2,3], the median is (2 + 3) / 2 = 2.5

	Design a data structure that supports the following two operations:
		void addNum(int num) - Add a integer number from the data stream to the data structure.
		double findMedian() - Return the median of all elements so far.

	For example:
		add(1)
		add(2)
		findMedian() -> 1.5
		add(3)
		findMedian() -> 2
*/

/*
 *  思路：
 *		1. 两个堆，大根堆存的是较小的数，小根堆存的是较大的数
 *		2. 大根堆（较小的数）中比小根堆最多大1 ，
 *			如果是{1,2,3}的话，大根堆对应的是{1,2}, 小根堆对应的是{3}, 结果是大根堆的最大值
 *			如果是{1,2,3,4}的话，大根堆是{1,2},小根堆是{3,4},结果是大根堆的最大值和小根堆的最大值，二者的均值
 *		3. 在插入时候的技巧是，进入小根堆的是大根堆的最大值，反之亦然
 *
 *  为什么不用排序：
 *  	因为按照题目的要求看，场景应该是stream类型的数据流，所以每当add一个元素的时候都要对所有元素sort一次（如果是快排的话，也是nlogn）
 *  	如果是用两个heap的话，没增加一个元素的时间复杂度是logn
 */

class MedianFinder{

public:
	MedianFinder():_counter(0){}

	void add(int num) {

		// counter 标示的是当前存储了多少数据，所以初始值，和先加还是后加要对应好
		if (++_counter % 2 == 1) {

			// 奇数的进入较小的一边，也就是大根堆
			// 并不是直接插入，而是在小根堆那边换出一个来
			_min_heap.push(num);
			int smaller = _min_heap.top();
			//cout << "into max-heap: " << smaller << endl;
			_min_heap.pop();

			_max_heap.push(smaller);
		} else {

			_max_heap.push(num);
			int bigger = _max_heap.top();
			//cout << "into min-heap: " << bigger << endl;
			_max_heap.pop();

			_min_heap.push(bigger);
		}
	}

	float findMedian() {
		/*
		 * 写错的点：
		 * 		1. 返回值要是float
		 * 		2. 求平均值的时候要用2.0， 而不是2。不然隐士转成整数了
		 */

		//cout << "_counter: " << _counter << endl;
		if (_counter % 2 == 0) {
			return (_max_heap.top() + _min_heap.top()) / 2;
		} else {
			return _max_heap.top();
		}
	}

private:
	// 优先级队列没有清空操作
	priority_queue<int> _max_heap;
	priority_queue<int, std::vector<int>, std::greater<int>> _min_heap;
	int _counter;
};

void tester(vector<int> nums)
{
	cout << "input nums: ";
	MedianFinder finder;

	for(auto num : nums) {
		finder.add(num);
		cout << num << "\t";
	}
	cout << endl;

	cout << "median is: " << finder.findMedian() << endl << endl;
}


int main(int argc, char **argv) {

	vector<int> test1 = {2, 3, 4};
	vector<int> test2 = {2, 3};

	tester(test1);
	tester(test2);

	return 0;
}
