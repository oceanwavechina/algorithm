/*
 * find_circle_entry.cpp
 *
 *  Created on: Sep 1, 2021
 *      Author: liuyanan
 */

#include <vector>
#include <iostream>
#include <sstream>

using namespace std;


/*
 两种方法
 	 一个是通过修改链表中的值，比如修改成一个极大(小) 值，当再次遍历回来的时候，就找到了
 	 另一个是通过公式计算

	比如 0 是这个环的

	10 -> 3 -> 2 -> 0 -> 4 -> 6 -> 9
				    ^			   |
				    |			   V
				    8 <- 5 <- 1 <- 7
							  ^
							 相遇
	我想用直观的理解说下:
		先用快慢两个指针，会在 1 这个地方相遇
		假设链表的开始就是入口的话，那相遇的地方就是入口，
		而此时是先走了一段时间才到入口，所以相遇的地方也就需要从入口回退这个距离
		所以从开始到入口，也就等于从相遇点到入口的距离
 */

struct Node {
	Node(int _val):val(_val), p_next(nullptr){}

	int val;
	Node* p_next;
};

Node* creat_list_with_circle(vector<int> data, int circle_start_pos) {

	/*
	 		3 -> 2 -> 0 -> 4 -> 6 -> 9
					  ^			     |
					  |			     V
					  8 <- 5 <- 1 <- 7
	 */

	Node *head = nullptr;
	Node *curNode = nullptr;
	Node *tmpNode = nullptr;

	int counter = 0;

	Node* circle_start = nullptr;
	Node* tail = nullptr;

	for(auto v : data) {
		tmpNode = new Node(v);
		if(curNode)
			curNode->p_next = tmpNode;
		curNode = tmpNode;

		if (!head)
			head = tmpNode;

		if(counter == circle_start_pos) {
			circle_start = tmpNode;
			cout << "circle start: " << circle_start->val << endl;
		}

		++counter;

		tail = tmpNode;
	}

	if(tail) {
		tail->p_next = circle_start;
	}

	return head;
}

void display_list(Node *head, int len) {

	cout << "list:";
	while(head && len-- > 0) {
		cout << head->val << " ";
		head = head->p_next;
	}
	cout << endl;
}


Node* find_entry(Node* list)
{
	if(! list) {
		return nullptr;
	}

	// 1. 先找到二者相遇的地方

	Node* fast = list;
	Node* slow = list;

	while (true) {

		if(!slow || !fast->p_next) {
			return nullptr;
		}

		slow = slow->p_next;
		fast = fast->p_next->p_next;

		if(slow->val == fast->val) {
			break;
		}
	}


	// 2. 从两个地方开始(链表开始 和 相遇的地方)， 一步一步往前，直到再次相遇
	//		第二次相遇的地方就是环的入口

	cout << "fast:" << fast->val << ", slow:" << slow->val << endl;
	fast = list;
	while(fast != slow) {
		fast = fast->p_next;
		slow = slow->p_next;
	}

	return fast;
}



int main(int argc, char **argv)
{
	Node* list = creat_list_with_circle({10, 3, 2, 0, 4, 6, 9, 7, 1, 5, 8}, 3);

	display_list(list, 10);

	Node* entry = find_entry(list);
	cout << "the entry is: " << (entry ? entry->val : -1 ) << endl;

	return 0;
}
