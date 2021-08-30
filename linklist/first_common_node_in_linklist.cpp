/*
 * common_node_in_linklist.cpp
 *
 *  Created on: Feb 15, 2017
 *      Author: liuyanan
 */




#include <iostream>
#include <vector>
#include <sstream>

using namespace std;


struct Node {

	Node(int value):data(value), next(nullptr) {}
	~Node() {}

	int data;
	Node* next;
};

Node* build_linklist(vector<int> values) {

	Node* head = nullptr;
	Node* last_node = nullptr;

	for(auto value : values) {
		Node* tmp = new Node(value);
		if (!head) {
			head = tmp;
		}

		if ( ! last_node ) {
			last_node = tmp;
		} else {
			last_node->next  = tmp;
			last_node = tmp;
		}
	}

	return head;
}

Node* list_append(Node* list, Node* tail) {
	Node* head = list;

	if (! list) {
		return tail;
	}

	while(list->next) {
		list = list->next;
	}

	list->next = tail;

	return head;
}

string output_linklist(Node* list) {
	stringstream ss;
	while(list) {
		ss << list->data;
		if (list->next)
			ss << "->";

		list = list->next;
	}

	return ss.str();
}

int count(Node* head) {
	int count = 0;

	while(head) {
		++count;
		head = head->next;
	}

	return count;
}

Node* advance(Node* head, int steps) {
	while(head && steps-- !=0) {
		head = head->next;
	}

	return head;
}

Node* first_common_node(Node* A, Node* B) {
	int count_A = count(A);
	int count_B = count(B);

	if (count_A > count_B) {
		A = advance(A, count_A - count_B);
	} else {
		B = advance(B, count_B - count_A);
	}

	while(A && B) {
		if (A == B) {
			cout << "first common node's values is: " << A->data << endl;
			return A;
		}

		A = A->next;
		B = B->next;
	}

	return nullptr;
}

int main(int argc, char **argv) {

	Node* A = build_linklist({1, 2, 3, 4, 5, 6, 7});
	Node* B = build_linklist({21, 22, 23, 24, 25, 26});
	list_append(B, advance(A, 3));

	cout << "list A: " << output_linklist(A) << endl;
	cout << "list B: " << output_linklist(B) << endl;

	first_common_node(A, B);

	return 0;
}

