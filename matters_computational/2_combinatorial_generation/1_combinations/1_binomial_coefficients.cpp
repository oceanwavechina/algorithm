/*
 * @Author: liuyanan 
 * @Date: 2019-02-13 17:55:13 
 * @Last Modified by: liuyanan
 * @Last Modified time: 2019-02-13 18:30:19
 */

#include <iostream>

using namespace std;

/*
组合数公式
    c(n,k) = n! / ( k! * (n-k)! )
           
           = n(n-1)(n-2)...(n-k+1) / k(k-1)(k-2)...1

为了避免溢出，用下面的计算顺序:
（这个变形使得代码计算简化了很多）
    c(n,k) = (n-k+1)/1 * (n-k+2)/2 * (n-k+3)/3 ... n/k
*/

u_long binomial(u_long n, u_long k)
{
    if(k > n) return 0;
    if( k==0 || k==n ) return 1;

    // 可以少计算一些，利用了组合公式的对称性
    if( 2*k > n ) k = n-k;

    u_long result = n - k + 1;
    u_long next_numerator = result;

    for(int i=2; i<k; ++i) {
        next_numerator += 1;
        result /= i;
        result *= next_numerator;
    }

    return result;
}

int main(int argc, char const *argv[])
{
    cout << "binomial of (3, 1): " << binomial(3, 1) << endl;
    cout << "binomial of (10, 2): " << binomial(10, 2) << endl;
    return 0;
}
