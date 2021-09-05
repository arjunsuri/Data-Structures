// Top view of binary tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <queue>
#include <map>

using namespace std;

struct node {

    int data;
    struct node* left;
    struct node* right;
    int hd;
};

struct node* new_node(int data) {

    struct node* newNode = new node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->hd = 0;
    return newNode; 
}

void printTopView(struct node* root) {

    if (root == NULL)
        return;

    queue<node*> topViewQueue;
    map<int, int> viewMap;
    int hd = 0;
    topViewQueue.push(root);

    while (topViewQueue.size()) {

        root = topViewQueue.front();
        hd = root->hd;

        if (viewMap.count(hd) == 0) {
            viewMap[hd] = root->data;
        }

        if (root->left) {
            root->left->hd = hd - 1;
            topViewQueue.push(root->left);
        }

        if (root->right) {
            root->right->hd = hd + 1;
            topViewQueue.push(root->right);
        }

        topViewQueue.pop();
    }

    for (auto i = viewMap.begin(); i != viewMap.end(); i++) {
        cout << i->second << endl;
    }

}

int main()
{
    struct node* root = new_node(1);
    root->left = new_node(2);
    root->right = new_node(3);
    root->left->left = new_node(4);
    root->left->right = new_node(5);
    root->right->left = new_node(6);
    root->right->right = new_node(7);

    cout << "Top view of binary tree:-" << endl;
    printTopView(root);

}

