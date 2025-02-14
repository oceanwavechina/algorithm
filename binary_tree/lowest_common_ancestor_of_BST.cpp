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

/*
 	 题目： 输入两个二叉搜索树的结点，求两个结点的最低公共祖先，所谓的最低公共祖先是指距离两个节点最近的共同祖先。
 */


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
	buildTree(node2, nullptr, nullptr);
	buildTree(node9, nullptr, nullptr);
	buildTree(node18, node15, node19);
	buildTree(node15, nullptr, node17);
	buildTree(node17, node16, nullptr);
	buildTree(node16, nullptr, nullptr);
	buildTree(node19, nullptr, nullptr);

	return node12;
}


Node* getLowestCommonAncestor_Recursively(Node* p_node, int v1, int v2)
{
	if(!p_node) {
		return nullptr;
	}

	int small = min(v1, v2);
	int big = max(v1, v2);

	if(p_node->value > small && p_node->value > big) {
		return getLowestCommonAncestor_Recursively(p_node->left, v1, v2);
	} else if(p_node->value < small && p_node->value < big) {
		return getLowestCommonAncestor_Recursively(p_node->right, v1, v2);
	} else {
		return p_node;
	}
}

Node* getLowestCommonAncestor_Iteratorly(Node* p_root, int v1, int v2)
{
	Node* p_cursor = p_root;

	int small = min(v1, v2);
	int big = max(v1, v2);

	do {

		if(p_cursor->value > small && p_cursor->value < big) {
			return p_cursor;
		}

		if(p_cursor->value > small && p_cursor->value > big) {
			p_cursor = p_cursor->left;
			continue;
		}

		if(p_cursor->value < small && p_cursor->value < big) {
			p_cursor = p_cursor->right;
			continue;
		}

		// 异常数据
		break;

	} while (p_cursor);

	return nullptr;
}



int main(int argc, char **argv)
{

	/*
	 	buildTree(node12, node5, node18);
		buildTree(node5, node2, node9);
		buildTree(node18, node15, node19);
		buildTree(node15, nullptr, node17);
		buildTree(node17, node16, nullptr);

									 12
								  /      \
								 5        18
							   /   \     /  \
							  2     9   15   19
							              \
							               17
							              /
							             16
	 */


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
		// Node* target = getLowestCommonAncestor_Recursively(tree, tes_cases[i][0], tes_cases[i][1]);
		Node* target = getLowestCommonAncestor_Iteratorly(tree, tes_cases[i][0], tes_cases[i][1]);
		if (tes_cases[i][2] != 0 && target) {
			cout << "get target: " << target->value;
			assert(target->value == tes_cases[i][2]);
		}

		cout << endl;
	}

	cout << "all passed !" << endl;

	return 0;
}





/*

     玩法是这样的：
         首先什么是二叉搜索树：
             二叉搜索树中的每个节点，都大于它的左孩子 并且小于它的 右孩子， 比如：

                                     12
                                  /      \
                                 5        18
                               /   \     /  \
                              2     9   15   19
                                          \
                                           17
                                          /
                                         16

        所以给定两个节点，其公共祖先满足： 比两个节点中较小的数大，并且比两个节点中较大的数小

        同时二叉搜索树又是有序的，于是，我们从根节点开始，依次搜索，知道满足上述条件即可：

            min(x,y) < ancestor < max(x,y)
 */
