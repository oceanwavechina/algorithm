/*
 * tree_diameter.cpp
 *
 *  Created on: May 10, 2018
 *      Author: liuyanan
 */

#include <iostream>
#include <queue>

using namespace std;


/*
  计算二叉树的直径
  	  https://www2.cs.duke.edu/courses/spring00/cps100/assign/trees/diameter.html


  什么是树的直径
	The diameter of a tree T is the largest of the following quantities:
		the diameter of T's left subtree
		the diameter of T's right subtree
		the longest path between leaves that goes through the root of T (this can be computed from the heights of the subtrees of T)


  TODO:
 	 树形动态规划
 */


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


void output_with_return(Node* root)
{
	if (! root)
		return;

	g_queue.push(root);

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

Node* getTree_ThroughRoot()
{
	/*
	  	  	  	  	  	  	  	  	  	    1
	  	  	  	  	  	  	  	  	  	 /    \
	  	  	  	  	  	  	  	  	  	2	   3
	  	  	  	  	  	  	  	  	   / \	    \
	  	  	  	  	  	  	  	  	  4	  5	     6
	  	  	  	  	  	  	  	  	     / \      \
	  	  	  	  	  	  	  	  	    7   [8]      9
	  	  	  	  	  	  	  	  	             /   \
	  	  	  	  	  	  	  	  	            10    11
	  	  	  	  	  	  	  	  	           /  \
	  	  	  	  	  	  	  	  	         [12]   13
	 */

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
	buildTree(node3, NULL, node6);
	buildTree(node5, node7, node8);
	buildTree(node6, NULL, node9);
	buildTree(node9, node10, node11);
	buildTree(node10, node12, node13);

	cout << "output tree by level" << endl;
	output_with_return(node1);

	return node1;
}

Node* getTree_NotThroughRoot()
{
	/*
	  	  	  	  	  	  	  	  	  	    1
	  	  	  	  	  	  	  	  	  	 /    \
	  	  	  	  	  	  	  	  	  	2	   3
	  	  	  	  	  	  	  	  	  /  \	    \
	  	  	  	  	  	  	  	  	 4	   5	 6
	  	  	  	  	  	  	  	  	/ \     \
	  	  	  	  	  	  	  	   7   8     9
	  	  	  	  	  	  	  	  	 /      /  \
	  	  	  	  	  	  	  	   10     11    12
	  	  	  	  	  	  	  	  /  \			 \
	  	  	  	  	  	  	  	13    14		  15
	 */

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
	Node* node14 = createNode(14);
	Node* node15 = createNode(15);

	buildTree(node1, node2, node3);
	buildTree(node2, node4, node5);
	buildTree(node3, NULL, node6);
	buildTree(node4, node7, node8);
	buildTree(node5, NULL, node9);
	buildTree(node8, node10, NULL);
	buildTree(node9, node11, node12);
	buildTree(node10, node13, node14);
	buildTree(node12, NULL, node15);

	cout << "output tree by level" << endl;
	output_with_return(node1);

	return node1;
}

int height(Node* t)
{
	// 深度： 当前节点往下，到叶子节点中最长的一条路径的

	if (!t) return 0;

	return max(height(t->left), height(t->right)) + 1;
}


int diameter(Node* t)
{
	if(!t) return 0;	// 叶子节点

	int lheight = height(t->left);
	int rheight = height(t->right);

	int ldiameter = diameter(t->left);
	int rdiameter = diameter(t->right);

	int max_child_diameter = max(ldiameter, rdiameter);

	return max(lheight + rheight + 1,  max_child_diameter);
}


int main(int argc, char **argv)
{
	Node* tree_1 = getTree_ThroughRoot();
	Node* tree_2 = getTree_NotThroughRoot();

	cout << "tree_1 diameter: " << diameter(tree_1) << endl;
	cout << "tree_2 diameter: " << diameter(tree_2) << endl;

	return 0;
}
