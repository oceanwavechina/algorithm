/*
 * BinaryTree_Traversing.cpp
 *
 *  Created on: Nov 24, 2016
 *      Author: liuyanan
 */


#include <iostream>
#include <stdlib.h>
#include <stack>

using namespace std;

/*
 关于各种顺序递归遍历的理解：

 	 递归本质上分成两部分:
 	 	 一个压栈
 	 	 一个出栈

	压栈是从后往前，也可以说是从顶到低， 而出栈反之

	对一颗树，如果在压栈之前做操作，那就是从根到叶子的顺序
			如果在出栈之后做操作，那就是从叶子到根的顺序

			因为到最低成的叶子之后才有出栈操作，也就是当栈顶的那个函数返回的时候，实际上是叶子之下的元素才处理完，接下来就是叶子了

	其在不同位置处理分别代表的含义(对于当前 root 而言)：
		void traverse(Node* root) {

			//
			// root 压栈前处理
			// 		比如二叉树镜像中，要从上到下，交换左右两个子树，需要在这里处理
			//

			if (root->left) {
				traverse(root->left);
			}

			//
			// root 第一次出栈处理(也就是左孩子处理完)
			// 	 	比如二叉树转换成链表的时候，需要连接左右孩子，所以要在这里做处理
			//

			if (root->right) {
				traverse(root->right);
			}

			//
			// root 第二次出栈处理(也就是右孩子处理完)
			//		比如计算树的深度，要求两个子树的最大值，所以只能在左右子树都计算完了，才能知道，所以要在这里处理
			//		再比如计算树的直径，也是这样
			//		再比如计算树的路径中最大值: 需要知道当前节点最有子树的最大值，所以要在这里处理
			//
		}

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
	Node* node10 = createNode(10);
	Node* node6 = createNode(6);
	Node* node14 = createNode(14);
	Node* node4 = createNode(4);
	Node* node8 = createNode(8);
	Node* node12 = createNode(12);
	Node* node16 = createNode(16);

	buildTree(node10, node6, node14);
	buildTree(node6, node4, node8);
	buildTree(node14, node12, node16);

	return node10;
}

void inOrderTraverse(Node* root)
{
	if (root == NULL) {
		return ;
	}

	if (root->left != NULL) {
		inOrderTraverse(root->left);
	}

	cout << root->value << '\t';

	if (root->right != NULL) {
		inOrderTraverse(root->right);
	}
}

void preOrderTraverse(Node* root) {

	if (root == NULL) {
		return ;
	}

	/*
	 先序遍历，这个是在当前节点压栈之前进行处理
	 */

	cout << root->value << '\t';

	if (root->left) {
		preOrderTraverse(root->left);
	}

	if (root->right) {
		preOrderTraverse(root->right);
	}
}

void postOrderTraverse(Node* root) {
	if(root == NULL) {
		return ;
	}

	if (root->left) {
		postOrderTraverse(root->left);
		/*
		  当这个函数返回的时候，说明 root->left 下的所有节点都遍历完了
		 */
	}

	if (root->right) {
		postOrderTraverse(root->right);
	}

	cout << root->value << '\t';
}


void PreOrder2_With_Stack(Node* root) {
	Node* node = root;

	stack<Node*> _stack;

	while( node || !_stack.empty() ) {
		if (node) {
			cout << node->value << '\t'; 	// 输出
			_stack.push(node);				// 压栈
			node = node->left;				// 遍历左子树
		} else {
			node = _stack.top();
			_stack.pop();
			node = node->right;
		}
	}
}

void InOrder2_With_Stack(Node* root) {
	Node* node = root;

	stack<Node*> _stack;

	while( node || !_stack.empty() ) {
		if (node) {
			_stack.push(node);			// 父节点压栈
			node = node->left;			// 遍历左子树
		} else {
			node = _stack.top();
			cout << node->value << '\t'; 	// 输出父节点

			node = node->right;				//遍历右子树

			_stack.pop();
		}
	}
}


int main()
{
	Node* root = getTestTree();

	cout << "pre order traverse: ";
	preOrderTraverse(root);
	cout << endl;;

	cout << "in order traverse: ";
	inOrderTraverse(root);
	cout << endl;;

	cout << "post order traverse: ";
	postOrderTraverse(root);
	cout << endl;;

	cout << "post order (without recursive) traverse: ";
	PreOrder2_With_Stack(root);
	cout << endl;;

	cout << "in order (without recursive) traverse: ";
	InOrder2_With_Stack(root);
	cout << endl;;

}
