#include <iostream>
#include<stdlib.h>
#include<limits.h>

using namespace std;

struct node
{
  int data;
  struct node* next;

};

//checking whether stack is empty.
bool isEmpty(struct node* head_ref){
    if(head_ref==NULL)
    {
     return true;
    }

    return false;

}

void push(struct node** head_ref,int new_data) //pushing elements in the stack.
{
    struct node* new_node=new node();

    new_node->data=new_data;

    new_node->next=*head_ref;                          // 20->10->NULL

    *head_ref=new_node;

    cout<<"\nthe element pushed to stack="<<new_data;

}



void pop(struct node** head_ref) //extracting elements out of the stack.
{
    if(isEmpty(*head_ref))
    {
        cout<<"the stack is empty";
        return;

    }


    struct node* temp=*head_ref;

    *head_ref=temp->next;

    free(temp);

}


int peek(struct node* head_ref)  //getting the topmost element in the stack.
{
    if(isEmpty(head_ref))
    {
        return INT_MIN;
    }

     return head_ref->data;

}



void printstack(struct node* node) //printing the stack.
{
while(node!=NULL)
{
    cout<<node->data<<endl;
    node=node->next;

}


}



int main()
{

    struct node* head=NULL;

    push(&head,10);
    push(&head,20);
    push(&head,30);

    cout<<"\nthe status of stack after pushing the elements:-"<<endl; // 30->20->10.

    printstack(head);

    pop(&head);


    cout<<"\nthe status of stack after popping the first element:-"<<endl;

    printstack(head);

    int start=peek(head);

    cout<<"the first element currently in the stack="<<start;


    return 0;
}
