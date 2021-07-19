/*
 * find_node_with_multi_parent.cpp
 *
 *  Created on: Jul 19, 2021
 *      Author: liuyanan
 */


#include <iostream>
#include <stdlib.h>
#include <unordered_map>
#include <vector>

using namespace std;


/*
 	问题：
		有一颗二叉树，有些节点有多个父节点，打印该节点和父节点

	思路：
		遍历每个有父节点的的节点，然后用hash表，记录下他的父节点
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

	/*
	 *
	 *			 10
	 *			/  \
	 *		   6    14
	 *		  / \  /  \
	 *		 4    8   16
	 *		/
	 *	   9
	 *
	 *	  这里的 8 有两个父节点，分别是 6 和 14
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
	buildTree(node14, node8, node16);

	return node10;
}

typedef unordered_map<Node*/*node*/, vector<Node*>/*parents*/> TResult;

void find_node_with_multi_parent(Node* p_node, TResult& g_result)
{
	if(!p_node) {
		return;
	}

	if(p_node->left) {
		g_result[p_node->left].push_back(p_node);
		find_node_with_multi_parent(p_node->left, g_result);
	}

	if(p_node->right) {
		g_result[p_node->right].push_back(p_node);
		find_node_with_multi_parent(p_node->right, g_result);
	}
}

int main(int argc, char **argv)
{
	TResult g_result;
	find_node_with_multi_parent(getTestTree(), g_result);

	for(auto pair : g_result) {
		if(pair.second.size() > 1) {
			cout << pair.first->value << " has multi parents:";
			for(auto parent : pair.second) {
				cout << parent->value << ", ";
			}
		}
	}
	cout << endl;

	return 0;
}




