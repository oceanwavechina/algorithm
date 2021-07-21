/*
 * binary_search_tree.cpp
 *
 *  Created on: Oct 9, 2016
 *      Author: liuyanan
 */


#include <iostream>
#include <vector>

#include <queue>
std::priority_queue a;

using namespace std;

/*
 *	在搜索二叉树中，父节点比左孩子大，比右孩子小
 */

struct Node {

	Node():key(0), left(nullptr), right(nullptr), parent(nullptr), data(-1) {}
	Node(int k):key(k), left(nullptr), right(nullptr), parent(nullptr), data(-1) {}

	int key;

	Node* left;
	Node* right;
	Node* parent;

	int data;
};


class BinarySearchTree {
public:
	typedef std::vector<Node*> Nodes;

public:
	BinarySearchTree():_root(nullptr)
	{}


public:
	Node* Search(int k)
	{
		Node* iter = _root;
		while(iter)
		{
			if (iter->key == k){
				return iter;
			} else if(k < iter->key) {
				iter = iter->left;
			} else {
				iter = iter->right;
			}
		}

		return nullptr;
	}

	Node* Minimum(Node* node)
	{
		// 找到该子树上最小的节点, 一路向左
		while(node && node->left) {
			node = node->left;
		}

		return node;
	}

	Node* Maximum(Node* node)
	{
		// 该子树的最大值，一直向右
		while(node && node->right) {
			node = node->right;
		}

		return node;
	}

	Node* Successor(Node* x)
	{
		// 右节点不为空时
		if(x->right)
			return Minimum(x->right);

		/* 有节点为空时
		 *	1. 循环向上是，x, y 要满足的关系：y 是 x 的父节点，并且 x 是 y 的右孩子
		 *	2. 退出循环条件：x 是 y 的左孩子
		 */
		Node* y = x->parent;
		while(y && x == y->right) {
			x = y;
			y = x->parent;
		}

		return y;
	}

	void Insert(Node* z)
	{
		Node* y = nullptr;
		Node* x = _root;

		// 按二叉树的特点查找这样一个节点y，y至少又一个孩子是空
		// y 保存 x上一个值
		while(x) {
			y = x;
			if(z->key < x->key)
				x = x->left;
			else
				x = x->right;
		}

		// 此时，y 就是 待插入节点 z 点的父节点
		z->parent = y;

		if(!y)
			_root = z;
		else {
			// 看看是左孩子，还是右孩子
			if(z->key < y->key)
				y->left = z;
			else
				y->right = z;
		}
	}

	Node* Delete(Node* z) {
		Node* y = nullptr;	// 真正要删除的节点，因为如果z的两个孩子都有的话，可以它它的后继复制过来，然后删除后继
		Node* x = nullptr;	// 被删除节点的孩子节点

		if(!z->left || !z->right)
			y = z;
		else
			y = Successor(z);

		if(y->left)
			x = y->left;
		else
			x = y->right;

		// 把孩子几点提升
		if(x) {
			x->parent = y->parent;
		}

		if(!(y->parent))	// 被删除的是根节点
			_root = x;
		else {
			if(y == y->parent->left)
				y->parent->left = x;
			else
				y->parent->right = x;
		}

		if(y != z) {
			z->key = y->key;
			z->data = y->data;
		}

		return y;
	}

	void MidOrderOutput() {
		_midOrderOutput(_root);
		cout << endl;
	}

private:
	void _midOrderOutput(Node* x) {
		if (x) {
			_midOrderOutput(x->left);
			cout << x->key << "\t";
			_midOrderOutput(x->right);
		}
	}


private:
	Node* _root;
};


int main() {

	BinarySearchTree tree;

	vector<int> nums = {15, 5, 3, 12, 10, 13, 6, 7, 16, 20, 18, 23};

	// build tree
	for(auto x : nums)
	{
		tree.Insert(new Node(x));
		tree.MidOrderOutput();
	}

	vector<int> search_case = {0, -1, 4, 6, 11, 99};
	for(auto key : search_case) {
		if(!tree.Search(key)) {
			cout << "find " << key << ":  xxx" << endl;
		} else {
			cout << "find " << key << ":  √√√" << endl;
		}
	}

	for(auto x : nums)
	{
		Node* p = tree.Search(x);
		p = tree.Delete(p);
		delete p; p=nullptr;
		cout << "after delete " << x << endl;
		tree.MidOrderOutput();

		tree.Insert(new Node(x));
	}

	return 0;
}
