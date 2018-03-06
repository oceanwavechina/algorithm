/*
 * linklist_reverse.cpp
 *
 *  Created on: Nov 22, 2016
 *      Author: liuyanan
 */



#include <iostream>
#include <vector>

using namespace std;


struct Node{
	int value;
	Node* p_next;
};


Node* construct_linklist(vector<int> values)
{
	Node* head  = NULL;
	Node* tmp =  NULL;

	for(auto value : values) {
		Node* new_node = new Node;
		new_node->value = value;
		new_node->p_next = NULL;

		// add to the list
		if (tmp) {
			tmp -> p_next = new_node;
		} else {
			head = new_node;
		}

		tmp = new_node;
	}

	return head;
}


/*
	pre		 cur    next
	 |		  |		 |
	 V		  V		 V
	 NULL ->	 HEAD -> X -> X -> X -> TAIL

    这个题，找清楚上述三个位置就好，搞明白如何把头节点一般化处理
 */

Node* reverse(Node* head)
{
	if (!head) {
		cerr << "empty linklist when reverse" << endl;
	}

	Node* p_reverse_head = NULL;
	Node* pre = NULL;
	Node* cur = head;
	Node* next = NULL;

	while(cur) {
		 next = cur->p_next;		// 这个是保存 cur->p_next

		if (next == NULL)
			p_reverse_head = cur;

		cur->p_next = pre;

		pre = cur;
		cur = next;
	}

	return p_reverse_head;
}


void output_linklist(Node* head) {

	if ( !head ) {
		cerr << "empty linklist" << endl;
	}

	Node *tmp = head;
	while(tmp) {
		cout << tmp->value << '\t';
		tmp = tmp->p_next;
	}

	cout << endl;
}


int main()
{

	Node* list = NULL;

	list = construct_linklist({1, 2, 3, 4, 5, 6, 7, 8});

	output_linklist(list);

	list = reverse(list);

	output_linklist(list);

	return 0;
}
