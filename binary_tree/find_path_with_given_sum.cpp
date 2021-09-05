/*
 * find_path_with_given_sum.cpp
 *
 *  Created on: Sep 5, 2021
 *      Author: liuyanan
 */

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

/*
  问题:
  	  输入一颗二叉树的根节点和一个整数，按字典序打印出二叉树中结点值的和为输入整数的所有路径。
  	  路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。

	  比如，如下的二叉树中， 给定和为22， 其路径有两条：[10， 12] 和 [10， 5， 7]

	  	  	    10
			   / \
			  5   12
			 / \
			4   7

  玩法是这样的：
	  首先我们要遍历所有路径

	  1. 什么是路径?
	  	  从 根节点 到 某个叶节点 就是对应一条路径（只能是一条，想想为什么）
	  	  比如 从 10 到 4, 就对应一条路径 [10, 5, 4]

	  2. 如何计算各个路径的和
	  	  这个要同时用到先序遍历和后续遍历，为什么?
			  1) 首先用先序遍历累计从根到叶子的和，也就是一条完整的路径的和
			  2) 然后用后序遍历回退，回退是把不满足条件的元素从累计的和中减去

	  3. 如何保存路径
	  	  可以用一个辅助的数组：
	  	  	  先序遍历的时候在后边追加
	  	  	  后序遍历的时候如果：
	  	  	  	  不满足和就在后边删除掉该元素
	  	  	  	  如果满足了，说明当前数组就是要找的路径，可以直接返回了
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
	  	  	    10
			   / \
			  5   12
			 / \
			4   7
	 */

	Node* node10 = createNode(10);
	Node* node5 = createNode(5);
	Node* node12 = createNode(12);
	Node* node4 = createNode(4);
	Node* node7 = createNode(7);

	buildTree(node10, node5, node12);
	buildTree(node5, node4, node7);

	return node10;
}


bool do_find_path(vector<long>& target_path, Node* tree, long& cur_sum)
{
	if(!tree) {
		return false;
	}

	// 先序遍历，累计和，压栈操作
	target_path.push_back(tree->value);
	cur_sum += tree->value;

	bool is_leaf = (!tree->left) && (!tree->right);
	if(is_leaf && cur_sum == 22) {
		return true;
	}

	bool found = do_find_path(target_path, tree->left, cur_sum);
	if(found) {
		return true;
	}

	found = do_find_path(target_path, tree->right, cur_sum);
	if(found) {
		return true;
	}

	target_path.pop_back();
	cur_sum -= tree->value;

	return false;
}

vector<long> find_path(Node* tree)
{
	assert(tree);

	vector<long> target_path;
	long cur_sum = 0;

	bool found = do_find_path(target_path, tree, cur_sum);

	if(found) {
		return target_path;
	} else {
		return vector<long>();
	}
}

void display(const vector<long>& vec, const string& msg)
{
	cout << msg << ": " << endl;

	for(auto item : vec) {
		cout << item << ", ";
	}

	cout << endl;
}

int main(int argc, char **argv) {

	Node* tree = getTestTree();

	vector<long> path = find_path(tree);

	display(path, "target path");

	return 0;
}
