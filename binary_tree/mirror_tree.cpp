/*
 * mirror_tree.cpp
 *
 *  Created on: Jul 2, 2021
 *      Author: liuyanan
 */

#include <iostream>
#include <sstream>
#include <queue>


/*


                   8                               8
                /     \							/     \
               6      10		   --->        10      6
             /  \    /  \                     /  \    /  \
            3    7  9    11                  11   9  7    3
 */



struct Node {
	Node(int v): value(v),left(nullptr), right(nullptr)
	{ }

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

Node* getTestTree()
{
	/*
                   8
                /     \
               6      10
             /  \    /  \
            3    7  9    11
	 */

	Node* node8 = createNode(8);
	Node* node6 = createNode(6);
	Node* node10 = createNode(10);
	Node* node3 = createNode(3);
	Node* node7 = createNode(7);
	Node* node9 = createNode(9);
	Node* node11 = createNode(11);

	buildTree(node8, node6, node10);
	buildTree(node6, node3, node7);
	buildTree(node10, node9, node11);

	return node8;
}

int depth(Node* p_node)
{
	if(!p_node) {
		return 0;
	}

	int left_depth = depth(p_node->left);
	int right_depth = depth(p_node->right);

	return std::max(left_depth, right_depth) + 1;
}

void display(Node* tree)
{
	if(!tree) {
		return ;
	}

	std::ostringstream oss;
	std::queue<Node*> q;
	q.push(tree);


	int tree_depth = depth(tree);
	int cur_level_size = 1;
	int next_level_size = 0;

	while(!q.empty()) {

		Node* p_node = q.front();
		q.pop();

		if(next_level_size == 0) {
			for(int i=0; i<tree_depth; ++i) {
				oss << "\t";
			}
			--tree_depth;
		}

		// 先打印当前层
		oss << p_node->value << "\t";

		if(p_node->left) {
			q.push(p_node->left);
			++ next_level_size;
		}
		if(p_node->right) {
			q.push(p_node->right);
			++ next_level_size;
		}


		if(--cur_level_size == 0) {
			oss << "\n";
			cur_level_size = next_level_size;
			next_level_size = 0;
		}
	}

	std::cout << oss.str() << std::endl;
}

/*
 	 思路是先序遍历，
 	 	 1. 遇到一个节点，并且不是叶子节点就交换他的左右孩子
 	 	 2. 然后依次递归调用，交换这个节点的左右孩子的孩子节点
 */
void mirror_tree_recursively(Node* p_node)
{
	if(!p_node || (!p_node->left && !p_node->right)) {
		return;
	}

	Node*  p_tmp = p_node->left;
	p_node->left = p_node->right;
	p_node->right = p_tmp;

	if(p_node->left) {
		mirror_tree_recursively(p_node->left);
	}

	if(p_node->right) {
		mirror_tree_recursively(p_node->right);
	}
}


void mirror_tree_recursively2(Node* p_node) {

    if(!p_node) {
        return;
    }

    Node* tmp =  p_node->left;
    p_node->left = p_node->right;
    p_node->right = tmp;

    if(p_node->left) {
        mirror_tree_recursively(p_node->left);
    }

    if(p_node->right) {
        mirror_tree_recursively(p_node->right);
    }

}

/*
 	 因为是根据镜像的特点，其实是按行遍历的，所以我们使用queue就可以解决
 */
void mirror_tree_iteratively(Node* p_node)
{
	if(!p_node) {
		return ;
	}

	std::queue<Node*> q;
	q.push(p_node);

	while(!q.empty()) {

		// 先交换当前行的左右子树
		Node* cur_node = q.front();
		q.pop();

		if(cur_node->left || cur_node->right) {
			Node* tmp = cur_node->left;
			cur_node->left = cur_node->right;
			cur_node->right = tmp;
		}

		// 把下一层入队
		if(cur_node->left) {
			q.push(cur_node->left);
		}
		if(cur_node->right) {
			q.push(cur_node->right);
		}
	}
}


int main(int argc, char **argv) {

	Node* tree = getTestTree();

	display(tree);

	mirror_tree_recursively2(tree);
	// mirror_tree_iteratively(tree);

	display(tree);

	return 0;
}
