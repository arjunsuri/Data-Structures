#include <iostream>
#include<stdlib.h>

using namespace std;

struct node
{
    int data;
    struct node*next;

};

struct node* rear=NULL;
struct node* fronts=NULL;


bool isEmpty()
{
    if(rear==NULL && fronts==NULL)
    {
        return true;

    }

    return false;

}


void enqueue(int new_data)  //it adds elements to the queue.Rear is ahead of fronts,so element is added at the last.
{
    struct node* new_node=(struct node *)malloc(sizeof(struct node));

    new_node->data=new_data;

    new_node->next=NULL;

    if(isEmpty())
    {
        rear=new_node;
        fronts=new_node;

    }

    else{

        rear->next=new_node;
        rear=new_node;

    }

}


void dequeue()  //it deletes elements from the queue.
{
    if(isEmpty())
    {
        cout<<"\nthe queue is empty";

        return;

    }

    struct node* temp=fronts;

    fronts=temp->next;

    free(temp);


}

int front_end()  //gives the front end data.
{

    return (fronts->data);


}

int rear_end()   //gives the rear end data.
{
    return (rear->data);

}


void printqueue(struct node* fronts,struct node* rear)  //printing the queue from the front side to the rear side i.e. from left to right.
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
    enqueue(1);
    enqueue(2);
    enqueue(3);

    cout<<"the original queue is:-"<<endl;

    printqueue(fronts,rear);

    cout<<"queue after enqueuing an element is:-"<<endl;

    enqueue(7);

    printqueue(fronts,rear);

    cout<<"queue after dequeuing the first element is:-"<<endl;

    dequeue();

    printqueue(fronts,rear);

    cout<<"the front end element is:-"<<endl;

    cout<<front_end()<<endl;

    cout<<"the rear end element is:-"<<endl;

    cout<<rear_end()<<endl;

    return 0;
}
