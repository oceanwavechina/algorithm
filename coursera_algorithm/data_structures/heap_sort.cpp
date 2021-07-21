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


/*
 	 一、 堆的定义：
 	 	 1. 堆是一个完全二叉树
 	 	 2. 大根堆中, 任意一个节点都大于等于它的子节点
 	 	 	小根堆中, 任意一个节点都小于等于它的子节点

 	 	 所以堆是一个递归定义的结构


  	  二、 基于数组的堆的实现原理
		  示例:
                    [1]
                  /    \
                [2]     [3]
              /    \    /
            [4]   [5] [6]

		  如 上图所示, 其中的数字是堆中元素的序号(也就是在数组中存储时的下标)，也就是从顶到底，从左到右依次编号，有了这样的逻辑，我们就有如下的关：

		  假设 x 是存放所有元素的数组; x[i] 表示下标为 i 的元素,

			1. x[i] 的 父节点 为 x[i/2]， 这里的 i/2 是向下取整
				比如 下标为 2 的 父节点 是  2/2=1;
					下标为 3 的 父节点 也是 3/2=1

			2. x[i] 的左孩子为 x[i*2]， x[i] 的右孩子为 x[i*2+1]
				比如 下标为 2 的 左孩子的序号是 2*2 = 4
				    下标为 2 的 右孩子的序号是 2*2+1 = 5

		** NOTE: 这里的关系是下标从 1 开始的， 不是从 0 开始的 **
 */

class MaxHeap {
	/*
	 * 序号 i 是从 1 开始的
	 */
public:
	~MaxHeap() {
		_array.push_back(0);
	};

public:

	// 下面这3个方法可以实现层级的遍历
	long parent(int pos) {
		return std::floor(pos/2);
	}

	long leftChild(int pos) {
		return 2*pos;
	}

	long rightChild(int pos) {
		return 2*pos + 1;
	}

	void shiftUp(int pos) {
		//
		//	这个是把元素从下往上移动
		//		最后一个元素(一般是新插入)上移到合适的位置
		//
		while(pos>0 && _array[parent(pos)] < _array[pos]) {
			std::swap(_array[parent(pos)], _array[pos]);
			pos = parent(pos);
		}
	}

	void shiftDown(int pos) {
		//
		//	这个是把元素从上往下移动
		//	移动原则：
		//		因为是大根堆，父节点最大，所以调整后的父节点是 {父节点，左孩子，右孩子} 三者中最大的那个
		//		所以我们要先找到最大的那个节点 max, 如果 max 不是父节点，那就需要跟父节点交换
		//		否则就结束返回
		//
		int maxIndex = pos;

		int l = leftChild(pos);
		if (l < _array.size() && _array[l] > _array[maxIndex]) {
			maxIndex = l;
		}

		int r = rightChild(pos);
		if(r < _array.size() && _array[r] > _array[maxIndex]) {
			maxIndex = r;
		}

		if(pos != maxIndex) {
			std::swap(_array[pos], _array[maxIndex]);
			shiftDown(maxIndex);
		}
	}

	void insert(long val) {
		_array.push_back(val);
		shiftUp(_array.size()-1);

		std::cout << "after insert:" << display(_array) << std::endl;
	}

	long extraceMax() {
		//
		//	注意这里的技巧是把最后一个元素(较小的那个)，跟第一个元素(最大的)交换
		//		然后把小元素下沉
		//
		int result = _array.front();
		std::swap(_array[0], _array[_array.size()-1]);
		_array.pop_back();
		shiftDown(0);
		return result;
	}

	long remove(int pos) {
		_array[pos] = LONG_MAX;
		shiftUp(pos);
		return extraceMax();
	}

	void changePriority(int pos, long val) {
		long old_p = _array[pos];
		_array[pos] = val;

		if(val > old_p) {
			shiftUp(pos);
		} else {
			shiftDown(pos);
		}
	}

	std::vector<long>& getData() {
		return _array;
	}

private:
	std::vector<long> _array;
};


void HeapSort(std::vector<long>& A) {
	MaxHeap aHeap = MaxHeap();

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
