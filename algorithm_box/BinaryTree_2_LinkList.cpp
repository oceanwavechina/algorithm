/*
 * BinaryTree_2_LinkList.cpp
 *
 *  Created on: Nov 20, 2016
 *      Author: liuyanan
 */


/*
 *	题目：输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
 *		要求不能创建任何新的结点，只能调整树中结点指针的指向。
 *		比如输入下图中左边儿茶搜索树，则输出转换后的排序双向链表。
 *
 *		 10
 *		/  \
 *	   6    14
 *	  / \   / \
 *	 4   8 12 16
 *
 *	4	6	8	10	12	14	16
 *
 */

#include <iostream>
#include <stdlib.h>

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


void convert(Node* node, Node** lastNodeInList)
{
	if (node == NULL)
		return ;

	// 就是一个中序遍历
	Node* current = node;
	if (current->left != NULL)
		convert(current->left, lastNodeInList);


	// 这个才是转换的过程: 结果是创建一个双向链表
	// 因为是基于中序遍历的, 这个过程就是： 1. 让右孩子的左指针指向父节点(current->left)		2. 让左孩子的右指针指向父节点(last->right)
	current -> left = *lastNodeInList;  // 主要是针对 current是右孩子：来指向它的父节点； 左孩子的值是不变的
	if((*lastNodeInList) != NULL)
		(*lastNodeInList) ->right = current;  // 主要是针对 current是父节点：让它的左孩子来指向current；
	*lastNodeInList = current;


	if (current->right != NULL)
		convert(current->right, lastNodeInList);
}

Node* convert(Node* root)
{
	Node* lastNodeInList = NULL;
	convert(root, &lastNodeInList);

	// 一直left 就可以回溯到head
	Node* head = lastNodeInList;
	while(head != NULL && head->left != NULL)
		head = head->left;

	return head;
}

void outputLinkList(Node* root)
{
	Node* pNode = root;
	while(pNode != NULL) {
		cout << pNode->value << '\t';
		pNode = pNode->right;
	}

	cout  << endl;
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

	Node* headOfList = convert(node10);
	outputLinkList(headOfList);

}
