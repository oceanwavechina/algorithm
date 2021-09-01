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
	 玩法是这样的：
	  	  我们通过比较 A，B，每次从其中拿最小的元素放到 C 的尾部，当 A(或B) 被拿掉一个后，其对应的游标则向后移动

	 需要注意的点
	 	 1. 一般对链表操作，需要保存头节点，如果p_i当成最后的链表，那么结果链表是错误的
	 	 2. 需要搞明白，每一步都有哪些指针需要移动
	 */

	Node* p_cursor_a = A;
	Node* p_cursor_b = B;

	Node* p_c_head = nullptr;		// C 链表的头节点
	Node* p_c_tail = nullptr;		// C 链表的尾节点

	while(p_cursor_a && p_cursor_b) {

		if (p_cursor_a->data < p_cursor_b->data) {

			if (! p_c_head)
				p_c_head = p_cursor_a;

			if (p_c_tail) {
				p_c_tail->next = p_cursor_a;
			}
			p_c_tail = p_cursor_a;
			p_cursor_a = p_cursor_a->next;

		} else {

			if (! p_c_head)
				p_c_head = p_cursor_b;

			if (p_c_tail) {
				p_c_tail->next = p_cursor_b;
			}
			p_c_tail = p_cursor_b;
			p_cursor_b = p_cursor_b->next;
		}
	}

	if(p_cursor_a) {
		p_c_tail->next = p_cursor_a;
	}

	if (p_cursor_b) {
		p_c_tail->next = p_cursor_b;
	}

	return p_c_head;
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


#if 0
	//
	// 如下的这种方式理解递归不好理解的话，我们把代码拆细点就可以了
	//
	Node* merge_head = nullptr;

	if(A->data < B->data){
		merge_head = A;
		merge_head->next = merge_recur(A->next, B);
	} else {
		merge_head = B;
		merge_head->next = merge_recur(A, B->next);
	}

	return merge_head;
#else

	//
	//	这里的递归是因为各种顺序都用到了
	//

	Node* p_cursor_c = nullptr;

	if(A->data < B->data) {

		// 这里算是先序操作了，先确定当前的头
		p_cursor_c = A;

		Node* p_next = merge_recur(A->next, B);

		// 这里算是后续操作了，把子函数的的返回值保存
		p_cursor_c->next = p_next;
	} else {
		p_cursor_c = B;

		Node* p_next = merge_recur(A, B->next);

		p_cursor_c->next = p_next;
	}

	return p_cursor_c;
#endif

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
