/*
 * intervals_merge.cpp
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
	给出一个区间的集合，请合并所有重叠的区间。

		示例 1:：
			输入: intervals = [[1,3],[2,6],[8,10],[15,18]]
			输出: [[1,6],[8,10],[15,18]]
		解释:
			区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6]。

		示例 2:：
			输入: intervals = [[1,4],[4,5]]
			输出: [[1,5]]
		解释:
			区间 [1,4] 和 [4,5] 可被视为重叠区间。

	思路：
		先把所有区间按起始位置从小到大排序， 然后从从小到大，依次判断是否可以合并

		需要合并的情况：

			|__________|
					|_________|
		或是

			|__________|
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

IntervalVec merge_intervals(IntervalVec& intervals)
{
	// sort by start
    sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {return a.first < b.first;});

    // display("after sort", intervals);

    for(IntervalVec::iterator cur = intervals.begin(); cur != intervals.end(); ) {

    	IntervalVec::iterator nxt = cur + 1;

    	if(nxt == intervals.end()) {
    		break;
    	}

    	if(nxt->first <= cur->second) {
    		// 需要 merge

    		// 1. 扩大当前区间的，可能是扩大，因为 nxt 可能是 cur 的子集
    		cur->second = max(cur->second, nxt->second);

    		// 2. 删除下一个区间
    		intervals.erase(nxt);

    	} else {
    		++cur;
    	}
    }

    return intervals;
}




int main(int argc, char **argv) {

	// IntervalVec intervals = { {1,3}, {2,6}, {8,10}, {15,18} };
	// IntervalVec intervals = { {1,4}, {4,5} };
	IntervalVec intervals = { {1,30}, {2,6}, {8,10}, {15,18} };

	display("initial intervals", intervals);

	IntervalVec merged = merge_intervals(intervals);

	display("merged intervals", merged);

	return 0;
}
