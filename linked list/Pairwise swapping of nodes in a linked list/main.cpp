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

void push(struct node **head_ref,int new_data)
{

    struct node *new_node=new node();
    new_node->data=new_data;
    new_node->next=*head_ref;
    *head_ref=new_node;

}

void swapData(int *first, int *second)
{
    int temp_data=*first;
    *first=*second;
    *second=temp_data;
}


void swapList(struct node** head_ref){

if((*head_ref)==NULL || (*head_ref)->next==NULL)
return;

node* temp = *head_ref;

while(temp && temp->next)
{
    swapData(&temp->data, &temp->next->data);
    temp=temp->next->next;
}

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
{   struct node* head=NULL;

    push(&head,5);
    push(&head,4);
    push(&head,3);
    push(&head,2);
    push(&head,1);

    cout<<"the list before swapping of elements:-"<<endl;
    printlist(head);

    swapList(&head);

    cout<<"the list after swapping of elements:-"<<endl;
    printlist(head);

    return 0;
}
