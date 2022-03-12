#include <iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
};

struct node* new_node(int new_data)
{
 node* new_node=new node();
 new_node->data=new_data;
 new_node->left=NULL;
 new_node->right=NULL;

 return new_node;

}

node* tree(node* root,int key)
{
    if(root == NULL)
        return new_node(key);

    if(root->data > key)
        root->left = tree(root->left,key);

    if(root->data < key)
        root->right = tree(root->right,key);

     return root;
}

struct node* inorder(node* root,int val)
{
    node* curr = root;
    node* succ = NULL;

    while(curr != NULL) {
      if(curr->data > val) {
        succ = curr;
        curr = curr->left;
      } else {
        curr = curr->right;
      }
    }

    return succ;

}

int main()
{
    node* root = NULL;

    root = tree(root,20);
    tree(root,8);
    tree(root,22);
    tree(root,4);
    tree(root,12);
    tree(root,10);
    tree(root,14);

    int val;
    cout<<"enter the no. of which inorder successor is required."<<endl;
    cin>>val;

    node* successor = inorder(root,val);

    if(successor == NULL) {
        cout << "no inorder successor";
    }
    else {
        cout << "inorder successor:- " << successor->data;
    }

    return 0;
}
