/*
 * binary_tree_maximum_path_sum.cpp
 *
 *  Created on: Feb 22, 2017
 *      Author: liuyanan
 */




/*
 Question:
	Given a binary tree, find the maximum path sum. The path may start and end at any node in the tree.
	For example, given the below binary tree,

				1
			   / \
			  2   4
			 / \
			2   3

	The highlighted path yields the maximum sum 10.

 Hint:
	Anytime when you found that doing top down approach uses a lot of repeated calculation, bottom up approach usually is able to be more efficient.

 	 	 	 	 _____Node____
 	 	 	    / 			  \
 	 	 	   / 			   \
 	 	  left subtree 		right subtree

	Try the bottom up approach. At each node, the potential maximum path could be one of these cases:
		i. max(left subtree) + node
		ii. max(right subtree) + node
		iii. max(left subtree) + max(right subtree) + node
		iv. the node itself
		Then, we need to return the maximum path sum that goes through this node and to either one of its left or right subtree to its parent.
		There is a little trick here: If this maximum happens to be negative, we should return 0,
			which means: 鈥淒o not include this subtree as part of the maximum path of the parent node, which greatly simplifies our code.
 */



#include <iostream>
#include <stdlib.h>
#include <stack>
#include <cstdint>
#include <vector>


using namespace std;

struct Node
{
	Node(int v):value(v), left(NULL), right(NULL) {}
	~Node() {}

	int value;
	Node* left;
	Node* right;
};


Node* createNode(int value)
{
	return new Node(value);
}

void buildTree(Node* parent, Node* left, Node* right)
{
	if (parent != NULL) {
		parent->left = left;
		parent->right = right;
	}
}

Node* getTestTree() {

	/*
	 *
	 *			 10
	 *			/  \
	 *		   6    14
	 *		  / \   / \
	 *		 4   8 12 16
	 *		/
	 *	   9
	 *
	 */

	Node* node10 = createNode(10);
	Node* node6 = createNode(6);
	Node* node14 = createNode(14);
	Node* node4 = createNode(4);
	Node* node8 = createNode(8);
	Node* node12 = createNode(12);
	Node* node16 = createNode(16);
	Node* node9 = createNode(4);

	buildTree(node10, node6, node14);
	buildTree(node6, node4, node8);
	buildTree(node14, node12, node16);

	return node10;
}


int find_max(Node* p) {
	if(!p)
		return 0;

	int left = find_max(p->left);
	int right = find_max(p->right);

	// 或是全局变量
	static int g_maxSum = max(p->value + left + right, g_maxSum);

	int ret = p->value + max(left, right);

	return ret > 0 ? ret : 0;
}

int find_max_using_stack(Node* p) {

	if(!p)
		return 0;

	static int max_sum = INT_MIN;
	stack<Node*> _stack;
	int stack_sum = 0;

	// 先压栈
	Node* tmp_node = tmp_node;
	while(tmp_node) {
		_stack.push(tmp_node);
		stack_sum += tmp_node->value;
		tmp_node  = tmp_node->left;
	}
	max_sum = stack_sum;

	//
	while(!_stack.empty()) {
		Node* top = _stack.top();
		_stack.pop();
		if(top->right)
	}

}



int main(int argc, char **argv) {

	Node* p = getTestTree();

	cout << "max tree path sum: " << find_max(p) << endl;

	return 0;
}
