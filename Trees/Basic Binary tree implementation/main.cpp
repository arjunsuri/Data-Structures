#include <iostream>

using namespace std;

struct node
{
  int data;
  struct node* left;
  struct node* right;

};
int i=0;
int arr[7];

struct node* new_node(int new_data)
{


    arr[i]=new_data;

    i++;

    struct node* new_node=new node();

    new_node->data=new_data;

    new_node->left=NULL;

    new_node->right=NULL;

    return new_node;
}


void print_tree()
{
    for(int i=0;i<7;i++)
    {
        cout<<arr[i]<<endl;

    }


}



int main()
{
    struct node* temp=new_node(1);

    temp->left=new_node(2);

    temp->right=new_node(3);

    temp->left->left=new_node(4);

    temp->left->right=new_node(5);

    temp->right->right=new_node(6);

    temp->right->left=new_node(7);

    cout<<"the tree:-"<<endl;

    print_tree();

    return 0;
}
