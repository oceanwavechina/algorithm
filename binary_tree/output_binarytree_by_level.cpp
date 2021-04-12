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


	// 按行打印时用
	int depth;
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
	if (! root)
		return;

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
		//delete current;
	}
}

void output_with_return(Node* root)
{
	if (! root)
		return;

	g_queue.push(root);

	/*
	 * 输出换行，方法是记录每层的个数。
	 * 1. 每输出一个元素就把这个个数减 1， 当这个数是 0 的时候，这一层就输出完了，打印一个换行
	 * 2. 在每次入队孩子的时候，记录下一行的个数。
	 * 3. 当前层输出完了，把下一层的计数器复制到当前行的计数器上，然后下一层的计数器清零，重新计数
	 */
	int cur_level_cnt = 1;
	int next_level_cnt = 0;

	while( ! g_queue.empty() ) {

		Node* current = g_queue.front();
		cout << current ->value << '\t';

		--cur_level_cnt;
		if(cur_level_cnt == 0) {
			cout << endl;
		}
		g_queue.pop();
		if(current->left) {
			g_queue.push(current->left);
			++next_level_cnt;
		}
		if (current->right) {
			g_queue.push(current->right);
			++next_level_cnt;
		}
		//delete current;

		if(cur_level_cnt == 0) {
			cur_level_cnt = next_level_cnt;
			next_level_cnt = 0;
		}
	}
}

void output_with_return_2(Node* root)
{
	if (! root)
		return;

	root->depth = 1;	// 第一层
	g_queue.push(root);

	/*
	 * 输出换行，修改 Node 节点
	 */

	// 记录当前深度，初始值和root->depth相同
	int cur_depth = 1;

	while( ! g_queue.empty() ) {

		Node* cur_node = g_queue.front();
		if(cur_depth != cur_node->depth) {
			// 当前节点的深度和打印深度不同时需要打印换行
			cout << endl;
			++cur_depth;
		}
		cout << cur_node ->value << '\t';

		g_queue.pop();
		if(cur_node->left) {
			cur_node->left->depth = cur_depth+1;
			g_queue.push(cur_node->left);

		}
		if (cur_node->right) {
			cur_node->right->depth = cur_depth+1;
			g_queue.push(cur_node->right);
		}
		//delete current;
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

	cout << endl  << "output:" << endl;
	inOrderTraverse(node10);

	output(node10);
	cout << endl  << "output with return:" << endl;
	output_with_return(node10);

	cout << endl  << "output with return2:" << endl;
	output_with_return_2(node10);
}
