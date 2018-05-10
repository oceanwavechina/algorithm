/*
 * tree_depth.cpp
 *
 *  Created on: Feb 20, 2017
 *      Author: liuyanan
 */


#include <iostream>
#include <stdlib.h>
#include <stack>


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

int depth(Node* p) {

	if (!p)
		return 0;


	/*
	 * 深度是相对跟节点的，所以递归返回的时候，到跟节点就可以找到左右子树的最大值，也就是深度
	 */

	int left_len = depth(p->left);
	int right_len = depth(p->right);

	return max(left_len, right_len) + 1;
}

int main(int argc, char **argv) {

	cout << "tree depth:" << depth(getTestTree()) << endl;

	return 0;
}




