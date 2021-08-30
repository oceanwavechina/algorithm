/*
 * lowest_common_acestor_of_trivial_tree_recursion.cpp
 *
 *  Created on: Aug 30, 2021
 *      Author: liuyanan
 */

#include <iostream>
#include <vector>
#include <sstream>
#include <cassert>
#include <utility>

using namespace std;


/*
 	题目：
 	 	 输入一个二叉树。求两个结点的最低公共祖先，所谓的最低公共祖先是指距离两个节点最近的共同祖先。

 	 	 这个是 lowest_common_ancestor_with_parent_pointer.cpp 的一个变种：
 	 	 	 即去掉了 每个节点可以指向其父节点的指针这个条件， 同时限定是二叉树：


								 5
							  /      \
							11        9
						   	   \     /  \
						  	   17   0   25
							  /
							32


	玩法是这样的, 根据递归的思路：

		给定两个节点 x, y

		如果有一个节点是 root，那最低公共祖先就是 root

		如果 x, y 分别在 root 的左右子树，那 root 本身就是 最低公共祖先

		如果 x, y 在 root 的 同一侧(左子树或是右子树)， 那 root = root->oneside, 继续递归
 */

struct Node
{
	Node(int v):value(v), left(nullptr), right(nullptr) {}
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
	if (parent != nullptr) {
		parent->left = left;
		parent->right = right;
	}
}

Node* getTestTree() {
/*
				 5
			  /      \
			11        9
			   \     /  \
			   17   0   25
			  /
			32
 */
	Node* node5 = createNode(5);
	Node* node11 = createNode(11);
	Node* node9 = createNode(9);
	Node* node17 = createNode(17);
	Node* node0 = createNode(0);
	Node* node25 = createNode(25);
	Node* node32 = createNode(32);

	buildTree(node5, node11, node9);
	buildTree(node11, nullptr, node17);
	buildTree(node17, node32, nullptr);
	buildTree(node9, node0, node25);

	return node5;
}

Node* get_node_by_value(Node* tree, long val)
{
	if(!tree) {
		return nullptr;
	}

	if(tree->value == val) {
		return tree;
	}

	Node* ret = get_node_by_value(tree->left, val);
	if(ret) return ret;

	ret = get_node_by_value(tree->right, val);
	return ret;
}

bool find_node(Node* tree, Node* x)
{
	if(tree->value == x->value) {
		return true;
	}

	if(tree->left && find_node(tree->left, x)) {
		return true;
	}

	if(tree->right) {
		return find_node(tree->right, x);
	}

	return false;
}

Node* do_find_common_ancestor(Node* tree, Node* x, Node* y)
{
	// 1. 有一个是当前子树的根节点，那根节点就是最低公共祖先了
	if(tree->value == x->value || tree->value == y->value) {
		return tree;
	}

	// 2. 如果 x，y 分别为 tree 的左右子树，那 tree 就是最低公共祖先了
	// 		这个好好理解下这个
	bool x_on_left = find_node(tree->left, x);
	bool y_on_left = find_node(tree->left, y);

	if(x_on_left != y_on_left) {
		return tree;
	}

	if(x_on_left) {
		return do_find_common_ancestor(tree->left, x, y);
	} else {
		return do_find_common_ancestor(tree->right, x, y);
	}
}


long common_ancestor(Node* tree, long x, long y)
{
	// 先根据数据找到对应的 Node*
	Node* p_x = get_node_by_value(tree, x);
	Node* p_y = get_node_by_value(tree, y);

	assert(p_x);
	assert(p_y);

	// 接下来是递归调用查找
	Node* ret = do_find_common_ancestor(tree, p_x, p_y);
	if(ret) {
		return ret->value;
	}

	return -1;
}


int main(int argc, char **argv) {

	Node* tree = getTestTree();

	/*
				 5
			  /      \
			11        9
			   \     /  \
			   17   0   25
			  /
			32
	 */

	vector<pair<long, long>> test_case = {
			{ 32, 0 },
			{ 0, 25 },
			{ 5, 32 },
			{ 17, 9 },
	};

	for(int i=0; i<test_case.size(); ++i) {
		long& x = test_case[i].first;
		long& y = test_case[i].second;

		long ret = common_ancestor(tree, x, y);

		cout << "lowest common ancestor of (" << x << ", " << y << ") is: " << ret << endl;
	}

	return 0;
}
