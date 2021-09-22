/*
 * sort_list.cpp
 *
 *  Created on: Sep 22, 2021
 *      Author: liuyanan
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <utility>

using namespace std;


/*
	在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。
	示例 1:
		输入: 4->2->1->3
		输出: 1->2->3->4

	示例 2:
		输入: -1->5->3->4->0
		输出: -1->0->3->4->5


	玩法是这样的：
		还是归并排序, 其实要点在split 那个地方
 */

struct Node{

	Node(int _data):val(_data), next(nullptr) {}

	int val;
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

void display(Node* head, string msg) {

	cout << msg;

	while(head) {
		cout << head->val << "\t";
		head = head->next;
	}

	cout << endl << endl;
}


void split(Node* list, Node** part1, Node** part2)
{
	/* 输入: -1->5->3->4->0
                   ^
                 slow

      难点在这里，实际上我们要找的slow 是中间节点的前一个。
      所以 fast 的起始是 list->next
	 */

	Node* slow = list;
	Node* fast = list->next;


	while(fast && fast->next) {
		fast = fast->next->next;
		slow = slow->next;
	}

	*part1 = list;
	*part2 = slow->next;
	slow->next = nullptr;	// 把链表断开
}

Node* merge(Node* pa, Node* pb)
{
	Node* pc = nullptr;
	Node* tail = nullptr;

	while(pa && pb) {
		if(pa->val < pb->val) {

			if(!pc) {
				pc = pa;
			}

			if(!tail) {
				tail = pa;
			} else {
				tail->next = pa;
				tail = tail->next;
			}

			pa = pa->next;

		} else {
			if(!pc) {
				pc = pb;
			}

			if(!tail) {
				tail = pb;
			} else {
				tail->next = pb;
				tail = tail->next;
			}

			pb = pb->next;
		}
	}

	if(pa) {
		tail->next = pa;
	}

	if(pb) {
		tail->next = pb;
	}

	return pc;
}

Node* merge_sort(Node* list)
{
	if(!list || !list->next) {
		return list;
	}

	Node* part1 = nullptr;
	Node* part2 = nullptr;

	// 递归中压栈前操作是把数据分成两部分
	split(list, &part1, &part2);

	Node* left = merge_sort(list);
	Node* right = merge_sort(part2);

	// 递归中压栈后操作是把数据排序合并
	return merge(left, right);
}


int main(int argc, char **argv) {

	vector<int> array = { 2, 1, 3, 4, 8, 7, 6, 9, 10};

	Node* list = create_list(array);
	display(list, "origin:\t");

	Node* sorted = merge_sort(list);
	display(sorted, "sorted:\t");

	return 0;
}
