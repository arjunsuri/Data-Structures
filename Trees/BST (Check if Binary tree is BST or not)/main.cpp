#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node* right;
    node* left;
};

struct node* new_node(int new_data) {
 node* new_node = new node();
 new_node->data = new_data;
 new_node->right = NULL;
 new_node->left = NULL;
 return new_node;
}

bool isBSTHelper(node* root_ptr, int min, int max) {
 if(root_ptr == NULL)
    return true;
 if(root_ptr->data <= min || root_ptr->data >= max) {
    return false;
 }

 return (isBSTHelper(root_ptr->left, min, root_ptr->data) &&
         isBSTHelper(root_ptr->right, root_ptr->data, max));
}

bool check_bst(node* root_ptr) {
   return isBSTHelper(root_ptr, INT_MIN, INT_MAX);
}

int main() {
    node* temp=new_node(4);
    temp->left=new_node(2);
    temp->right=new_node(5);
    temp->left->left=new_node(1);
    temp->left->right=new_node(3);
    if(check_bst(temp)) {
        cout<<"this is a bst";
    } else {
        cout<<"this is not a bst";
    }
    return 0;
}
