/*
 * dp_most_profit_stock_trade_once.cpp
 *
 *  Created on: Apr 5, 2021
 *      Author: liuyanan
 */

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;



/*
	Question:
		假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖该股票一次可能获得的最大利润是多少？
		（最多有两次交易机会，买一次算一次交易，卖一次也算一次交易）


	问题分析：
		首先我们认为i是从1开始的, 其取值范围是 [1, i]
		我们进行交易的前提是要赚钱的，要是赔钱的话，那我们就没有交易的的必要了，也就是股价一直在下跌，此时我们的最大利润是0
		所以我们先看看我们进行交易的话，最好的结果是什么，然后在和0比较

		按照 dp_cut_rode.cpp 中理解的DP问题分析思路，我们最多有2次交易机会，假设我们在第 i day 最后一次交易 (可能是第一次，也可能是第二次)
		（ 其中的i，表示的是第i天 ）

			MAX( i ) = price( i ) - MIN( price(i-1), MIN(i-2) )
			MAX(i-1) = price(i-1) - MIN( price(i-2), MIN(i-3) )
			MAX(i-2) = price(i-2) - MIN( price(i-3), MIN(i-4) )
						.
						.
						.
			MAX( 3 ) = price( 3 ) - MIN( price( 2 ), MIN( 1 ) )
			MAX( 2 ) = price( 2 ) - MIN(1)				// 这个是起始，有效的交易，因为每天只能一次, 一天交易两次相当于没有交易

			所以我们需要保存的中间值有两个，一个是MAX， 一个是MIN，其中MAX没有被中间引用，只有MIN被引用，所以我们只保存MIN
			MAX 作为一个全局最大值


		具体实现，我们从 MAX(2) = price(2) - MIN(1) 开始

			MAX( 2 ) = price( 2 ) - MIN( price( 2 ), MIN( 1 ) )						// price(2) 已知, MIN(1)=price(1)
			MAX( 3 ) = price( 3 ) - MIN( price( 2 ), MIN( 1 ) )		// price(3), price(2) 已知, MIN(2)=MIN( price( 2 ), MIN( 1 ) )
						.
						.
						.
			MAX( i ) = price( i ) - MIN( price(i-1), MIN(i-2) )		// price(i), price(i-1) 已知, MIN(i-1)=MIN( price( i-1 ), MIN( i-2 ) )
 */

long max_profit(const vector<long>& prices)
{
	vector<long> mins(prices.size(), LONG_MAX);
	// mins[0] = prices[0];

	long final_max = LONG_MIN;

	ostringstream oss;

	for(int i=1; i<prices.size(); ++i) {

		oss << "i: " << i << ", ";
		mins[i] = min(prices[i-1], mins[i-1]);

		oss << "\tmin[" << i << "]: " << mins[i];
		long cur_max = prices[i] - mins[i];

		oss << "\tcurmax: " << cur_max << "\n";
		if(cur_max > final_max) {
			final_max = cur_max;
		}
	}

	cout << oss.str();

	return final_max > 0 ? final_max : 0;
}

int main(int argc, char **argv)
{
	map<long/*profit*/, vector<long> > samples = {
			{ 5, {7,1,5,3,6,4} },
			{ 4, {1, 2, 3, 4, 5} },
			{ 0, {7, 6, 4, 3, 1} },
	};

	for(const auto pair : samples) {

		long our_max = max_profit(pair.second);
		cout << "correct_max:" << pair.first << ", our_max:" << our_max << "\n" << endl;

		assert(our_max == pair.first);
	}

//	vector<long> prices = {7, 6, 5, 4, 3, 2, 1};
//	long max = max_profit(prices);
//	cout << "max_profit:" << max << endl;

	return 0;
}
