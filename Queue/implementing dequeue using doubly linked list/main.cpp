#include <iostream>
#include<stdlib.h>

using namespace std;

struct node
{
    int data;
    struct node* next;
    struct node* prev;

};

struct node* fronts=NULL;
struct node* rear=NULL;

bool isEmpty()
{
    if(fronts==NULL && rear==NULL)
    {
        return true;

    }
    return false;
}

void insert_rear(int new_data)
{
    struct node* new_node=(struct node *)malloc(sizeof(struct node));

    new_node->data=new_data;

    new_node->next=NULL;

    if(isEmpty()) {
        fronts=new_node;
        rear=new_node;
    }

    else {
        rear->next=new_node;
        new_node->prev=rear;
        rear=new_node;
    }
}

void insert_front(int new_data)
{
    struct node* new_node=(struct node *)malloc(sizeof(struct node));

    new_node->data=new_data;

    new_node->prev=NULL;

    if(isEmpty()) {
        fronts=new_node;
        rear=new_node;
    }

    else {
        new_node->next=fronts;
        fronts->prev=new_node;
        fronts=new_node;
    }
}

void delete_front()
{
    if(isEmpty())
    {
        cout<<"the queue is empty";
        return;
    }

    struct node* temp=fronts;

    fronts=temp->next;

    if(fronts==NULL) {
        rear=NULL;
    }
    else {
        fronts->prev=NULL;
    }

    delete(temp);
}


void delete_rear()  //delete element from the rear end.
{
    if(isEmpty()) {
        cout<<"the queue is empty";
        return;
    }

    struct node* temp=rear;
    rear=temp->prev;
    if(fronts==NULL) {
        rear=NULL;
    }
    else {
        rear->next=NULL;
    }

    delete(temp);
}


int getfront()
{
    return fronts->data;

}

int getrear()
{
    return rear->data;

}


void printqueue(struct node* fronts,struct node* rear)
{
    while(fronts!=rear)
    {
        cout<<fronts->data<<endl;

        fronts=fronts->next;

    }

    cout<<rear->data<<endl;
}

int main()
{

    cout<<"the original queue is:-"<<endl;

    insert_rear(1);

    insert_front(2);

    insert_rear(3);

    printqueue(fronts,rear);

    cout<<"the queue after insertion is:-"<<endl;

    insert_front(4);

    printqueue(fronts,rear);
    cout<<"the queue after insertion is:-"<<endl;

    insert_rear(5);

    printqueue(fronts,rear);
    cout<<"the queue after insertion is:-"<<endl;

    insert_front(6);

   printqueue(fronts,rear);

   cout<<"deleting from rear"<<endl;

   delete_rear();

   printqueue(fronts,rear);

   cout<<"deleting from front"<<endl;

   delete_front();

   printqueue(fronts,rear);

   cout<<"getting front element"<<endl;

   cout<<getfront()<<endl;

   cout<<"getting rear element"<<endl;

    cout<<getrear()<<endl;

    return 0;
}
