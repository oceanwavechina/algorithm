/*
 * @Author: liuyanan 
 * @Date: 2020-04-28 16:43:43 
 * @Last Modified by: liuyanan
 * @Last Modified time: 2020-04-28 19:36:42
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

/*
    Cutting a Rod | DP-13
    Given a rod of length n inches and an array of prices that contains prices of all pieces of size smaller than n. 
    Determine the maximum value obtainable by cutting up the rod and selling the pieces. 
    
    For example, if length of the rod is 8 and the values of different pieces are given as following, 
    then the maximum obtainable value is 22 (by cutting in two pieces of lengths 2 and 6)

    length   | 1   2   3   4   5   6   7   8  
    --------------------------------------------
    price    | 1   5   8   9  10  17  17  20


    And if the prices are as following, 
    then the maximum obtainable value is 24 (by cutting in eight pieces of length 1)

    length   | 1   2   3   4   5   6   7   8  
    --------------------------------------------
    price    | 3   5   8   9  10  17  17  20


    根据dp的思想，把每一步最优的情况都记录下来，遍历所有元素

    dp的思想是：
    	1. 思考问题从最后一步入手
    	2. 看看每一步都依赖前一步的那些，然后dp的逻辑就是把前一步计算出来
    	3. 也就是，思考的时候是从结果往前推依赖，然后真正的代码是把每步的依赖计算出来，然后保存起来

    	比如这个问题，假设我们现在得到了这个杆最大价值为 MAX(n)， 这里的 n 指的是杆的长度那, 依次类推

    		MAX( n ) = max( (MAX(n-1) + price(1)), price(n))
    		MAX(n-1) = max( (MAX(n-2) + price(1)), price(n-1) )
    		MAX(n-2) = max( (MAX(n-3) + price(1)), price(n-2) )
    					.
    					.
    					.
			MAX( 3 ) = max( (MAX(2) + price(1)), price(3)
    		MAX( 2 ) = max( (MAX(1) + price(1)), price(2)
    		MAX( 1 ) = price(1)

		以上是我们思考的入口，也就是假设我们已经得到了最终结果，然后倒着推算这个最终结果跟之前的关系
		我们可以看到 MAX(n-1), MAX(n-2), MAX(n-3) ... MAX(2), MAX(1), 在这个关系中被引用计算多次
		也就是 越靠前的x (MAX(x)),  重复计算的次数越多，所以减少这些重复计算就是算法的关键
		而减少的办法就是把这些临时结果保存起来

    	可以看到，**最终的** 最优解 MAX(n) 是依次嵌套的依赖于之前的计算结果，
    	以至于，如果我们不从头计算每一步的最优解，我们无法知道最终的结果，
    	而每一步的最优解，又会被后边的计算用到，所以为了减少计算，我们要把这些 **中间最优解** 保存下来，
    	于是就形成了一张表，对应每一步的最优解


    	以上是DP问题的分析思路(从后往前分析)，接下来是实现(从前往后一次计算并保存中间结果), 依次有:

    		MAX( 1 ) = price(1)									// price(1), 是已知条件，这个我们可以知道， 可以计算并保存 MAX(1)
    		MAX( 2 ) = max( (MAX(1) + price(1)), price(2)		// MAX(1), price(1), price(2) 三者都知道, 可以计算并保存 MAX(2)
    						.
    						.
    						.
    		MAX( n ) = max( (MAX(n-1) + price(1)), price(n)		// price(1), price(n) 是已知条件， MAX(n-1) 是之前计算并保存下来的也是知道的

    	经过以上一次计算，并保存，我们就知道最终结果 MAX(n) 了
*/


typedef map<long/*length*/, long/*price*/> TPrice;


long naive_cut_rod(TPrice& price, long total_length)
{
    if (total_length == 0) {
        return 0;
    } else {
        long max_value = 0;
        for(long i = 1; i <= total_length; ++i) {
            max_value = max(max_value, price[i] + naive_cut_rod(price, total_length - i));
        }
        return max_value;
    }    
}

long dp_cut_rod(TPrice& price, long total_length)
{
    vector<long> values_trace(total_length + 1, 0);
    
    // 一段一段的累计，分别计算每一步的最大值
    for(long i = 1; i <= total_length; ++i) {
        long max_value = INT_MIN;
        
        // 计算出当前步的最大值，并保存下来
        for(int j=0; j <= i; ++j) {
            max_value = max(max_value, price[j] + values_trace[i-j]);
        }

        values_trace[i] = max_value;
    }

    return values_trace[total_length];
}


int main(int argc, char const *argv[])
{
    TPrice prices {{1, 1}, {2, 5}, {3, 8}, {4, 9}, {5, 10}, {6, 17}, {7, 17}, {8, 20}};
    
    cout << "max_value(naive): " << naive_cut_rod(prices, 8) << endl;
    
    cout << "max_value(dp): " << dp_cut_rod(prices, 8) << endl;

    return 0;
}
