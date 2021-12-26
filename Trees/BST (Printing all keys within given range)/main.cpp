#include <iostream>

using namespace std;


struct node
{
    int data;
    node* right;
    node* left;

};

node* root=NULL;

node* new_node(int new_data)
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


void print(node* root_ptr,int k1,int k2)  //it is given that k2>k1.
{
    if(root_ptr==NULL)
        return;


    print(root_ptr->left,k1,k2);   //simple inordef traversal with condition in between.


    if(root_ptr->data<=k2 && root_ptr->data>=k1)
    {
      cout<<root_ptr->data<<endl;

    }

    print(root_ptr->right,k1,k2);


}




int main()
{
    node* temp=new_node(20);
    temp->left=new_node(8);
    temp->right=new_node(22);
    temp->left->left=new_node(4);
    temp->left->right=new_node(12);



    int k1,k2;
    cout<<"\nenter the values of k1 and k2";
    cin>>k1>>k2;

    cout<<"bst keys in the given range is:-"<<endl;
    print(root,k1,k2);


    return 0;
}
