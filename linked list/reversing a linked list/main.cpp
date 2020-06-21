#include <iostream>
#include<stdlib.h>
using namespace std;

struct node
{
int data;
struct node *next;

};

void make_list(struct node** head_ref, int data)
{
    struct node* new_node=new node();
    new_node->data=data;
    new_node->next=*(head_ref);
    *(head_ref)=new_node;

}

void reverse_list(struct node** head_ref)
{

    if(*(head_ref)==NULL)
        return;

    struct node* pre=NULL;
    struct node* curr=*(head_ref);
    struct node* curr_next=curr->next;

    while(curr)
    {
        curr->next=pre;
        pre=curr;
        curr=curr_next;

        if(curr_next!=NULL)
         curr_next=curr_next->next;

    }

    *(head_ref)=pre;

}

void printlist(struct node* head)
{
    struct node* temp=head;

    while(temp)
    {
        cout<<temp->data<<endl;
        temp=temp->next;
    }

}


int main()
{
   struct node* head=NULL;

   make_list(&head,1);
   make_list(&head,2);
   make_list(&head,3);
   make_list(&head,4);
   make_list(&head,5);      // 5->4->3->2->1->NULL

   cout<<"Print list before reversing:-"<<endl;
   printlist(head);

   reverse_list(&head);

   cout<<"Print list after reversing:-"<<endl;  //1->2>3->4->5->NULL
   printlist(head);

    return 0;
}
