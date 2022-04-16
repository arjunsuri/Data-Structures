#include <iostream>

using namespace std;

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int new_data)
{
  struct node* new_node=new node();
  new_node->data  = new_data;
  new_node->left  = NULL;
  new_node->right = NULL;

  return new_node;
}

struct node* insert_node(node* root,int data)  //insert node in binary search tree.
{
    if(root==NULL)
    {
       return newNode(data);
    }

    if(data>root->data)
    {
       root->right=insert_node(root->right,data);

    }


    if(data<root->data)
    {
       root->left=insert_node(root->left,data);

    }

    return root;

}

int minimum(node* root) //find the minimum value of root node.
{
    if(root==NULL)
    {
       return 0;
    }

    while(root->left!=NULL)
    {
        root=root->left;
    }

    return root->data;

}

int main()
{
    node* root=NULL;

    root=insert_node(root,4);

    insert_node(root,2);
    insert_node(root,1);
    insert_node(root,3);
    insert_node(root,6);
    insert_node(root,5);

    int ans=minimum(root);

    cout<<"\nthe min value in the tree is "<<ans;

    return 0;
}
