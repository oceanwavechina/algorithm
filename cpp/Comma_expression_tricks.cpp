/*
 * stricks.cpp
 *
 *  Created on: Apr 20, 2018
 *      Author: liuyanan
 */

#include <iostream>
#include <stdexcept>
#include <cassert>


/*
 * try 初始化列表，还可以这样用
 * https://en.wikibooks.org/wiki/More_C%2B%2B_Idioms/Construction_Tracker
 *
 * 这里边的技巧就是：
 * 	1. 逗号表达式只返回最后一个表达式的结果
 *
 * 	In a comma expression E1, E2, the expression E1 is evaluated,
 * 	its result is discarded (although if it has class type, it won't be destroyed until the end of the containing full expression),
 * 	and its side effects are completed before evaluation of the expression E2 begins
 */

using namespace std;

struct B {
    B (char const *) { throw std::runtime_error("B Error"); }
};
struct C {
    C (char const *) { throw std::runtime_error("C Error"); }
};
class A {
   B b_;
   C c_;
   enum TrackerType { NONE, ONE, TWO };
public:
   A( TrackerType tracker = NONE)
   try    // A constructor try block.
     : b_((tracker = ONE, "hello")) // Can throw std::exception
     , c_((tracker = TWO, "world")) // Can throw std::exception
     {
        assert(tracker == TWO);
        // ... constructor body ...
     }
   catch (std::exception const & e)
     {
        if (tracker == ONE) {
           std::cout << "B threw: " << e.what() << std::endl;
        }
        else if (tracker == TWO) {
           std::cout << "C threw: " << e.what() << std::endl;
        }
        throw;
     }
};

int main (void)
{
    try {
    	int tracker(0);

    	string str = (tracker = 1, "hello");
    	// string str = ("hello", tracker = 1);	// error
    	std::cout << "str: " << str << std::endl;
    	std::cout << "tracker:" << tracker << endl;
        A a;
    }
    catch (std::exception const & e) {
          std::cout << "Caught: " << e.what() << std::endl;
    }
    return 0;
}
