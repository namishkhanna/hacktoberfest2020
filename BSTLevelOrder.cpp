#include <queue>
#include <iostream>
using namespace std;

struct Node {
	Node* right;
	Node* left;
	int key;
	Node(int);
};
Node::Node(int _key) {
	this->key = _key;
	right = nullptr;
	left = nullptr;
}

struct BST {
	BST();
	Node* root;
	Node* getRoot();
	void setRoot(Node* _root);
	Node* InsertNode(Node* root, int _key);
	void LevelOrderTraversal(Node* root);
};
BST::BST() {
	root = nullptr;
}
Node* BST::getRoot() {
	return this->root;
}
void BST::setRoot(Node* _root) {
	this->root = _root;
}
Node* BST::InsertNode(Node* root, int _key) {
	if (root == nullptr) {
		return new Node(_key);
	}
	if (_key < root->key) {
		root->left = InsertNode(root->left, _key);
	}
	else if (_key > root->key) {
		root->right = InsertNode(root->right, _key);
	}
	return root;
}
void BST::LevelOrderTraversal(Node* root) {
	queue<Node*> q1;
	queue<Node*> q2;
	int level = 0;
	if (root != nullptr) {
		q1.push(root);
	}
	while (!q1.empty() || !q2.empty()) {
		level++;
		cout << "Level: " << level << endl;
		while (!q1.empty()) {
			if (q1.front()->left != nullptr) {
				q2.push(q1.front()->left);
			}
			if (q1.front()->right != nullptr) {
				q2.push(q1.front()->right);
			}
			cout << q1.front()->key << " ";
			q1.pop();
		}
		if (!q2.empty()) {
			cout << endl;
			level++;
			cout << "Level: " << level << endl;
		}
		while (!q2.empty()) {
			if (q2.front()->left != nullptr) {
				q1.push(q2.front()->left);
			}
			if (q2.front()->right != nullptr) {
				q1.push(q2.front()->right);
			}
			cout << q2.front()->key << " ";
			q2.pop();
		}
		cout << endl;
	}
}

int main() {
	BST Tree;
	int valuesAmount;
	cout << "How many values would you like to insert? ";
	cin >> valuesAmount;
	vector<int> treeValues;
	for (int i = 0; i < valuesAmount; i++) {
		int value;
		cout << "insert value into tree: ";
		cin >> value;
		cout << endl;
		Tree.setRoot(Tree.InsertNode(Tree.getRoot(), value));
	}
	cout << "-----Level Order Traversal-----" << endl;
	Tree.LevelOrderTraversal(Tree.getRoot());
	return 0;
}
