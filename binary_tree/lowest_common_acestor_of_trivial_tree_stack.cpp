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
#include <stack>

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


	玩法是这样的, 用栈的思路：

		其实思想还是求两个路径的公共节点，只不过这次不用链表保存，而是用栈保存

		比如给定的两个元素， 32 和 0， 其对应的栈分别为：

		| 32 |
		------
		| 17 |			| 0 |
		------			------
		| 11 |			| 9 |
		------			------
		| 5  |			| 5 |
		------			------

		但是这两个栈大小不一样，所以我们要先把它变的一样高， 也就是让高的那个弹出元素：

		| 17 |			| 0 |
		------			------
		| 11 |			| 9 |
		------			------
		| 5  |			| 5 |
		------			------

		然后依次比较，直到找到两个相同的为止
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

void display_stack(const stack<long>& path, const string& msg)
{
	stack<long> tmp = path;
	ostringstream oss;
	oss << msg << ": ";

	while(!tmp.empty()) {
		oss << tmp.top() << ",";
		tmp.pop();
	}

	cout << oss.str() << endl;
}


bool build_path_stack(Node* tree, long val, stack<long>& path)
{
	path.push(tree->value);

	if(tree->value == val) {
		return true;
	}

	if(tree->left && build_path_stack(tree->left, val, path)) {
		return true;
	}

	if(tree->right && build_path_stack(tree->right, val, path)) {
		return true;
	}

	path.pop();

	return 0;
}

long common_ancestor(Node* tree, long x, long y)
{
	// 1. 先构建两个路径栈
	stack<long> stack_x, stack_y;

	build_path_stack(tree, x, stack_x);
	build_path_stack(tree, y, stack_y);

	display_stack(stack_x, "stack_x");
	display_stack(stack_y, "stack_y");

	// 2. 弄成一样高
	long diff = stack_x.size() - stack_y.size();
	if(diff > 0) {
		while(diff-- > 0) {
			stack_x.pop();
		}
	} else if(diff < 0) {
		diff = abs(diff);
		while(diff-- > 0) {
			stack_y.pop();
		}
	}

	// 开始找
	while(!stack_x.empty() && !stack_y.empty()) {

		if(stack_x.top() == stack_y.top()) {
			return stack_x.top();
		}

		stack_x.pop();
		stack_y.pop();
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

		cout << "lowest common ancestor of (" << x << ", " << y << ") is: " << ret << endl << endl;
	}

	return 0;
}
