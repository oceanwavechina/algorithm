/*
 * is_contain_circle.cpp
 *
 *  Created on: Aug 15, 2021
 *      Author: liuyanan
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


/*
	给定一个链表，判断链表中是否有环。

	如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。
	为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。
	如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。

	如果链表中存在环，则返回 true 。 否则，返回 false 。

	进阶：
		你能用 O(1)（即，常量）内存解决此问题吗？

	示例 1：

		3 -> 2 -> 0 -> 4
			 ^		   |
			 |	<-  <- V

		输入：head = [3,2,0,-4], pos = 1
		输出：true
		解释：链表中有一个环，其尾部连接到第二个节点。

	提示：
		链表中节点的数目范围是 [0, 10^4]
		-10^5 <= Node.val <= 10^5
		pos 为 -1 或者链表中的一个 有效索引 。
 */

struct Node {
	Node(int _val):val(_val), p_next(nullptr){}

	int val;
	Node* p_next;
};

Node* creat_list_with_circle(vector<int> data, int circle_start_pos) {

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

bool is_contain_circle_two_pointers(Node* list, int pos)
{
	/*
	 	 玩法是这样的：
	 	 	 有两个指针同时遍历，但是一个的速度是另一个 2 倍。如果有环的话，那二者会相遇。
	 */

	if(! list  || pos < 0) {
		return false;
	}

	Node* slow = list;
	Node* fast = list;

	while(fast && fast->p_next) {
		slow = slow->p_next;
		fast = fast->p_next->p_next;

		if(slow == fast) {
			return true;
		}
	}

	return false;
}

bool is_contain_circle_markup(Node* list, int pos)
{
	/*
	 	 玩法是这样的：
	 	 	 根据题中的提示，我们可以修改链表，即对遍历过的元素进行标记，也就是把value 修改成有效范围之外的一个值 x
	 	 	 当遇到list 中value 为 x时，说明转了一圈了。
	 */

	Node* p_cursor = list;

	const int INFINITE = 1000000;

	while(p_cursor) {
		if(p_cursor->val == INFINITE) {
			return true;
		} else {
			p_cursor->val = INFINITE;
		}

		p_cursor = p_cursor->p_next;
	}

	return false;
}


int main(int argc, char **argv) {

	Node* list = creat_list_with_circle({3, 2, 0, 4}, 1);

	display_list(list, 4);

	bool is_contain_circle = is_contain_circle_two_pointers(list, 1);
	cout << "is_contain_circle_two_pointers: " << is_contain_circle << endl;

	is_contain_circle = is_contain_circle_markup(list, 1);
	cout << "is_contain_circle_markup: " << is_contain_circle << endl;

	display_list(list, 4);

	return 0;
}
