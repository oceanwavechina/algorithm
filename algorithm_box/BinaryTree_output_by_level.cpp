/*
 * BinaryTree_2_LinkList_with_queue.cpp
 *
 *  Created on: Nov 21, 2016
 *      Author: liuyanan
 */


/*
 *	题目：输入一棵二叉搜索树，按层级输出
 *
 *		 10
 *		/  \
 *	   6    14
 *	  / \   / \
 *	 4   8 12 16
 *
 *	10	6	14	4	8	12	16
 *
 */

#include <iostream>
#include <stdlib.h>
#include <queue>

using namespace std;

struct Node
{
	Node(int v):value(v), left(NULL), right(NULL) {}
	~Node() {}

	int value;
	Node* left;
	Node* right;
};

static queue<Node *> g_queue;

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

void inOrderTraverse(Node* root)
{
	if (root != NULL) {
		if (root->left != NULL) {
			inOrderTraverse(root->left);
		}
		cout << "value of node is: " << root->value << endl;

		if (root->right != NULL) {
			inOrderTraverse(root->right);
		}
	} else {
		cout  << "node is null." << endl;
	}
}

void output(Node* root)
{
	g_queue.push(root);

	while( ! g_queue.empty() ) {
		Node* current = g_queue.front();
		cout << current ->value << '\t';
		g_queue.pop();
		if(current->left) {
			g_queue.push(current->left);
		}
		if (current->right) {
			g_queue.push(current->right);
		}
		delete current;
	}
}


int main()
{
	Node* node10 = createNode(10);
	Node* node6 = createNode(6);
	Node* node14 = createNode(14);
	Node* node4 = createNode(4);
	Node* node8 = createNode(8);
	Node* node12 = createNode(12);
	Node* node16 = createNode(16);

	buildTree(node10, node6, node14);
	buildTree(node6, node4, node8);
	buildTree(node14, node12, node16);

	inOrderTraverse(node10);

	output(node10);

}
