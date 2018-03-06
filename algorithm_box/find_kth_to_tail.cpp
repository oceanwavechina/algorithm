/*
 * find_kth_to_tail.cpp
 *
 *  Created on: Feb 24, 2018
 *      Author: liuyanan
 */

#include <vector>
#include <iostream>

using namespace std;

struct Node {

	Node(int _val):val(_val), p_next(nullptr){}

	int val;
	Node* p_next;

};

Node* creat_list(vector<int> data) {

	Node *head = nullptr;
	Node *curNode = nullptr;
	Node *tmpNode = nullptr;

	for(auto v : data) {
		tmpNode = new Node(v);
		if(curNode)
			curNode->p_next = tmpNode;
		curNode = tmpNode;

		if (!head)
			head = tmpNode;
	}

	return head;
}

void display_list(Node *head) {

	cout << "list:";
	while(head) {
		cout << head->val << " ";
		head = head->p_next;
	}
	cout << endl;
}


Node* find_kth_to_tail(Node* head, unsigned k) {

	if (! head)
		return NULL;

	Node* first = head;
	Node* second = head;

	unsigned interval = 0;

	if (k > 0) {
		while (second->p_next && interval != k-1) {
			second = second->p_next;
			++interval;
		}

		if (interval != k-1) {
			return nullptr;
		}
	}

	cout << "interval:" << interval << endl;

	while (second && second->p_next) {
		second = second->p_next;
		first = first->p_next;
	}

	return first;
}


int main(int argc, char **argv) {

	//Node* mylist = creat_list({1, 2});
	Node* mylist = creat_list({1, 2, 3, 4, 5, 6,7 ,8, 9});

	display_list(mylist);

	int k = 3;
	Node* target = find_kth_to_tail(mylist, k);

	if(target) {
		cout << k << "th to tail:" << target->val << endl;
	}

	return 0;
}
