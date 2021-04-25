// C++ program for different tree traversals
#include <iostream>
using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* create_node(int data) {

    struct Node* newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/* Given a binary tree, print its nodes according to the
preorder traversal. */
void preOrder(struct Node* node)
{
    if (node == NULL)
        return;

    // print the topmost node
    cout << node->data << " ";

    // first recur on left subtree
    preOrder(node->left);

    // then recur on right subtree
    preOrder(node->right);
}

/* Given a binary tree, print its nodes according to the
inorder traversal. */
void inOrder(struct Node* node)
{
    if (node == NULL)
        return;

    // first recur on left subtree
    inOrder(node->left);

    // print the topmost node
    cout << node->data << " ";

    // then recur on right subtree
    inOrder(node->right);
}

/* Given a binary tree, print its nodes according to the
postorder traversal. */
void postOrder(struct Node* node)
{
    if (node == NULL)
        return;

    // first recur on left subtree
    postOrder(node->left);

    // then recur on right subtree
    postOrder(node->right);

     // print the topmost node
    cout << node->data << " ";
}

/* Driver program to test above functions*/
int main()
{
    struct Node* root = create_node(1);
    root->left = create_node(2);
    root->right = create_node(3);
    root->left->left = create_node(4);
    root->left->right = create_node(5);

    cout << "\nPreorder traversal of binary tree is \n";
    preOrder(root);

    cout << "\ninorder traversal of binary tree is \n";
    inOrder(root);

    cout << "\npostorder traversal of binary tree is \n";
    postOrder(root);

    return 0;
}
