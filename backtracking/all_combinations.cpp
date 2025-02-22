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
	给定一个数组，内容比如[1,2,3,4,5]，输出所有数字的组合情况（注意不是全排列），给定数组的数字不重复。

    比如给定[1,2,3]，输出结果为 12、23、13、123、1、2、3、空
                             12、23、 1,  123, 2, , 3
 */



string display(vector<int> data)
{
	ostringstream oss;

	for(auto i: data) {
		oss << i << ", ";
	}

	return oss.str();
}


void generate_combinations_backtracking(const vector<int>& nums, vector<int>& current, size_t idx)
{
    for(const int& cur : current) {
        cout << cur;
    }
    cout << endl;


    for(size_t i=idx; i<nums.size(); ++i) {
        current.push_back(nums[i]);
        generate_combinations_backtracking(nums, current, i+1);
        current.pop_back();
    }
}


void generate_combinations_mask(const vector<int>& nums) {

    for(size_t mask=0; mask<pow(2, nums.size()); ++mask) {

        std::string cur_comb;

        for(size_t j=0; j<nums.size(); ++j) {
            if(mask & (1<<j)) {
                cur_comb += to_string(nums[j]);
            }
        }

        cout << cur_comb << endl;
    }
}



int main(int argc, char **argv) {

    vector<int> nums = {1,2,3,4};
	std::cout << "original data: " << display(nums) << std::endl;

#if 0
	vector<int> current;
	generate_combinations_backtracking(nums, current, 0);
#else
	generate_combinations_mask(nums);
#endif

	return 0;
}


/*
  from deepseek:
      现在，具体的实现步骤可能是这样的：

1. 确定数组的长度n。

2. 计算总共有2^n个子集，包括空集。

3. 遍历每个可能的子集，即从0到2^n -1的每个数。

4. 对于每个数，将其转换为二进制，然后检查每一位是否为1。每一位对应数组中的一个元素，如果该位是1，就将对应的元素加入到当前子集的字符串中。

5. 将生成的字符串收集起来，最后返回所有字符串的列表。

例如，数组是[1,2,3]，每个子集的二进制位数是3位：

- i=0 → 000 → 空 → 输出空字符串

- i=1 → 001 → 第一个元素 → 1

- i=2 → 010 → 第二个元素 → 2

- i=3 → 011 → 第一、二元素 → 12

- i=4 → 100 → 第三个元素 →3

- i=5 → 101 → 1和3 →13

- i=6 → 110 →2和3 →23

- i=7 →111 →全部 →123

所以总共有8个子集，对应的字符串如上述。那例子中的输出是12、23、13、123、1、2、3、空。
但按照这个顺序的话，可能遍历的顺序是按照i的顺序，比如i=0是空，然后是1，2，3，4等。
但例子中的输出可能没有按照i的顺序排列。不过不管顺序如何，只要所有可能的组合都被生成即可。
 */
