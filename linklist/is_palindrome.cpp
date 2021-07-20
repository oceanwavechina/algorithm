/*
 * is_palindrome.cpp
 *
 *  Created on: Jul 20, 2021
 *      Author: liuyanan
 */

#include <iostream>
#include <vector>

using namespace std;

/*
  	  问题：
  	  	  给定一个单链表，判断它是不是回文 (即，从前往后读 和 从后往前读 是一样的)
  	  	  要求 空间复杂度O(1) 时间复杂度O(n)

  	  玩法是这样的：
		 这里会对链表做修改
		 	 1. 先对前半部分的链表进行翻转
		 	 	 问题是如何确定前半部分，两种方法：
		 	 	 	 1.1 遍历一遍确定链表的长度
		 	 	 	 1.2 利用快慢指针
		 	 2. 之后两个指针从中间向两边移动判断
 */

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

bool is_palindrome_with_getlen(Node* list)
{
	if(!list) {
		return false;
	}

	// 获取长度
	int len = 0;
	Node* p_cursor = list;
	while(p_cursor) {
		len += 1;
		p_cursor = p_cursor->p_next;
	}

	// 翻转前半部分
	Node* pre = nullptr;
	Node* cur =  list;
	int half = len / 2;
	while(half-- > 0) {

		// 保存cur的next域，要不链表就断了
		Node* next = cur->p_next;

		// 指针翻转
		cur->p_next = pre;

		// 向前移动
		pre = cur;
		cur = next;
	}

	// 这里要注意下，
	//	如果链表是偶数个，那cur就是后一半的第一个，
	Node* rear = cur;
	if(len % 2 == 1) {
		rear = cur->p_next;
	}

	// 开始比较
	while(pre && rear) {
		if(pre->val != rear->val) {
			return false;
		}

		pre = pre->p_next;
		rear = rear->p_next;
	}

	return true;
}

bool is_palindrome_with_fastslowpointer(Node* list)
{
	if(!list) {
		return false;
	}

	//
	// 这里的玩法是用两个指针，其中一个前进的速度是另一个两倍
	// 慢的那个负责翻转前一半，快的那个负责探底
	//

	// 这俩负责翻转
	Node* cur = list;
	Node* pre = nullptr;

	// 这个是快指针，负责判断链表结尾
	Node* fast_cursor = list;

	// 开始翻转前半部分
	while(1) {

		if(!fast_cursor->p_next) {
			// 这个是偶数的情况
			cout << "even:" << cur->val << endl;
			break;
		}

		if(!fast_cursor->p_next->p_next) {
			// 这个是奇数的情况
			cout << "odd:" << cur->val << endl;

			break;
		}

		fast_cursor = fast_cursor->p_next->p_next;

		Node* next = cur->p_next;
		cur->p_next = pre;
		pre = cur;
		cur = next;
	}

	display_list(cur);

	cout << "pre:" << pre->val << ", cur:" << cur->val << endl;

	// 当是偶数的时候，cur要特殊处理下
	if(fast_cursor->p_next == nullptr) {
		cur = cur->p_next;
	}

	// 开始判断
	while(pre && cur) {
		if(pre->val != cur->val) {
			return false;
		}

		pre = pre->p_next;
		cur = cur->p_next;
	}

	return true;
}


int main(int argc, char **argv) {

	Node* list = creat_list({1, 2, 3, 4, 5, 4, 3, 2, 1});

	display_list(list);

	//bool is_palindrome = is_palindrome_with_getlen(list);
	bool is_palindrome = is_palindrome_with_fastslowpointer(list);

	cout << "the list is palindrome: " << is_palindrome << endl;

	display_list(list);

	return 0;
}
