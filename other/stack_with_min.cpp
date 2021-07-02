/*
 * stack_with_min.cpp
 *
 *  Created on: Jul 2, 2021
 *      Author: liuyanan
 */

#include <iostream>
#include <stack>


/*
  	  实现一个stack，要求push，pop，min 的时间复杂度都是 O(1)

  	  思路是使用一个辅助栈
  	  	  1. 并不是所有元素都压入辅助栈
  	  	  2. 考点是压入重复的元素时，怎么处理，这个是一个要点
 */

template<typename T>
class StackWithMin {
public:
	void push(T val) {
		_stack.push(val);

		// 这里的小于等于是考点，想想为什么
		if(_min.empty() || val <= _min.top()) {
			_min.push(val);
		}
	}

	void pop() {
		if(_stack.top() <= _min.top()) {
			_min.pop();
		}
		_stack.pop();
	}

	T min() {
		return _min.top();
	}

private:
	std::stack<T> _stack;
	std::stack<T> _min;
};



int main(int argc, char **argv)
{

	StackWithMin<int> stack_min;

	stack_min.push(5);
	std::cout << "after push 5, min:" << stack_min.min() << std::endl;

	stack_min.push(2);
	std::cout << "after push 2, min:" << stack_min.min() << std::endl;

	stack_min.push(2);
	std::cout << "after push 2, min:" << stack_min.min() << std::endl;

	stack_min.pop();
	std::cout << "after pop, min:" << stack_min.min() << std::endl;

	stack_min.push(1);
	std::cout << "after push 1, min:" << stack_min.min() << std::endl;


	stack_min.pop();
	std::cout << "after pop, min:" << stack_min.min() << std::endl;
}
