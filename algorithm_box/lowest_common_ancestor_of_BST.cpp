/*
 * lowest_common_ancestor_of_BST.cpp
 *
 *  Created on: May 15, 2018
 *      Author: liuyanan
 */

#include <iostream>
#include <tuple>
#include <assert.h>

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
	Node* node12 = createNode(12);
	Node* node5 = createNode(5);
	Node* node18 = createNode(18);
	Node* node2 = createNode(2);
	Node* node9 = createNode(9);
	Node* node15 = createNode(15);
	Node* node19 = createNode(19);
	Node* node17 = createNode(17);
	Node* node16 = createNode(16);

	buildTree(node12, node5, node18);
	buildTree(node5, node2, node9);
	buildTree(node18, node15, node19);
	buildTree(node15, nullptr, node17);
	buildTree(node17, node16, nullptr);

	return node12;
}


Node* getLowestCommonAncestor(Node* tree, int v1, int v2)
{
	int small = min(v1, v2);
	int big = max(v1, v2);

	Node* iterator = tree;

	while(iterator) {
		if( iterator->value < small) { // 在 iterator 的右孩子上
			iterator = iterator->right;
			continue;
		} else if(iterator->value > big) {	// 在iterator 的左孩子上
			iterator = iterator->left;
			continue;
		}

		// 好像不能判断某个值是不是在二叉树中
//		if (!iterator->left || ! iterator->right) {
//			// 这个判断用来检查v1,或是 v2不是二叉树节点的情况
//			return nullptr;
//		} else if (iterator->value < small && iterator->value > big) {
//			return nullptr;
//		} else {
//			return iterator;
//		}

		return iterator;
	}

	return nullptr;
}



int main(int argc, char **argv) {

	Node* tree = getTestTree();
	int tes_cases[6][3] = {
			{2, 9, 5},
			{2, 19, 12},
			{2, 16, 12},
			{15, 19, 18},
			{100, 19, 0},
			{-1, 19, 0},
	};


	for(int i=0; i < 6; ++i) {
		cout << "testcase: " << tes_cases[i][0] << " " << tes_cases[i][1] << ", ";
		Node* target = getLowestCommonAncestor(tree, tes_cases[i][0], tes_cases[i][1]);
		if (target && tes_cases[i][2] != 0) {
			cout << "get target: " << target->value;
			assert(target->value == tes_cases[i][2]);
		}

		cout << endl;
	}

	cout << "all passed !" << endl;

	return 0;
}