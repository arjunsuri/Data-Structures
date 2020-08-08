#include <iostream>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

struct node{

int data;
struct node* next;

};


void push(struct node **head_ref,int new_data)
{

    struct node* new_node=new node();

    new_node->data=new_data;

    new_node->next=*head_ref;

    *head_ref=new_node;


}




int getcount(struct node* head)
{
    //struct node *counter=head;

 if(head==NULL)
 {
   return 0;          //count = 0.
 }
 else{

    return 1+getcount(head->next);  //count =1+counter->next.


 }




}


void printlist(struct node* n)
{
    while(n!=NULL)
    {
        cout<<n->data<<endl;
        n=n->next;

    }

}



int main()
{
    struct node *head=NULL;

    push(&head,5);
    push(&head,4);
    push(&head,3);
    push(&head,2);
    push(&head,1);

    cout<<endl;
    cout<<"the no. of nodes = "<<getcount(head);
    cout<<endl;
    cout<<"the linked list:-";
    cout<<endl;
    printlist(head);

    return 0;
}
