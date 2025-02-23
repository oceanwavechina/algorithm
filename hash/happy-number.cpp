/*
 * happy-number.cpp
 *
 *  Created on: Feb 23, 2025
 *      Author: liuyanan
 */

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <unordered_set>

using namespace std;


/*
    编写一个算法来判断一个数 n 是不是快乐数。

    「快乐数」 定义为：

    对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
    然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
    如果这个过程 结果为 1，那么这个数就是快乐数。
    如果 n 是 快乐数 就返回 true ；不是，则返回 false 。


    示例 1：
        输入：n = 19
        输出：true
        解释：
            1**2 + 9**2 = 82
            8**2 + 2**2 = 68
            6**2 + 8**2 = 100
            1**2 + 0**2 + 0**2 = 1

    示例 2：
        输入：n = 2
        输出：false
 */

int cal_sqr(int n) {
    int ans = 0;
    while(n) {
        ans += std::pow(n%10, 2);
        n /= 10;
    }

    return ans;
}

bool is_happy(int n, std::unordered_set<int>& visited) {

    int ans = cal_sqr(n);
    if(ans == 1) {
        return true;
    }

    if(visited.count(ans)) {
        return false;
    }

    visited.insert(ans);
    return is_happy(ans, visited);
}



int main(int argc, char **argv) {

    std::unordered_set<int> visited;

    cout << "is happy:" << is_happy(2, visited) << endl;

    return 0;
}
