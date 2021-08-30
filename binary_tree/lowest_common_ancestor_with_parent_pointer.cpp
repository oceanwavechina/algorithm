/*
 * lowest_common_ancestor_with_parent_pointer.cpp
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
 	 	 输入一个树，每个节点有指向父节点的指针。求两个结点的最低公共祖先，所谓的最低公共祖先是指距离两个节点最近的共同祖先。

 	 	 这个是 lowest_common_ancestor_of_BST.cpp 的一个变种：
 	 	 	 即去掉了二叉搜索树这个条件，同时添加了每个节点可以指向其父节点的指针这个条件
 	 	 	 所以这个树可能不是一个二叉树：


							  32
							//	 \\
						  12	  45
						 //	  //  ||  \\
						3	 36   78   99

	玩法是这样的：

		对于给定的任意一个节点 X, 其到 root 的路径就形成了一个双向链表

		题目相当于求：对于给定的两个节点，求它们的第一个公共节点。
		比如， 给定两个节点 36 和 99， 其到根节点的路径分别为：

			36：	36 -> 45 -> 32
			99：	99 -> 45 ->	32

		其公共祖先，也就是第一个公共节点 45

				 36
					 \
					 	45 ->32
					 /
		 		 99

		所以题目就是在求两个链表的公共节点
 */

struct Node
{
	Node(int v):value(v), child1(nullptr), child2(nullptr), child3(nullptr), parent(nullptr) {}
	~Node() {}

	int value;
	Node* child1;
	Node* child2;
	Node* child3;
	Node* parent;
};


Node* createNode(int value)
{
	return new Node(value);
}

void buildTree(Node* parent, Node* child1, Node* child2, Node* child3)
{
	if (parent != nullptr) {
		parent->child1 = child1;
		parent->child2 = child2;
		parent->child3 = child3;

		if(child1)
			child1->parent = parent;
		if(child2)
			child2->parent = parent;
		if(child3)
			child3->parent = parent;
	}
}

Node* getTestTree() {
/*
 							  32
							//	 \\
						  12	  45
						 //	  //  ||  \\
						3	 36   78   99
 */
	Node* node32 = createNode(32);
	Node* node12 = createNode(12);
	Node* node3 = createNode(3);
	Node* node45 = createNode(45);
	Node* node36 = createNode(36);
	Node* node78 = createNode(78);
	Node* node99 = createNode(99);

	buildTree(node32, node12, node45, nullptr);
	buildTree(node12, node3, nullptr, nullptr);
	buildTree(node45, node36, node78, node99);

	return node32;
}

Node* get_node_by_value(Node* tree, long val)
{

	/*
	这里在理解下递归：

		递归有两个条件：
			1. 一个是初始值，
			2. 另一个是递推关系

		对应递归函数，其实是两个过程：
			1. 压栈的过程，这个是向前找到初始值的过程，没有任何计算
			2. 出栈过程，这个是从初始值开始向后计算的过程
			 	 所以每一个递归函数返回时，我们就认为初始值到当前的节点已经计算完了，比如：

			 	 	 ret = get_node_by_value(tree->child1, val);

			 	 当这行代码执行完成后，就认为 tree-child1，这个分支的所有遍历完成了
			 	 (先不要去纠结里边来来回回跳了多少次， 因为我们关心的是这个递归返回值)

		关于递归函数需要注意的是：
			1. 初始值在哪里
			2. 对于多有分支都要依次判断
			3. 我们只关心递归函数返回值代表的是什么

			比如我们这里的实现：

				ret = get_node_by_value(tree->child1, val) 中

				如果 ret != nullptr 表示的是：

					tree->child1 子树中存在一个节点 ret 满足: ret->value == val
					此时我们只需要依次向上返回即可，不需要在对这个 ret 做什么了
	 */

	if(tree->value == val) {
		return tree;
	}

	Node* ret = nullptr;

	if(tree->child1) {
		ret = get_node_by_value(tree->child1, val);
		if(ret) {
			return ret;
		}
	}
	if(tree->child2) {
		ret = get_node_by_value(tree->child2, val);
		if(ret) {
			return ret;
		}
	}
	if(tree->child3) {
		return get_node_by_value(tree->child3, val);
	}

	return nullptr;
}

long len(Node* p_node)
{
	int ret = 0;

	while(p_node) {
		++ ret;
		p_node = p_node->parent;
	}

	return ret;
}

Node* advance(Node* p_node, long step)
{
	while(step-- > 0) {
		p_node = p_node->parent;
	}

	return p_node;
}

long common_ancestor(Node* tree, long x, long y)
{
	Node* p_x = get_node_by_value(tree, x);
	Node* p_y = get_node_by_value(tree, y);

	assert(p_x);
	assert(p_y);

	// 现在 p_x 和 p_y 是两个链表的头节点，
	// 接下来，沿着 parent 寻找两个链表的公共节点

	long len_x = len(p_x);
	long len_y = len(p_y);

	// 让长的那个前进几步
	if(len_x > len_y) {
		p_x = advance(p_x, len_x - len_y);
	} else {
		p_y = advance(p_y, len_y - len_x);
	}

	// 找第一个公共节点
	while(p_x && p_y) {
		if(p_x == p_y) {
			return p_x->value;
		}

		p_x = p_x->parent;
		p_y = p_y->parent;
	}

	return -1;
}



int main(int argc, char **argv) {

	Node* tree = getTestTree();

	/*
	 							  32
								//	 \\
							  12	  45
							 //	  //  ||  \\
							3	 36   78   99
	 */

	vector<pair<long, long>> test_case = {
			{ 36, 99 },
			{ 3, 36 },
			{ 12, 78 },
	};

	for(int i=0; i<test_case.size(); ++i) {
		long& x = test_case[i].first;
		long& y = test_case[i].second;

		long ret = common_ancestor(tree, x, y);

		cout << "lowest common ancestor of (" << x << ", " << y << ") is: " << ret << endl;
	}

	return 0;
}
