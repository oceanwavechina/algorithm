/*
 * BinaryTree_Traversing.cpp
 *
 *  Created on: Nov 24, 2016
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

	return node10;
}

void inOrderTraverse(Node* root)
{
	if (root == NULL) {
		return ;
	}

	if (root->left != NULL) {
		inOrderTraverse(root->left);
	}

	cout << root->value << '\t';

	if (root->right != NULL) {
		inOrderTraverse(root->right);
	}
}

void preOrderTraverse(Node* root) {
	if (root == NULL) {
		return ;
	}

	cout << root->value << '\t';

	if (root->left) {
		preOrderTraverse(root->left);
	}

	if (root->right) {
		preOrderTraverse(root->right);
	}
}

void postOrderTraverse(Node* root) {
	if(root == NULL) {
		return ;
	}

	if (root->left) {
		postOrderTraverse(root->left);
	}

	if (root->right) {
		postOrderTraverse(root->right);
	}

	cout << root->value << '\t';
}


void PreOrder2_With_Stack(Node* root) {
	Node* node = root;

	stack<Node*> _stack;

	while( node || !_stack.empty() ) {
		if (node) {
			cout << node->value << '\t'; 	// 输出
			_stack.push(node);				// 压栈
			node = node->left;				// 遍历左子树
		} else {
			node = _stack.top();
			_stack.pop();
			node = node->right;
		}
	}
}

void InOrder2_With_Stack(Node* root) {
	Node* node = root;

	stack<Node*> _stack;

	while( node || !_stack.empty() ) {
		if (node) {
			_stack.push(node);			// 父节点压栈
			node = node->left;			// 遍历左子树
		} else {
			node = _stack.top();
			cout << node->value << '\t'; 	// 输出父节点

			node = node->right;				//遍历右子树

			_stack.pop();
		}
	}
}


int main()
{
	Node* root = getTestTree();

	cout << "pre order traverse: ";
	preOrderTraverse(root);
	cout << endl;;

	cout << "in order traverse: ";
	inOrderTraverse(root);
	cout << endl;;

	cout << "post order traverse: ";
	postOrderTraverse(root);
	cout << endl;;

	cout << "post order (without recursive) traverse: ";
	PreOrder2_With_Stack(root);
	cout << endl;;

	cout << "in order (without recursive) traverse: ";
	InOrder2_With_Stack(root);
	cout << endl;;

}
