#include <iostream>

using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
};

struct node* new_node(int new_data)
{
 struct node* new_node=new node();
 new_node->data=new_data;
 new_node->left=NULL;
 new_node->right=NULL;

 return new_node;
}

int count_leaf(struct node* root)
{
    if(root==NULL)
    {
        return 0;
    }

    else if(root->left==NULL && root->right==NULL)
    {
        return 1;
    }


    int countleft=count_leaf(root->left);
    int countright=count_leaf(root->right);

    return (countleft+countright);
}

int main()
{
    struct node* root=new_node(1);
    root->left=new_node(2);
    root->right=new_node(3);
    root->left->left=new_node(4);
    root->left->right=new_node(5);

    cout<<"no. of leaf nodes="<<count_leaf(root);

    return 0;
}
