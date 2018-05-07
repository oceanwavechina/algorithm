/*
 * binary_search_tree.cpp
 *
 *  Created on: Oct 9, 2016
 *      Author: liuyanan
 */


#include <iostream>
#include <vector>

using namespace std;

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

		//std::cout << "find before insert: ";
		//DisplayNode(P);

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
	static void Delete(Node* N, Node** root) {

		if (N->right == nullptr && N->left != nullptr) {
			if (N->parent != nullptr) {
				if (N == N->parent->right)
					N->parent->right = nullptr;
				else
					N->parent->left = nullptr;
			} else {
				*root = N->left;
			}

			delete N;

		} else if (N->right != nullptr && N->left == nullptr) {
			if (N->parent != nullptr) {
				if (N == N->parent->right)
					N->parent->right = N->right;
				else
					N->parent->left = N->right;
			} else {
				*root = N->right;
			}

			delete N;

		} else if (N->right == nullptr && N->left != nullptr) {
			if (N == N->parent->right)
				N->parent->right = N->left;
			else
				N->parent->left = N->left;

			delete N;

		} else {
			Node *X = Next(N);
			N->key = X->key;

			if(!X->parent) {
				*root = N;
			} else {
				if(X->parent->left == X)
					X->parent->left = X->right;
				else
					X->parent->right = X->right;
			}

			delete X;
#if 0
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
#endif
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


	vector<int> nums = {15, 5, 3, 12, 10, 13, 6, 7, 16, 20, 18, 23};

	// build tree
	for(auto x : nums)
	{
		BinarySearchTree::Insert(x, tree);
		BinarySearchTree::middle_order(tree);
	}

	vector<int> search_case = {0, -1, 4, 6, 11, 99};
	for(auto key : search_case) {
		Node* node_del = BinarySearchTree::Find(key, tree);
		if(node_del->key != key) {
			cout << "find " << key << ":  xxx" << endl;
		} else if(node_del->key == key) {
			cout << "find " << key << ":  √√√" << endl;
		}
	}

	for(auto x : nums)
	{
		Node* node_del = BinarySearchTree::Find(x, tree);
		delete node_del; node_del=nullptr;
		cout << "after delete " << x << endl;
		BinarySearchTree::middle_order(tree);

		BinarySearchTree::Insert(x, tree);
	}

	return 0;
}
