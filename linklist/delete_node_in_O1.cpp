/*
 * delete_node_in_O1.cpp
 *
 *  Created on: Jul 13, 2021
 *      Author: liuyanan
 */

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;


/*
	Question:
		给定单向链表的头指针和一个节点指针， 定义一个函数在 O(1) 时间删除该节点。
 */


struct Node{
	int value;
	Node* p_next;
};


Node* construct_linklist(const vector<int>& values)
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
  一般而言，删除单链表中的一个节点，需要找到该节点的前驱节点。然后把前驱节点的 next 指向该节点的后继节点
  因为是单链表，所以会有一个遍历的过程

  这里有一个技巧就是，我们把下一个节点的内容复制到当前节点，然后删除后继节点
  但是要考虑，是否有后继节点，并且当前节点是不是头结点等特殊情况：
  	  1. 有后继节点（正常情况），复制后继节点到当前节点，然后删除后继
  	  2. 没有后继，且当前节点是头节点，那我们要把头节点置空，所以参数中的 p_list_head 是一个二级指针
  	  3. 没有后继，当前节点是尾节点(即没有后继节点), 此时删除该节点后，无法修改前驱节点的next值，所以需要遍历，找到该节点的前驱节点
 */

void delete_node(Node** pp_list_head, Node* p_node_tobe_deleted)
{
	if(! pp_list_head || ! p_node_tobe_deleted) {
		return ;
	}

	if(p_node_tobe_deleted->p_next) {
		// 有后继节点，正常删除

		cout << "deleting internal: " << p_node_tobe_deleted->value << endl;

		Node* p_tmp = p_node_tobe_deleted->p_next;

		p_node_tobe_deleted->value = p_node_tobe_deleted->p_next->value;
		p_node_tobe_deleted->p_next = p_node_tobe_deleted->p_next->p_next;

		delete p_tmp; p_tmp = nullptr;

	} else if(*pp_list_head == p_node_tobe_deleted){
		// 没有后继，且是头结点，那链表只有这一个节点了，则需要修改链表头指针

		cout << "deleting head: " << p_node_tobe_deleted->value << endl;

		delete p_node_tobe_deleted; p_node_tobe_deleted = nullptr;
		*pp_list_head = nullptr;

	} else {
		// 没有后继，且待删除的不是头节点, 那就需要遍历了

		cout << "deleting tail: " << p_node_tobe_deleted->value << endl;

		Node* p_cursor = *pp_list_head;

		while(p_cursor) {
			if(p_cursor->p_next == p_node_tobe_deleted) {
				break;
			}
			p_cursor = p_cursor->p_next;
		}

		p_cursor->p_next = p_node_tobe_deleted->p_next;

		delete p_node_tobe_deleted; p_node_tobe_deleted = nullptr;
	}
}


string output_linklist(Node* list) {
	stringstream ss;
	while(list) {
		ss << list->value;
		if (list->p_next)
			ss << "->";

		list = list->p_next;
	}

	return ss.str();
}

Node* get(Node* p_list, int idx)
{
	Node* p_cursor = p_list;

	while(idx > 0) {
		p_cursor = p_cursor->p_next;
		--idx;
	}

	return p_cursor;
}


int main(int argc, char **argv)
{
	Node* list = construct_linklist({1, 2, 3, 4, 5, 6, 7, 8});

	cout << "origin list: " << output_linklist(list) << endl;

	delete_node(&list, get(list, 0));
	cout << "after delete normal(1): " << output_linklist(list) << endl;

	delete_node(&list, get(list, 6));
	cout << "after delete tail(8): " << output_linklist(list) << endl;

	delete_node(&list, get(list, 3));
	cout << "after delete normal(5): " << output_linklist(list) << endl;

	delete_node(&list, get(list, 1));
	cout << "after delete normal: " << output_linklist(list) << endl;
	delete_node(&list, get(list, 1));
	cout << "after delete normal: " << output_linklist(list) << endl;
	delete_node(&list, get(list, 1));
	cout << "after delete normal: " << output_linklist(list) << endl;
	delete_node(&list, get(list, 1));
	cout << "after delete normal: " << output_linklist(list) << endl;

	delete_node(&list, get(list, 0));
	cout << "after delete head: " << output_linklist(list) << endl;

	return 0;
}
