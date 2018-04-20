/*
 * stricks.cpp
 *
 *  Created on: Apr 20, 2018
 *      Author: liuyanan
 */

#include <iostream>
#include <list>


using namespace std;


int main(int argc, char **argv) {


	list<int> x;
	x.push_back(10);
	x.push_back(20);

	for (auto i : x) {
		cout << i;
	}

	return 0;
}
