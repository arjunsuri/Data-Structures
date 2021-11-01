// bst (insertion).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

struct Node {

    int data;
    Node* left;
    Node* right;
};

struct Node* makeNode(int data) {

    struct Node* newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct Node* insertNode(struct Node* root, int data) {

    if (root == NULL) {
         return makeNode(data);
    }

    if (root->data < data) {
       root->right = insertNode(root->right, data);
    }

    else if (root->data > data) {
        root->left = insertNode(root->left, data);
    }

    return root;
}

void inorder(struct Node* root) {

    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << endl;
    inorder(root->right);

}

int main()
{
    struct Node* root = NULL;
    root = insertNode(root, 5);
    root = insertNode(root, 2);
    root = insertNode(root, 3);
    root = insertNode(root, 4);
    root = insertNode(root, 8);
    root = insertNode(root, 6);
    root = insertNode(root, 7);
    root = insertNode(root, 1);
    root = insertNode(root, 9);
    root = insertNode(root, 10);  

    inorder(root);
}
