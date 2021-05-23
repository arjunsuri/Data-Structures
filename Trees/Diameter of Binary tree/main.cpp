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
      return 0;
   }

   int left_height=height(root_ptr->left);
   int right_height=height(root_ptr->right);

   return(1+maximum(left_height,right_height));

}


int diameter(struct node* root_ptr)
{
    if(root_ptr==NULL)
    {
        return 0;
    }

    int left_height1=height(root_ptr->left);
    int right_height1=height(root_ptr->right);

    int left_dia=diameter(root_ptr->left); //calculate diameter of left subtree.
    int right_dia=diameter(root_ptr->right); //calculate diameter of right subtree.

    return(maximum((1+left_height1+right_height1),maximum(left_dia,right_dia)));
    //there are two cases of return statement i.e. if root node is involved in the diameter of the tree,maximum will give
    //1+height(head_ref->left)+height(head_ref->right) and if root node is not involved in diameter then return maximum of
    //left_dia and right_dia.
}

int main()
{
    node* temp=new_node(1);
    temp->left=new_node(2);
    temp->right=new_node(3);
    temp->left->left=new_node(4);
    temp->left->right=new_node(5);
    temp->right->right=new_node(6);
    temp->left->right->left=new_node(7);
    temp->left->right->right=new_node(8);

   int dia=diameter(root);
   cout<<"the diameter of the tree will be "<<dia;

    return 0;
}
