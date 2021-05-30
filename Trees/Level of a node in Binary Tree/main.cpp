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
    node* new_node=new node();
    new_node->data=new_data;
    new_node->left=NULL;
    new_node->right=NULL;

    return new_node;

}

int treeLevel(node* root,int key, int level)
{
    if(root==NULL)
        return 0;

    if(root->data==key)
        return level;


    int leftLevel=treeLevel(root->left,key,level+1);

    if(leftLevel!=0)
        return leftLevel;

    int rightLevel=treeLevel(root->right,key,level+1);
        return rightLevel;

}



int main()
{
    struct node* root=new_node(3);
    root->left=new_node(2);
    root->right=new_node(5);
    root->left->left=new_node(1);
    root->left->right=new_node(4);

    int key;
    cout<<"enter the value of key"<<endl;
    cin>>key;

    cout<<"the level of the node="<<treeLevel(root,key,1);

    return 0;
}
