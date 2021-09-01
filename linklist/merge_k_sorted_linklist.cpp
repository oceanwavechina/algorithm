/*
 * merge_k_sorted_linklist.cpp
 *
 *  Created on: Apr 12, 2018
 *      Author: liuyanan
 */


#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;


/*
 	K个有序链表的合并

 	玩法是这样的：
 		把每个 list 头结点(如果有的话)，都放到一个 heap 里边，也就是用 heap 排序

 		需要注意的是，每次从 heap 里边拿走一个节点后，还要把这个节点的 next 压入 heap 中
 */

struct Node{

	Node(int _data):data(_data), next(nullptr) {}

	int operator<(const Node* &v) const {
		return this->data + v->data;
	}

	int data;
	Node* next;
};

Node* create_list(vector<int> nums){

	Node* head = nullptr;
	Node* tail = nullptr;

	for(auto num : nums) {
		Node* tmp = new Node(num);
		if(!head){
			head = tmp;
		}

		if(!tail) {
			tail = tmp;
		} else {
			tail->next = tmp;
			tail = tmp;
		}
	}

	return head;
}


/*
 * 因为堆中是结点的指针，所以要重新定义比较函数
 */
struct cmp {
	bool operator()(Node* a, Node* b){
		return a->data > b->data;
	}
};
using my_container_t = std::vector<Node*>;

Node * merge(vector<Node*> lists) {

	Node* p_X = nullptr;
	Node* p_curser = nullptr;
	priority_queue<Node*, my_container_t, cmp> heap;

	// init heap
	for(Node* head_node : lists) {
		if (head_node) {
			heap.push(head_node);
		}
	}

	cout << endl;

	// merge
	while( ! heap.empty() ) {
		Node* cur_top = heap.top();
		heap.pop();

		if(!p_X)
			p_X = cur_top;

		if (!p_curser)
			p_curser = cur_top;
		else {
			p_curser -> next = cur_top;
			p_curser = cur_top;
		}

		// 重点在这一句，上次从哪个队列取的；就还从那个队列中继续读取
		if (cur_top->next) {
			heap.push(cur_top->next);
		}
	}

	return p_X;
}

void display(Node* head, string msg) {

	cout << msg;

	while(head) {
		cout << head->data << "\t";
		head = head->next;
	}

	cout << endl << endl;
}


int main(int argc, char **argv) {

	vector<vector<int> > datum= {
			{ 1, 4, 7, 10, 13, 16},
			{ 2, 5, 8, 11, 14},
			{ 3, 6, 9, 12, 15, 17, 18}
	};
	vector<Node*> lists;

	for(auto data : datum) {
		Node* list = create_list(data);
		lists.push_back(list);
		display(list, "list:\t");
	}

	Node* list_C = merge(lists);
	display(list_C, "\nresult:\t");

	return 0;
}
