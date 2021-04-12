/*
 * count_complete_tree_nodes.cpp
 *
 *  Created on: Jul 31, 2018
 *      Author: liuyanan
 */


/*
	给出一个完全二叉树，求出该树的节点个数。
	说明：
		完全二叉树的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第 h 层，则该层包含 1~ 2h 个节点。

	示例:
		输入:
				1
			   / \
			  2   3
			 / \  /
			4  5 6

		输出: 6


	思路：这个题目，一开始的想法就是遍历以下就得出结果来了，时间复杂度是 O(n) ,
 */


#include <iostream>
#include <stdlib.h>
#include <stack>
#include <queue>
#include <cmath>


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

Node* getTestTree() {
	Node* node1 = createNode(1);
	Node* node2 = createNode(2);
	Node* node3 = createNode(3);
	Node* node4 = createNode(4);
	Node* node5 = createNode(5);
	Node* node6 = createNode(6);
	Node* node7 = createNode(7);
	Node* node8 = createNode(8);
	Node* node9 = createNode(9);
	Node* node10 = createNode(10);
	Node* node11 = createNode(11);
	Node* node12 = createNode(12);
	Node* node13 = createNode(13);

	buildTree(node1, node2, node3);
	buildTree(node2, node4, node5);
	buildTree(node3, node6, node7);
	buildTree(node4, node8, node9);
	buildTree(node5, node10, node11);
	buildTree(node6, node12, node13);

	return node1;
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

	cout << endl;
}


int BruteForceCount(Node* tree)
{
	if(!tree)
		return 0;
	return BruteForceCount(tree->left) + BruteForceCount(tree->right) + 1;
}

int mostLeftLevel(Node* tree)
{
	if(!tree)
		return 0;

	return mostLeftLevel(tree->left) + 1;
}

int mostRightLevel(Node* tree)
{
	if(!tree)
		return 0;

	return mostRightLevel(tree->right) + 1;
}

int EffectiveCount(Node* tree)
{
	if(!tree)
		return 0;

	int level_l = mostLeftLevel(tree);
	int level_r = mostRightLevel(tree);

	if(level_l == level_r) {
		return pow(2, level_l) - 1;
	}

	return EffectiveCount(tree->left) + EffectiveCount(tree->right) + 1;
}

int EffectiveCount_2(Node* tree)
{
	/*
	 *  https://blog.csdn.net/zjucor/article/details/72229076
	 *
	 *	先求树高 L， 再求root->right的树高 Lr，
	 *
	 *	1. 若 Lr = L-1, 则 root->left 是高度为 L-1 的满二叉树
	 *		f(root) = 2^(L-1) - 1 + 1 + f(root->right)
	 *
	 *  2. 若Lr = L-2, 则 root->right 是满二叉树，高度为L-2
	 *  	f(root) = 2^(L-2) - 1 + 1 + f(root->left)
	 *
	 *  复杂度：
	 *  	F(N) = logN + F(N/2)
	 *  	F(N) = (logN)^2
	 */

	if(!tree)
		return 0;

	int level = mostLeftLevel(tree);
	int level_r = mostLeftLevel(tree->right);

	if(level == level_r + 1) {
		return pow(2, level-1) - 1 + 1 + EffectiveCount_2(tree->right);
	}

	if(level == level_r + 2) {
		return pow(2, level-2) - 1 + 1 + EffectiveCount_2(tree->left);
	}
}


int main(int argc, char **argv) {

	Node* tree = getTestTree();
	output(tree);
	cout << "tree count: " << BruteForceCount(tree) << endl;
	cout << "tree count: " << EffectiveCount(tree) << endl;
	cout << "tree count: " << EffectiveCount_2(tree) << endl;

	return 0;
}
