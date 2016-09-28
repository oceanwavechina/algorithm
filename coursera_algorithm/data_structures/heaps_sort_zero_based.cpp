/*
 * heaps.cpp
 *
 *  Created on: Sep 28, 2016
 *      Author: liuyanan
 */


#include <iostream>
#include <ctime>
#include <vector>
#include <cstdint>
#include <sstream>
#include <cmath>


template <typename T>
std::string display(T val) {
	std::stringstream ss;
	for (auto v : val) {
		ss << v << ' ';
	}

	return ss.str();
}


class Heaps {
	/*
	 * 序号 i 是从 0 开始的
	 */
public:
	~Heaps() {};

public:
	long parent(int i) {
		return std::floor((i-1)/2);
	}

	long leftChild(int i) {
		return 2*i+1;
	}

	long rightChild(int i) {
		return 2*i + 2;
	}

	void shiftUp(int i) {
		while(i>0 && _data[parent(i)] < _data[i]) {
			std::swap(_data[parent(i)], _data[i]);
			i = parent(i);
		}
	}

	void shiftDown(int i) {
		int maxIndex = i;

		int l = leftChild(i);
		if (l < _data.size() && _data[l] > _data[maxIndex]) {
			maxIndex = l;
		}

		int r = rightChild(i);
		if(r < _data.size() && _data[r] > _data[maxIndex]) {
			maxIndex = r;
		}

		if(i != maxIndex) {
			std::swap(_data[i], _data[maxIndex]);
			shiftDown(maxIndex);
		}
	}

	void insert(long p) {
		_data.push_back(p);
		shiftUp(_data.size()-1);

		std::cout << "after insert:" << display(_data) << std::endl;
	}

	long extraceMax() {
		int result = _data.front();
		std::swap(_data[0], _data[_data.size()-1]);
		_data.pop_back();
		shiftDown(0);
		return result;
	}

	long remove(int i) {
		_data[i] = LONG_MAX;
		shiftUp(i);
		return extraceMax();
	}

	void changePriority(int i, long p) {
		long old_p = _data[i];
		_data[i] = p;

		if(p > old_p) {
			shiftUp(i);
		} else {
			shiftDown(i);
		}
	}

	std::vector<long>& getData() {
		return _data;
	}

private:
	std::vector<long> _data;
};


void HeapSort(std::vector<long>& A) {
	Heaps aHeap = Heaps();

	for(auto a : A) {
		aHeap.insert(a);
	}

	for(int i=A.size(); i>=0; --i) {
		A[i-1] = aHeap.extraceMax();
	}
}


int main() {

	std::vector<long> A = {11, 42,  7, 18, 14, 18, 29 ,12, 13};

	std::cout << "original data:" << display(A) << std::endl;

	HeapSort(A);

	std::cout << "after sort: " << display(A) << std::endl;

	return 0;
}
