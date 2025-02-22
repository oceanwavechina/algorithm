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
	给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。

    你可以按 任何顺序 返回答案。

    示例 1：
        输入：n = 4, k = 2

        输出：
        [
          [2,4],
          [3,4],
          [2,3],
          [1,2],
          [1,3],
          [1,4],
        ]

    示例 2：
        输入：n = 1, k = 1
        输出：[[1]]

    提示：
        1 <= n <= 20
        1 <= k <= n
 */



string display(vector<int> data)
{
	ostringstream oss;

	for(auto i: data) {
		oss << i << ", ";
	}

	return oss.str();
}

void combinations_backtracking(const vector<int>& nums, const int k, vector<int>& current, size_t idx) {

    if(current.size() > k) {
        return;
    }

    if(current.size() == k) {
        stringstream oss;
        for(auto& cur : current) {
            oss << cur;
        }
        int i = 0;
        oss >> i;
        cout << i << endl;
        return;
    }

    for(int i=idx; i<nums.size(); ++i) {
        current.push_back(nums[i]);
        combinations_backtracking(nums, k, current, i+1);
        current.pop_back();
    }
}

void combine(int n, int k) {
    vector<int> nums;

    for(size_t num=1; num<=n; ++num) {
        nums.push_back(num);
    }

    vector<int> current;
    combinations_backtracking(nums, k, current, 0);
}


void combinations_mask(const vector<int>& nums, const int k) {

    for(size_t mask=0; mask<pow(2, nums.size()); ++mask) {

        string cur;

        for(size_t i=0; i<nums.size(); ++i) {
            if(!(mask & 1<<i)) {
                continue;
            }

            cur += to_string(nums[i]);

            if(cur.size() == k) {
                cout << cur << endl;
                break;
            }
        }
    }
}

void combine2(int n, int k) {
    vector<int> nums;

    for(size_t num=1; num<=n; ++num) {
        nums.push_back(num);
    }

    combinations_mask(nums, k);
}

int main(int argc, char **argv) {

#if 0
    combine(4, 2);
#else
    combine2(4, 2);
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
