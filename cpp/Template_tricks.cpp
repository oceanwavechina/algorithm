/*
 * Template_Meta_programming_tricks.cpp
 *
 *  Created on: Apr 20, 2018
 *      Author: liuyanan
 */

#include <iostream>
#include <stdio.h>


using namespace std;

/*
 * 思路就是把运行时的计算移到编译时期执行,
 *     1. 编译期间的值都是要求不能变的，所以要么是常量，要么是只读变量
 * 	   2. 对于递归，用模版特例来确定循环终止条件，也就是返回栈顶的值
 * 	   3. 最有用的也就是递归了，因为可以循环计算。在然后就是跨平台支持的例子了
 *
 * 突然想到了python中对于小于255的值都创建了缓存变量，如果某段逻辑需要大量的重复计算，
 * 其实也可以借鉴，提前计算出来然后，缓存起来。
 * 进一步，还可以用LRU缓存，来优化保存最常用的值
 */


/* ****************************** functions ****************************** */
template<int X, int Y>
struct Adder
{
	// 我怀疑现代的编译器，只要你写 1+2 这样的代码，它就能自动帮你把结果计算出来
	// 不过这种用法还是听好玩儿的
   enum { result = X + Y };
};


/* ****************************** recursion ****************************** */
template <unsigned n>
struct factorial
{
	enum {value = n*factorial<n-1>::value};
};

template <>
struct factorial<0>
{
	enum {value = 1};
};


/* ****************************** example:if_ ****************************** */
template <bool Condition, typename TrueResult, typename FalseResult>
struct if_;	// 这是个空类，有用的都是特例出来的

template <typename TrueResult, typename FalseResult>
struct if_<true, TrueResult, FalseResult>
{
	typedef TrueResult result;
};

template <typename TrueResult, typename FalseResult>
struct if_<false, TrueResult, FalseResult>
{
	typedef FalseResult result;
};


/* ****************************** Barton-Nackman trick ****************************** */
template <typename T>
class EquaityComparable {
public:
	friend bool operator==(const T& lft, const T& rgt) {
		return lft.equalTo(rgt);
	}

	friend bool operator!=(const T& lft, const T& rgt) {
		return !lft.equalTo(rgt);
	}
};

class Node: private EquaityComparable<Node> {

public:
	explicit Node(float _data):data(_data){};

public:
	bool equalTo(const Node& other) const {
		//cout << "call Node::equalto" << endl;
		return data-other.data < 0.001 && data-other.data > -0.001;
	}

private:
	float data;
};


int main(int argc, char **argv) {

	// 直接放一个URL是不会编译报错的。猜猜为啥
	https://en.wikibooks.org/wiki/C%2B%2B_Programming/Templates/Template_Meta-Programming
	cout << "result of Adder<1, 2>: " << Adder<1, 2>::result << endl;


	const int NUM =3;	// 一定要是 “不变量”
	cout << "factorial of " << NUM << ": " << factorial<NUM>::value << endl;


	/* 如果类型写错了，3被赋值到void* 上就会编译失败 */
	typename if_<true, int, void*>::result number(3);
	typename if_<false, int, void*>::result pointer(&number);

	typedef typename if_<(sizeof(void*) > sizeof(uint32_t)), uint64_t, uint32_t>::result integral_prt_t;
	typedef typename if_<(sizeof(void*) < sizeof(uint32_t)), uint64_t, uint32_t>::result integral_prt_2_t;

	integral_prt_t length = -1;
	integral_prt_2_t length2 = -1;
	cout <<"length of integral_prt_t: " << length << endl << "length of integral_prt_2_t: " << length2 << endl;



	Node a(1.001), b(1.0012), c(1.1), d(1.12);
	cout << "Node(1.001)==Node(1.0012)? : " << boolalpha << (a==b )<< endl;
	cout << "Node(1.1)==Node(1.12)? : " << boolalpha << (c==d )<< endl;



	return 0;
}
