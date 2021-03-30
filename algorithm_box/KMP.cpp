/*
 * @Author: liuyanan 
 * @Date: 2020-05-04 17:49:02 
 * @Last Modified by: liuyanan
 * @Last Modified time: 2020-05-04 20:15:01
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
    详解见 KMP.md

	对比一下暴力朝查找的思路是，主串遍历一遍，每次主串上的位置移动，都去遍历子串

    基本思路：
    	KMP算法优化的点是减少回溯的次数，主串还是遍历一遍，但是每次子串尽量不回退
    		方法是，直接找到最小的回退点

    	先有如下定义
			字符串的前缀集合
				如果字符串A和B，存在A=BS，其中S是任意的非空字符串，那就称B为A的前缀
			字符串的后缀集合
				同样可以定义后缀A=SB，其中S是任意的非空字符串，那就称B为A的后缀
			Partial Match Table
				当前字符串中 前缀集合 和 后缀集合 交集中最长元素的长度

		例子:
			a b abab a b c a
			abab a b c a

		1. 为什么要要引入前后缀
			在主串中，我们关心的是遍历到当前位置的后缀
			在子串中，我们关心的是其前缀
			** 因为自始至终，我们都是在用 子串中的前缀 在和 主串中的后缀进行比较，想想是不是 **

    	2. 为什么子串可以做到不从头开始
    		因为 子串中的前缀是我们进行比较的最基本单位，要是这个前缀都不存在，那肯定主串肯定不包含子串了
			于是 主串后缀 与 子串前缀中 最大的公共长度，就是我们不需要再次比较的，所以不需要回退到公共长度之前

		3. 构造 PMT 表的逻辑，是在干什么
			是在找 所有子串中 前后缀集合交集中 最长元素的长度
			PMT 表是，计算当前字符串 前后缀 交集中 最长元素的长度, 注意这个前后缀不能为空
			比如我们给定字符串 abababca，一次遍历所有子串的前后缀集合
			a
				没有前后缀集合
				最大交集元素长度: 0, 也就是将来比到这里，要是不一样，子串要从头开始
			ab
				前缀集合为 (a)
				后缀集合为 (b)
				最大交集元素长度: 0，也就是将来比到这里，要是不一样，子串要从头开始
			aba
				前缀集合为 (a, ab)
				后缀集合为 (a, ba)
				最大交集元素长度: 1，也就是将来比到这里，要是不一样，子串的前 1 个元素不用比较了，从子串的 第 2 个元素开始接着比较
			abab
				前缀集合为 (a, ab, aba)
				后缀集合为 (a, ab, bab)
				最大交集元素长度: 2，也就是将来比到这里，要是不一样，子串的前 2 个元素不用比较了，从子串的 第 3 个元素开始接着比较
			ababa
				前缀集合为 (a, ab, aba, abab)
				后缀集合为 (a, ba, aba, baba)
				最大交集元素长度: 3，也就是将来比到这里，要是不一样，子串的前 3 个元素不用比较了，从子串的 第 4 个元素开始接着比较
			ababab
				前缀集合为 (a, ab, aba, abab, ababa)
				后缀集合为 (b, ab, bab, abab, babab)
				最大交集元素长度: 4，也就是将来比到这里，要是不一样，子串的前 4 个元素不用比较了，从子串的 第 5 个元素开始接着比较

			......

		4. PMT 是如何具体实现的
			子串其实的 最大公共长度都是0
			PMT 在实现时，把 所有的值，按下标位置整体往后平移了一下，为了编程方便
			如下变的get_next()函数中
			i 表示的是字符串的后缀
			j 表示的是字符串的前后缀最长的长度

			TODO

*/

int kmp(const string& str, const string& pattern, const vector<int>& next) 
{
    int i=0, j=0;

    while (i < str.length() && j < pattern.length()) {

        if(j == -1 || str[i] == pattern[j]) {
            ++i;
            ++j;
        } else {
            j = next[j];
        }
    }
    
    if(j == pattern.length()) {
        return i-j;
    } else {
        return -1;
    }
}

void get_next(const string& pattern, vector<int>& next)
{
    next.resize(pattern.length() + 1);

    next[0] = -1;
    int i = 0, j = -1;
    
    while (i < pattern.length()) {

        if(j == -1 || pattern[i] ==  pattern[j]) {
            ++i;
            ++j;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
    
}

int main(int argc, char const *argv[])
{
    const string str = "abbaabbaaba";
    const string pattern = "abbaaba";
    
    cout << "string : " << str << "\n";
    cout << "pattern: " << pattern << "\n";

    vector<int> next;

    get_next(pattern, next);

    int pos = kmp(str, pattern, next);
    
    cout << "pos:" << pos << endl;

    return 0;
}
