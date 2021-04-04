/*
 * bucket_sort.cpp
 *
 *  Created on: Apr 4, 2021
 *      Author: liuyanan
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/*
  桶排序：
  	  算法导论 8.4

  	  这个算法对输入的序列有个要求，就是数据要均匀的分布到各个通里边
  	  (Note: 是否有办法，可以把一组分布不均匀的数据，通过某种hash过程后，变成均匀的 ？？
  	  	  是否可以 结合 jump-consistent-hashing 的思想，我们可以数据分布的均匀性用生成随机数的的均匀性 来代替 数据原有的均匀性
  	  这样我们就不依赖元数据是否是均匀的了？？？)
	  上述这个想法应该是行不通的，原因如下:
		  决定的元素在各个桶的分布，是由元素大小决定的，所以我们不太能找到一个hash函数来做均匀映射
		  因为待排序数据的分布是无法预知 且 已经固定了的
		  能想到的办法也就是预估数据的分布，来调整通的个个数，比如这个例子的数据集，5个桶要比10个桶分布的更均匀
 */

template <typename T>
struct LNode {

	LNode(T _data): data(_data), next(nullptr) {
	}

	T data;
	LNode* next;

	bool operator <= (const LNode& other) {
		return data <= other.data;
	}
};


template <typename T>
class OrderedLinklist {
public:
	OrderedLinklist(): _p_head(nullptr) {
	}

public:
	void insert(LNode<T>* p_node) {
		if(!p_node) {
			cerr << "insert_error: nullptr" << endl;
			return;
		}

		//  链表为空的情况
		if(!_p_head) {
			_p_head = p_node;
		} else {
			LNode<T>* p_traverser = _p_head;

			// 遍历整个链表找到p_node 的位置
			while(p_traverser) {

				// 找到了 p_node 的位置
				if(*p_node <= *p_traverser) {

					cout << "put:" << p_node->data << " before " << p_traverser->data << endl;

					// 交换元素，然后 p_traverser 的next 指向p_node
					// 这样p_node就在 p_traverser 的前边了，且不用管_p_head

					T tmp = p_node->data;
					p_node->data = p_traverser->data;
					p_traverser->data = tmp;

					// 插入到链表中
					p_node->next = p_traverser->next;
					p_traverser->next = p_node;

					break;

				} else {

					if(!p_traverser->next) {
						// p_traverser 是最后一个节点, 只需要把 p_node 放在最后
						p_traverser->next = p_node;
						break;

					} else {
						p_traverser = p_traverser->next;
					}
				}
			}
		}
	}

	LNode<T>* get_all() {
		return _p_head;
	}


private:
	LNode<T>* _p_head;
};


template <typename T>
class BucketSort {
public:
	BucketSort(size_t size = 5){
		_buckets.resize(size);
	}

	void sort(const vector<T>& items) {

		for(auto item : items) {

			//
			// NOTE:
			//	1. item 与 哪个桶的映射关系
			// 		选一个bucket, 这里用 除法是可以的， 但是用模除就不行了
			// 		因为排序通的要领是通本身是从小到大有序的，桶里的元素也是从小到大有序的
			// 		如果用 mod (模除) 的话，可能大的元素反而跑到小桶里边去了
			//
			//	2. 在用除法计算桶的映射关系时，通过调整 bucket 个数，可以看到元素在不同桶的分布情况
			//		最佳的情况是元素均匀的分布到各个通里边，又因为桶本身是有序的，
			//		所以决定的元素在各个桶的分布，是由元素大小决定的，所以我们不太能找到一个hash函数来做均匀映射
			//		因为待排序数据的分布是无法预知 且 已经固定了的
			//		能想到的办法也就是预估数据的分布，来调整通的个个数，比如这个例子的数据集，5个桶要比10个桶分布的更均匀
			//

			// int pos = item % _buckets.size();	// ERROR
			int pos = item / _buckets.size();
			if(pos >= _buckets.size()) {
				pos = _buckets.size() - 1;
			}

			_buckets[pos].insert(new LNode<T>(item));
		}

		cout << "after sort: \n";
		vector<T> sorted;
		for(size_t i=0; i<_buckets.size(); ++i) {

			cout << "\t bucket " << i << ": ";
			LNode<T>* p_node = _buckets[i].get_all();
			while(p_node) {
				cout << p_node->data << "\t";
				p_node = p_node->next;
			}
			cout << endl;
		}
	}

private:
	vector< OrderedLinklist<T> > _buckets;
};


int main(int argc, char **argv)
{
	BucketSort<int> bucket_sorter;

	vector<int> unordered_elements = {6, 4, 8, 100, 2, 9, 30, 29, 88, 71, 3, 44, 82, 2, 17, 33, 12, 18, 9, 4, 7, 6, 1};

	bucket_sorter.sort(unordered_elements);

	return 0;
}

