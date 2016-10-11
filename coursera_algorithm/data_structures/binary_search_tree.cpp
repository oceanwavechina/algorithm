/*
 * binary_search_tree.cpp
 *
 *  Created on: Oct 9, 2016
 *      Author: liuyanan
 */


#include <iostream>
#include <vector>


struct Node {

	Node():key(0), left(nullptr), right(nullptr), parent(nullptr), height(1) {}
	Node(int k):key(k), left(nullptr), right(nullptr), parent(nullptr), height(1) {}

	int key;

	Node* left;
	Node* right;
	Node* parent;

	int height;	// height of the tree
};


class BinarySearchTree {
public:
	typedef std::vector<Node*> Nodes;

public:

	static void DisplayNode(Node* n) {
		std::cout << "node:" << n->key << std::endl;
	}

	static void DisplayRange(Nodes nodes) {

		std::cout << "range is:";
		for (auto node : nodes) {
			std::cout << " " << node->key;
		}
		std::cout <<  std::endl;
	}

	static Node* Find(int k, Node* R) {
		/*
		 * missing key: if you stop before reaching a null pointer,
		 * you find the place in the tree where K would fit.
		 * we will return something close to it
		 */

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

	static Node* LeftDescendent(Node* N) {
		if (N->left == nullptr)
			return N;
		else
			return LeftDescendent(N->left);
	}

	static Node* RightAncestor(Node* N) {
		// 不断的找parent节点

		// N is the largest number, then it has no ancestor,
		// so when call RightAncestor(N->parent); we got nullptr as the parameter
		// N->parent == nullptr:  这句话可别忘了。。。
		if (N == nullptr || N->parent == nullptr)
			return nullptr;

		if (N->key < N->parent->key)
			return N->parent;
		else
			return RightAncestor(N->parent);
	}

	/*
	 * 找到 next largest key
	 */
	static Node* Next(Node* N) {
		if (N->right != nullptr)
			return LeftDescendent(N->right);
		else
			return RightAncestor(N);
	}

	static Nodes RangeSearch(int x, int y, Node* R) {
		Nodes L;

		Node* N = Find(x, R);

		while (N->key <= y) { 		// 上限
			if (N->key >= x) {		// 下限
				L.push_back(N);
			}

			N = Next(N);
			if (nullptr == N)
				break;
		}

		return L;
	}

	static void Insert(int k, Node* R) {
		Node* P = Find(k, R);

		std::cout << "find before insert: ";
		DisplayNode(P);

		Node* n = new Node(k);
		n->parent = P;

		if (k > P->key)
			P->right = n;
		else
			P->left = n;
	}

	/*
	 * delete 没调试好，有问题
	 */
	static void Delete(Node* N) {
		if (N->right ==  nullptr) {
			// remove N, promote N->left
			Node *X = Next(N);
			N->key = X->key;

			if (X && X->left) {
				N->parent->right = X->left;
			} else {
				N->parent->right = nullptr;
			}

			delete X;

		} else {
			// replace N by X, promote X->right
			std::cout <<  "delete right is not null" << std::endl;
			Node *X = Next(N);
			N->key = X->key;

			if (X->right){
				if (X->right)
					N->right = X->right;
				else
					N->right = nullptr;
				delete X->right;
			} else {
				std::cout <<  "delete X" << std::endl;
				if (X->right)
					N->right = X->right->right;
				else
					N->right = nullptr;
				delete X;
			}
		}
	}

	static void _middle_order(Node* R) {
		if(R != nullptr){
			_middle_order(R->left);
			std::cout << " " << R->key;
			_middle_order(R->right);
		}
	}

	static void middle_order(Node* R) {
		_middle_order(R);
		std::cout << std::endl;
	}
};


int main() {

	Node* tree = new Node(9);

	BinarySearchTree::Insert(1, tree);
	BinarySearchTree::middle_order(tree);
	BinarySearchTree::Insert(6, tree);
	BinarySearchTree::middle_order(tree);
	BinarySearchTree::Insert(2, tree);
	BinarySearchTree::middle_order(tree);
	BinarySearchTree::Insert(7, tree);
	BinarySearchTree::middle_order(tree);
	BinarySearchTree::Insert(4, tree);
	BinarySearchTree::middle_order(tree);
	BinarySearchTree::Insert(8, tree);
	BinarySearchTree::middle_order(tree);
	BinarySearchTree::Insert(3, tree);
	BinarySearchTree::middle_order(tree);
	BinarySearchTree::Insert(5, tree);
	BinarySearchTree::middle_order(tree);
	std::cout << "tree built complete ..." << std::endl << std::endl;

	BinarySearchTree::DisplayRange(BinarySearchTree::RangeSearch(2, 90, tree));

	Node* node_5 = BinarySearchTree::Find(6, tree);
	BinarySearchTree::DisplayNode(node_5);

	BinarySearchTree::Delete(node_5);

	BinarySearchTree::middle_order(tree);

	return 0;
}
