/*
 * is_balance_tree.cpp
 *
 *  Created on: Sep 5, 2021
 *      Author: liuyanan
 */

#include <iostream>
#include <vector>

using namespace std;

/*
  问题：
  	  输入一颗二叉树的根节点， 判断该树是不是平衡二叉树。
  	  如果二叉树中任意节点的左右子树的深度相差不超过1， 那么它就是一颗平衡二叉树
  	  如下图就是一颗平衡二叉树：

  	  	  	  	1
			   / \
			  2   3
			 / \   \
			4   5   6
			   /
			  7

  两种玩法：
  	  1. 暴力解法，后续遍历，每次都判断左右子树的高度差是不是大于1

  	  2. 类似于线性规划的思想，每次把左右子树的高度都保存下来， 也是后续遍历

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
  	  	  	  	1
			   / \
			  2   3
			 / \   \
			4   5   6
			   /
			  7
	 */

	Node* node1 = createNode(1);
	Node* node2 = createNode(2);
	Node* node3 = createNode(3);
	Node* node4 = createNode(4);
	Node* node5 = createNode(5);
	Node* node6 = createNode(6);
	Node* node7 = createNode(7);

	buildTree(node1, node2, node3);
	buildTree(node2, node4, node5);
	buildTree(node3, nullptr, node6);
	buildTree(node5, node7, nullptr);

	return node1;
}

int depth(Node* tree)
{
	if(!tree) {
		return 0;
	}

	int left_depth = depth(tree->left);
	int right_depth = depth(tree->right);

	return max(left_depth, right_depth) + 1;
}

bool is_balance_tree_brute_force(Node* tree)
{
	int left_depth = depth(tree->left);
	int right_depth = depth(tree->right);

	if(abs(left_depth - right_depth) > 1) {
		return false;
	} else {
		return true;
	}
}

bool is_balance_tree_lp(Node* tree, int& depth)
{
	/* 玩法是这样的
			在后续遍历后，比较左右子树的深度，同时更新当前的深度，
			也就是从叶子节点到根节点的方向累加深度

		为什么这里的复杂度是 O(N)?
			首先当当前节点 cur 的深度我们是知道的，也就是根据左右子树的深度计算出来的
			而左右子树的深度也是有左右孙子树计算来的
			也就是减少了的递归过程中来来回回，进进退退的步骤
	 */

	if(!tree) {
		depth = 0;
		return true;
	}

	int left_depth, right_depth;

	bool left_is_balance = is_balance_tree_lp(tree->left, left_depth);
	bool right_is_balance = is_balance_tree_lp(tree->right, right_depth);

	// 出栈后，depth 都已经更新了
	// 同时左右子树都是平衡树的情况下才有继续判断的意义
	if(left_is_balance && right_is_balance) {

		// 只有当前也是平衡的情况下， depth 才有更新的必要
		if(abs(left_depth - right_depth) <= 1) {
			depth = max(left_depth, right_depth) + 1;
			return true;
		}
	}

	return false;
}


int main(int argc, char **argv) {

	Node* tree = getTestTree();

	cout << "is balance tree using brute force: " << is_balance_tree_brute_force(tree) << endl;

	int depth = 0;
	cout << "is balance tree using lp: " << is_balance_tree_lp(tree, depth) << endl;

	return 0;
}
