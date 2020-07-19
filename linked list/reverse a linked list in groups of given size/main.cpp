#include <iostream>
#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
using namespace std;


struct node
{
struct node* next;
int data;
};

struct node* reverse_list(struct node *head_ref,int k)
{
    if(head_ref==NULL && head_ref->next==NULL)
        return head_ref;


    struct node* prev=NULL;
    struct node* current=head_ref;
    struct node* ahead=NULL;    //this node is pointing to the next node of current node.
    int counts=0;

    while(current!=NULL && counts<k )  //reverse the first k digits of the list.
    {
        ahead=current->next;
        current->next=prev;
        prev=current;
        current=ahead;
        counts++;

    }

    //ahead is now the new pointer to the (k+1)th element.
    // if ahead != NULL then recursively do the same for the next part of the list.


    if(ahead!=NULL)
    {
        head_ref->next=reverse_list(ahead,k);  //we are repeatedly making the prev , head of the of the reversed list

    }

    return prev;


}

void push(struct node **head_ref,int new_data)
{

    struct node *new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=new_data;
    new_node->next=*head_ref;
    *head_ref=new_node;

}


void printlist(struct node *node)
{
    while(node!=NULL)
    {
        cout<<node->data<<endl;
        node=node->next;
    }

}

int main()
{   int k;
    struct node* head=NULL;

    push(&head,5);
    push(&head,4);
    push(&head,3);
    push(&head,2);
    push(&head,1);

    cout<<"enter the no. after which you want the list to be reversed";
    cin>>k;

    cout<<"the list before reversing:-"<<endl;

    printlist(head);

    head=reverse_list(head,k);

    cout<<"the list after reversing:-"<<endl;

    printlist(head);

    return 0;
}
