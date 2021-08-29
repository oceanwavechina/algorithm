/*
 * find_the_two_single_numbers.cpp
 *
 *  Created on: Aug 28, 2021
 *      Author: liuyanan
 */

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

/*
	一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。

	示例 1：
		输入：nums = [4,1,4,6]
		输出：[1,6] 或 [6,1]

	示例 2：
		输入：nums = [1,2,10,4,1,4,3,3]
		输出：[2,10] 或 [10,2]
	 
	限制：
		2 <= nums.length <= 10000

	玩法是这样的：
		先假设只有一个数字出现一次，那我们对所有元素进行异或操作，可以得到最终的那个元素。

		而现在是两个元素，首先，两个元素必然不同。所以对其经行异或操作的结果大于0。
			也就是其结果的二进制中至少有一位为1。

		反过来，如果两个数字相同，其异或结果为0(即二进制中没有1出现)。而这两个数的二进制位，要么都为0， 要么都为1

		回到不同元素异或结果中，其至少二进制表示中，至少有一位(假设其下标为idx)为 1。
		也就是说这两个不同的数字的二进制表示中，第 idx 位是不同的。
		我们以此把两个数，分成两部分， 然后各部分内进行异或，就可以在每个部分各自找到一个数字了：
			第 idx 位为 0 的
			第 idx 为 1 的

			比如 2 和 10 的二进制表示分别为：
				2: 0000 0010
			   10: 0000 1010

			其异或的结果为(其中有一位为1)：
				2: 0000 0010

		问题来了：
			1. 会不会把相同的两个数字分到不同的部分？
				不会，因为假设两个数字相同，其二进制的 idx 位也必然相同，所以会分到相同的部分
				有这样的想法，是因为有平均分配的顾虑。此时我们不是平均分配，而是要把两个不同的数字区分开
				可能出现，某一部分中只有一个数字的情况。

 */

pair<int, int> find_the_two_singer_numbers(const vector<int>& data)
{
	pair<int, int> ret;

	// 1.  先找到两个 single number 的异或结果
	int xor_ret = 0;
	for(auto num :  data) {
		xor_ret ^= num;
	}

	// 2. 找到异或结果的二进制中为 1 的那位, 所表示的数
	int base = 0;	// base 是只有为 1 的那位的二进制所表示的数
	for(int pos=0; pos<32; ++pos) {
		if((xor_ret & (1 << pos)) > 0) {
			cout << "pos:" << pos << endl;
			base = (1 << pos);
			break;
		}
	}

	// 3. 分成两组进行异或操作
	for(auto num : data) {
		if((num & base) == 0) {
			ret.first ^= num;
		} else {
			ret.second ^= num;
		}
	}

	return ret;
}

int main(int argc, char **argv) {


	pair<int, int> ret = find_the_two_singer_numbers({1,2,10,4,1,4,3,3});

	cout << "the two single numbers: " << ret.first << ", " << ret.second << endl;

	return 0;
}
