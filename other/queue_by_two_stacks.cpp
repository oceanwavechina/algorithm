/*
 * queue_by_two_stacks.cpp
 *
 *  Created on: Aug 8, 2021
 *      Author: liuyanan
 */


#include <iostream>
#include <algorithm>
#include <stack>
#include <cassert>

using namespace std;


/*

问题：
	用两个栈来实现一个队列，分别完成在队列尾部插入整数(push)和在队列头部删除整数(pop)的功能。 
	队列中的元素为int类型。保证操作合法，即保证pop操作时队列内已有元素。

示例:
	输入:
		["PSH1","PSH2","POP","POP"]
	返回:
		1,2
解析:
	"PSH1":代表将1插入队列尾部
	"PSH2":代表将2插入队列尾部
	"POP“:代表删除一个元素，先进先出=>返回1
	"POP“:代表删除一个元素，先进先出=>返回2

思路：
	利用栈先进后出的原则，如果是 pop 操作的话，就把数据倒到另一个栈里边。
 */

class QueueByStacks
{
public:
	QueueByStacks(){}
	~QueueByStacks(){}
	

	void push_back(int x) {
		// push 的话，只需要在 _in 里边入栈即可。也就是只管保存数据
		_in.push(x);
	}

	int pop_front() {
		/*
			pop 的话需要 ‘倒’ 一次数据
			被倒过来的数据正好就是被反转了。
			第一次想这个问题时，这样是高效的吗。现实中应该没人这么干，应该只是考察stack 的特性。
		*/

		if(_out.empty()) {
			if(_in.empty()) {
				throw runtime_error("empty already");
			}

			do{
				_out.push(_in.top());
				_in.pop();

			} while(!_in.empty());
		}

		int ret = _out.top();

		_out.pop();

		return ret;
	}

private:
	stack<int> _in;
	stack<int> _out;
};


int main(int argc, char **argv)
{
	QueueByStacks queue;

	queue.push_back(1);
	queue.push_back(2);
	queue.push_back(3);

	assert(queue.pop_front() == 1);

	queue.push_back(4);
	queue.push_back(5);

	assert(queue.pop_front() == 2);	
	assert(queue.pop_front() == 3);	
	assert(queue.pop_front() == 4);	
	assert(queue.pop_front() == 5);	
}
