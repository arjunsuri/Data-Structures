#include <iostream>
#include <stack>

using namespace std;

struct node {
    int data;
    node* left;
    node* right;
};

struct node* new_node(int new_data) {
    node* new_node = new node();
    new_node->data = new_data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

struct node* tree(node* root,int key) {

    if(root == NULL)
        return new_node(key);

    if(key > root->data) {
        root->right=tree(root->right,key);
    }

    if(key < root->data) {
        root->left=tree(root->left,key);
    }

    return root;
}

void iterative_inorder(node* root) {

  if(root == NULL)
    return;

  else {

   stack<node*> itr;

  while(root != NULL || !itr.empty()) {

   while(root != NULL) {
   itr.push(root);
   root = root->left;
   }

   root = itr.top();
   cout<<root->data<<endl;
   itr.pop();
   root = root->right;
  }

  }

}

int main() {

    node* root=NULL;
    root = tree(root,1);
    tree(root,2);
    tree(root,3);
    tree(root,7);
    tree(root,4);
    tree(root,5);
    tree(root,6);
    tree(root,8);
    tree(root,9);

    cout<<"iterative inorder traversal:-"<<endl;
    iterative_inorder(root);

    return 0;
}
