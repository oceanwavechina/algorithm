/*
 * radix_convert.cpp
 *
 *  Created on: Nov 21, 2016
 *      Author: liuyanan
 */



#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

template <typename T>
std::string display(T val) {
	std::stringstream ss;
	for (auto v : val) {
		ss << v << ' ';
	}

	return ss.str();
}


void decimal_2_binary(int x)
{
	vector<int> a;
	int i = 0;

	do{
		a.push_back(x % 2);
		x = x / 2;
		i++;
	} while( x!=0 );

	while( i>0 ) {
		cout  << a[--i];
	}

	cout << endl;
}


int main()
{
	int d;
	cout << "input a number: ";
	cin >> d;
	decimal_2_binary(d);

	cout << "done";

	return 0;
}

