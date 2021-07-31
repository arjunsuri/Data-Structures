#include <iostream>
using namespace std;

struct node
{
	int data;
	node* left;
	node* right;
};

void printArray(int ints[], int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		cout << ints[i] << " ";
	}
	cout << endl;
}

void printPathsRecur(node* node, int path[], int pathLen)
{
	if (node == NULL)
		return;

	/* append this node to the path array */
	path[pathLen] = node->data;
	pathLen++;

	/* it's a leaf, so print the path that led to here */
	if (node->left == NULL && node->right == NULL)
	{
		printArray(path, pathLen);
	}
	else
	{
		/* otherwise try both subtrees */
		printPathsRecur(node->left, path, pathLen);
		printPathsRecur(node->right, path, pathLen);
	}
}

node* newnode(int data)
{
	node* Node = new node();
	Node->data = data;
	Node->left = NULL;
	Node->right = NULL;

	return(Node);
}

void printPaths(node* node)
{
	int path[1000];
	printPathsRecur(node, path, 0);
}

int main()
{
	node* root = newnode(10);
	root->left = newnode(8);
	root->right = newnode(2);
	root->left->left = newnode(3);
	root->left->right = newnode(5);
	root->right->left = newnode(2);

	printPaths(root);
	return 0;
}
