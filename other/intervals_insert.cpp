/*
 * interval_insert.cpp
 *
 *  Created on: Aug 24, 2021
 *      Author: liuyanan
 */

#include <map>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;


/*
	给出一个无重叠的 ，按照区间起始端点排序的区间列表。

		在列表中插入一个新的区间，你需要确保列表中的区间仍然 有序且不重叠（如果有必要的话，可以 合并区间）。

		示例 1:：
			输入: intervals = [[1,3],[6,9]], newInterval = [2,5]
			输出: [[1,5],[6,9]]
		解释:
			新区间[2,5] 与 [1,3]重叠，因此合并成为 [1,5]。

		示例 2:：
			输入: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
			输出: [[1,2],[3,10],[12,16]]
		解释:
			新区间 [4,8] 与 [3,5],[6,7],[8,10] 重叠，因此合并成为 [3,10]。

	思路：

		// 遍历判断肯定是很复杂了
		// 可以分两步， 1.先按区间开始排序并插入，2. 检查合并
		直接插入：

			|__________|			|______|
						 |_______|
		需要合并：

			|__________|	|——————————|
					   |_________|

				 |__________|	|——————————|
			|_________|

 */


typedef pair<long, long> Interval;
typedef vector<Interval> IntervalVec;

void display(const string& msg, const IntervalVec& intervals)
{
	ostringstream oss;
	oss << msg << ": ";

	for(auto interval : intervals) {
		oss << "[" << interval.first << "," << interval.second << "], ";
	}

	cout << oss.str() << endl;
}

IntervalVec insert_interval(IntervalVec& intervals, const Interval& new_inter)
{
	// 先插入
	for(IntervalVec::iterator it = intervals.begin(); it != intervals.end(); ++it) {
		if(new_inter.first <= it->first || it == intervals.end()) {
			intervals.insert(it, new_inter);
			break;
		}
	}

	// 在合并
	for(IntervalVec::iterator cur = intervals.begin(); cur != intervals.end(); ) {

		IntervalVec::iterator nxt = cur + 1;
		if(nxt == intervals.end()) {
			break;
		}

		if(cur->second >= nxt->first) {
			//  有重叠

			// 扩大当前区间
			cur->second = max(cur->second, nxt->second);

			// 删除下一个区间
			intervals.erase(nxt);

		} else {
			// 没有重叠，往下走
			++cur;
		}
	}

	return intervals;
}


int main(int argc, char **argv) {

	IntervalVec intervals = { {1,2}, {3,5}, {6,7}, {8,10}, {12,16} };
	Interval insert = {4, 8};

	display("initial intervals", intervals);

	insert_interval(intervals, insert);

	display("after insert intervals", intervals);

	return 0;
}
