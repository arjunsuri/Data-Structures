// sample2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
};

struct Node* new_node(int data) {
	struct Node* new_node = new Node();
	new_node->data = data;
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
}

void NthInorder(struct Node* root, int n)
{
	static int count = 0;
	if (root == NULL)
		return;

	if (count < n) {

		NthInorder(root->left, n);
		count++;

		if (count == n)
			cout << "Data for Nth node = " << root->data << endl;

		NthInorder(root->right, n);
	}
}

int main()
{
	struct Node* root = new_node(1);
	root->left = new_node(2);
	root->right = new_node(3);
	root->left->left = new_node(4);
	root->left->right = new_node(5);

	int n = 3;

	NthInorder(root, n);
}