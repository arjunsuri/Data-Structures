#include <iostream>

using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
};

node* root=NULL;

struct node* new_node(int new_data)
{
 node* new_node=new node();
 new_node->data=new_data;
 new_node->left=NULL;
 new_node->right=NULL;

  if(root==NULL)
  {
    root=new_node;

  }

    return new_node;

}

int maximum(int a,int b)
{
    if(a>b)
    {
       return a;
    }

    return b;

}

int height(struct node* root_ptr)
{
   if(root_ptr==NULL)
   {
      return -1;
   }

   int left_height=height(root_ptr->left);
   int right_height=height(root_ptr->right);

   return(1+maximum(left_height,right_height));

}

int main()
{
    node* temp=new_node(1);
    temp->left=new_node(2);
    temp->right=new_node(3);
    temp->left->left=new_node(4);
    temp->left->right=new_node(5);
    temp->right->left=new_node(6);
    temp->right->right=new_node(7);

   int height_tree=height(root);

   cout<<"\nthe height of the tree="<<height_tree;

    return 0;
}
