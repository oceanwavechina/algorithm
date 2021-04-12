/*
 * merge_sorted_linklist.cpp
 *
 *  Created on: Apr 2, 2018
 *      Author: liuyanan
 */


#include <iostream>
#include <vector>
#include <string>

using namespace std;


/*
 *	两个有序链表的合并
 *		递归和非递归的方式
 */

struct Node{

	Node(int _data):data(_data), next(nullptr) {}

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


Node * merge(Node* A, Node* B) {

	/*
	 *	需要注意的点
	 *		1. 一般对链表操作，需要保存头节点，如果p_i当成最后的链表，那么结果链表是错误的
	 *		2. 需要搞明白，每一步都有哪些指针需要移动
	 */

	Node* p_a = A;
	Node* p_b = B;
	Node* p_i = nullptr;
	Node* p_c = nullptr;

	while(p_a && p_b) {

		if (p_a->data < p_b->data) {

			if (! p_c)
				p_c = p_a;

			if (p_i) {
				p_i->next = p_a;
			}
			p_i = p_a;
			p_a = p_a->next;

		} else {

			if (! p_c)
				p_c = p_b;

			if (p_i) {
				p_i->next = p_b;
			}
			p_i = p_b;
			p_b = p_b->next;
		}
	}

	if(p_a) {
		p_i->next = p_a;
	}

	if (p_b) {
		p_i->next = p_b;
	}

	return p_c;
}


Node* merge_recur(Node* A, Node* B) {
	/*
	 * 	理解递归调用时，要想象一步一步的压栈调用才能明白。。。
	 * 	这样想把：
	 * 		1. 栈里边的每一层，包含哪些传入参数，每一层返回的值应该是要有什么特点
	 * 		2. 最后一个要注意的是，栈定的调用，应该返回什么
	 * 		3. 从栈顶到栈底的执行过程中
	 * 			上一层的返回值是下一层的参数
	 * 		4. 所以递归调用执行过程：是逆向的从结尾到开始的方式
	 */

	if (!A)
		return B;
	if (!B)
		return A;

	Node* merge_head = nullptr;

	if(A->data < B->data){
		merge_head = A;
		merge_head->next = merge_recur(A->next, B);
	} else {
		merge_head = B;
		merge_head->next = merge_recur(A, B->next);
	}

	return merge_head;
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

	vector<int> data_A = { 1, 3, 5};
	vector<int> data_B = { 2, 4, 6, 8, 10};

	Node* list_A = create_list(data_A);
	Node* list_B = create_list(data_B);
	display(list_A, "list A:");
	display(list_B, "list B:");

	//Node* list_C = merge(list_A, list_B);
	Node* list_C = merge_recur(list_A, list_B);
	display(list_C, "list C:");

	return 0;
}
