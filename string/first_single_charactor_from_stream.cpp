/*
 * first_appear_once_charactor_from_stream.cpp
 *
 *  Created on: Sep 3, 2021
 *      Author: liuyanan
 */

#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>

using namespace std;


/*
	题目：
		请实现一个函数用来找出字符流中第一个只出现一次的字符。

		例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。
			当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。

		输出描述：
			如果当前字符流没有存在出现一次的字符，返回#字符。

	玩法是这样的：
		首先这是根据流，实时输出第一个符合要求的字符，也就是，我们在处理的时候，除了要能知道出现的次数，还需要保证出现的顺序不变。

		所以用 vector 保证出现的顺序，
		用 hash 记录出现的次数
 */


class CharactorCounter{
public:
	void feed(const char c)
	{
		auto iter = _counter.find(c);
		if(iter != _counter.end()) {
			iter->second += 1;
		} else {
			_charactors.push_back(c);
			_counter[c] = 1;
		}
	}

	char first_singele_charactor()
	{
		for(auto c : _charactors) {
			if(_counter[c] == 1) {
				return c;
			}
		}
		return '#';
	}

private:
	vector<char> _charactors;
	unordered_map<char, long/*cnt*/> _counter;
};

int main(int argc, char **argv)
{
	CharactorCounter charCounter;
	string str("google");
	cout << "target string: " << str << endl;

	for(auto ch : str) {
		charCounter.feed(ch);
		cout << "after feed: " << ch << ", first single char is: " << charCounter.first_singele_charactor() << endl;
	}

	return 0;
}
