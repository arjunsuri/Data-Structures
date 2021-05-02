#include <iostream>
#include<queue>
using namespace std;       //refer my code school video(youtube).

struct node
{
    int data;
    node* left;
    node* right;
};

queue<node*> q;  //formation of queue using std library.

struct node* root=NULL;

struct node* new_node(int new_data)  //storing nodes in the tree.
{
    struct node* new_node=new node();
    new_node->data=new_data;
    new_node->right=NULL;
    new_node->left=NULL;

    if(root==NULL)
    {
       root=new_node;
    }
    return new_node;
}

void breadth_first_traversal(struct node* head_ref)
{
    if(head_ref==NULL)  //if tree is empty.
        return;

    q.push(root);

    while(!q.empty())   //while queue is not empty.
    {
        struct node* current=q.front();   // front() access to front element of the queue.
        cout<<current->data<<endl;
        q.pop();  //deletes the first element from the queue.

        if(current->left!=NULL)
        {
        q.push(current->left);   //push left child in the queue.
        }

        if(current->right!=NULL)   //push right child in the queue.
        {
         q.push(current->right);
        }
    }
}

int main()
{
    struct node* temp=new_node(1);
    temp->left=new_node(2);
    temp->right=new_node(3);
    temp->left->left=new_node(4);
    temp->left->right=new_node(5);
    temp->right->left=new_node(6);
    temp->right->right=new_node(7);

    cout<<"Level order traversal of binary tree is:-"<<endl;

    breadth_first_traversal(root);

    return 0;
}
