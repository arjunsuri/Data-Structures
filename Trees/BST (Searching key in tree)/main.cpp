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


int search_key(node* root,int key)
{
if(root==NULL)
{
    return 0;
}

if(root->data==key)
{
 cout<<"found it";
 return 0;
}

if(root->data<key)
search_key(root->right,key);

else
search_key(root->left,key);



return 0;

}

int main()
{
    node* temp=new_node(8);
    temp->left=new_node(3);
    temp->right=new_node(10);
    temp->right->right=new_node(14);
     temp->right->right->left=new_node(13);
     temp->left->left=new_node(1);
      temp->left->right=new_node(6);
     temp->left->right->left=new_node(4);
     temp->left->right->right=new_node(7);
     int key;
     cout<<"enter key to be searched"<<endl;
     cin>>key;

      search_key(root,key);


    return 0;
}
