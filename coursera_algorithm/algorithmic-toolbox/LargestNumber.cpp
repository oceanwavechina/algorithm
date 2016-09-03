/*
 * LargestNumber.cpp
 *
 *  Created on: Sep 1, 2016
 *      Author: liuyanan
 */

#include <iostream>
#include <ctime>
#include <vector>
#include <cstdint>
#include <sstream>
#include <cmath>

std::string display(std::vector<long> val) {
	std::stringstream ss;
	for (auto v : val) {
		ss << v << ' ';
	}

	return ss.str();
}

long LargestNumberGreedy(std::vector<long> input) {
	std::vector<long> output;

	// rearrange values
	while( input.size() != 0 ) {
		std::vector<long>::iterator itMax = input.end();

		for (std::vector<long>::iterator it=input.begin(); it!=input.end(); ++it) {
			if ( itMax == input.end() || *it > *itMax)
				itMax = it;
		}

		output.push_back(*itMax);
		input.erase(itMax);
	}

	// calcaulator the integer
	long number = 0;
	int base=output.size() - 1;
	for (auto i : output) {
		number += pow(10, base) * i;
		--base;
	}

	return number;
}


int main() {
	std::vector<long> elements = {5, 7, 3, 9, 1, 9};

	std::time_t start, end;
	start = std::time(nullptr);
	std::cout << "LargestNumberGreedy for: " << display(elements)  << std::endl
			<< "is:" << LargestNumberGreedy(elements) << std::endl
			<< "with time:" << std::time(nullptr)-start << "seconds\n";
}
