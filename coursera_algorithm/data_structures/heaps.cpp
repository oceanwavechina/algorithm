/*
 * heaps.cpp
 *
 *  Created on: Sep 22, 2016
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
	 * 序号 i 是从 1 开始的
	 */
public:
	Heaps(std::vector<long> data):_data(data) {};
	~Heaps() {};

public:
	long parent(int i) {
		return i/2;
	}

	long leftChild(int i) {
		return 2*i;
	}

	long rightChild(int i) {
		return 2*i + 1;
	}

	void shiftUp(int i) {
		while(i>1 && _data[parent(i)] < _data[i]) {
			std::swap(_data[parent(i)], _data[i]);
			i = parent(i);

			std::cout << "internal data:" << display(_data) << std::endl;
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
//		std::cout << "after push back data:" << display(_data) << std::endl;
		shiftUp(_data.size()-1);
	}

	long extraceMax() {
		int result = _data.front();
		_data.insert(_data.begin(), _data[_data.size()-1]);
		_data.erase(_data.end()-1);
		shiftDown(1);
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



int main() {
	// 序号 i 是从 1 开始的
	Heaps aHeap = Heaps({0, 42, 29, 18, 14, 7, 18, 12, 11, 13});

	std::cout << "original data:" << display(aHeap.getData()) << std::endl;

	std::cout << "position 4's parent: " << aHeap.parent(4) << std::endl;
	std::cout << "position 4's left child: " << aHeap.leftChild(4) << std::endl;
	std::cout << "position 4's right child: " << aHeap.rightChild(4) << std::endl;


	aHeap.insert(1);
	std::cout << "after insert 1:" << display(aHeap.getData()) << std::endl;

	aHeap.insert(100);
	std::cout << "after insert 100:" << display(aHeap.getData()) << std::endl;
	return 0;
}


