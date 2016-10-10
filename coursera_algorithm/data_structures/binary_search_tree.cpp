/*
 * binary_search_tree.cpp
 *
 *  Created on: Oct 9, 2016
 *      Author: liuyanan
 */




#include <iostream>


struct Node {

	Node():key(0), left(nullptr), right(nullptr), parent(nullptr) {}
	Node(int k):key(k), left(nullptr), right(nullptr), parent(nullptr) {}

	int key;

	Node* left;
	Node* right;
	Node* parent;
};



class BinarySearchTree {
public:
	typedef std::vector<Node*> Nodes;

public:
	Node* Find(int k, Node* R) {

		if (R->key == k)
			return R;
		else if (R->key > k)
			if (R->left != nullptr)
				return Find(k, R->left);
			else
				return R;
		else
			if (R->right != nullptr)
				return Find(k, R->right);
			else
				return R;
	}

	Node* LeftDescendent(Node* N) {
		if (N->left == nullptr)
			return N;
		else
			return LeftDescendent(N->left);
	}

	Node* RightAncestor(Node* N) {
		if (N == nullptr)
			return nullptr;

		if (N->key < N->parent->key)
			return N->parent;
		else
			return RightAncestor(N->parent);
	}

	/*
	 * 找到次大的那个元素
	 */
	Node* Next(Node* N) {
		if (N->right != nullptr)
			return LeftDescendent(N->right);
		else
			return RightAncestor(N);
	}

	Nodes RangeSearch(int x, int y, Node* R) {
		Nodes L;

		Node* N = Find(x, R);

		while (N->key <= y) {
			if (N->key >= x) {
				L.push_back(N);
			}

			N = Next(N);
		}

		return L;
	}

	void Insert(int k, Node* R) {
		Node* P = Find(k, R);

		Node* n = new Node(k);
		n->parent = R;

		if (k > R->key)
			R->right = n;
		else
			R->left = n;
	}

	void Delete(Node* N) {
		if (N->right ==  nullptr)
			// remove N, promote N->left
			;
		else
			// X <- Next(N)
			// replace N by X, promote X->right
			;
	}
};


int main() {


	return 0;
}
