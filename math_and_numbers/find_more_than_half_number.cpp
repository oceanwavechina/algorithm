/*
 * find_more_than_half_number.cpp
 *
 *  Created on: Jul 3, 2021
 *      Author: liuyanan
 */

#include <iostream>
#include <sstream>
#include <vector>


/*
	问题：
		数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
		例如输入一个长度为 9 的数组 {1,2,3,2,2,2,5,4,2}。
		由于数字2在数组中出现了 5 次，超过数组长度的一半，因此输出 2, 否则输出0

	注意：
		这个下面的这个算法其实是有个条件限制的，就是这个元素必须存在， 所以我们要加一个校验是否是真的超过了半数

	两种思路
 */

bool is_more_than_half(const std::vector<int>& data, int number)
{
	int counter = 0;
	for(const auto& item : data) {
		if(number == item) {
			++counter;
		}
	}

	return counter >= data.size() / 2;
}


int partition(std::vector<int>& data, int left, int right)
{
	// left 和 right 是闭区间
	int pivot_pos = left;
	int pivot_val = data[left];

	right +=1;	// 注意这里为什么要先 +1

	while(true) {

		do {
			++left;
		} while(data[left] < pivot_val);

		do {
			--right;
		} while(data[right] > pivot_val);

		if(left >= right) {
			break;
		}

		std::swap(data[left], data[right]);
	}

	// 注意这里为什么 povit 要跟 right 交换
	std::swap(data[pivot_pos], data[right]);

	return left;
}

int find_more_than_half_number_using_partition(std::vector<int>& data)
{
	//
	//	思路是：
	//		如果一个数出现大于半数，在排序后，那他一定会出现在中间位置
	//			比如最小的那个数大于半数，那至少前一半 + 1 的元素都是它
	//		根据快拍的思想，我们尝试找中间那个数，找到后判断下是不是就可以了
	//

	if(data.empty()) {
		return 0;
	}

	int cur_pos = partition(data, 0, data.size()-1);

	int middle_pos = data.size() / 2;

	do {
		if(cur_pos == middle_pos) {
			// 这个数就是中间位置
			break;

		} else if (cur_pos < middle_pos) {
			// 需要在右边找
			cur_pos = partition(data, cur_pos+1, data.size()-1);

		} else {
			// 需要在右边找
			cur_pos = partition(data, 0, cur_pos-1);
		}

	} while(cur_pos != middle_pos);

	if(is_more_than_half(data, data[cur_pos])) {
		return data[cur_pos];
	} else {
		return 0;
	}
}

int find_more_than_half_number_using_counter(const std::vector<int>& data)
{
	//
	// 这里的玩法思路是
	//		如果一个元素超过半数，那对它计数时，一定是大于元素总个数的 1/2 的
	//		所以，我们对相同的元素进行计数，出现一次就 +1， 当没有出现就 -1，
	//		直到为0， 重新对新元素计数
	//		也就是用 其他元素出现的次数 去抵消 大于半数元素出现的次数
	//		这里的要点是，
	//			当计数为0时，要设置下一个元素的计数为1
	//			如果剩余的那个元素的计数大于0，那它目标元素
	//

	if(data.empty()) {
		return 0;
	}

	int target_number = data[0];
	int counter = 1;

	for(int i=1; i<data.size(); ++i) {

		if(data[i] == target_number) {
			counter += 1;

		} else {
			counter -= 1;

			// 是否要保存新的元素
			if(counter == 0) {
				target_number = data[i];
				counter = 1;
			}
		}
	}

	return is_more_than_half(data, target_number) ? target_number : 0;
}

void display(const std::vector<int>& data)
{
	for(const auto& item : data) {
		std::cout << item << " ";
	}
	std::cout << std::endl;
}

int main(int argc, char **argv)
{
	std::vector<int> numbers {1,2,3,2,2,2,5,4,2};
	//std::vector<int> numbers {1,2,3,2,2,3,5,4,1};
	display(numbers);

	std::cout << "target number (const): " << find_more_than_half_number_using_counter(numbers) << std::endl;

	std::cout << "target number (mutable): " << find_more_than_half_number_using_partition(numbers) << std::endl;
	display(numbers);

	return 0;
}
