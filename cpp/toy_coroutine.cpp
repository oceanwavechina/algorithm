/*
 * toy_coroutine.cpp
 *
 *  Created on: Apr 16, 2018
 *      Author: liuyanan
 */

#include <iostream>

using namespace std;



/*
 * c 实现类似 python 中的generator, i.e.
	   def rangeN(a, b):
		i = a
		while (i < b):
			yield i
			i += 1  # Next execution resumes
					# from this point

		for i in rangeN(1, 5):
			print(i)

	shamed copied from:
		https://www.geeksforgeeks.org/coroutines-in-c-cpp/

	Implement using:
		Duff's devie + static varaible
 */


int range(int a, int b)
{
	static int i;
	static int state = 0;

	switch(state) {
	case 0:
		state = 1;
		for(i=a; i<b; ++i){
			return i;

	case 1:	// this case is inside of for-loop
		;
		}
	}

	state = 0;
	return 0;
}



int main(int argc, char **argv) {

	int i;

	for(; i=range(1, 5);) {
		cout << "control at main: " << i << endl;
	}

	return 0;
}
