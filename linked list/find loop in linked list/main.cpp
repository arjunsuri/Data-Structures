#include <iostream>
#include<stdlib.h>
using namespace std;

struct node
{
    struct node *next;
    int data;

};

bool detect_loop(struct node* lists)   //this function detects the presence of loop.
{
 struct node* slow_p=lists;
 struct node* fast_p=lists;

 while(fast_p && slow_p && fast_p->next)
 {
     slow_p=slow_p->next;
     fast_p=fast_p->next->next;

     if(fast_p==slow_p)
     {
       return true;
     }

 }

     return false;
}



struct node* newnode(int key)   //method to allocate nodes.
{

    struct node* temp =(struct node*)malloc(sizeof(struct node));

    temp->data=key;
    temp->next=NULL;
    return temp;

}

int main()
{

    struct node* head=newnode(2);

    head->next=newnode(3);
    head->next->next=newnode(7);
    head->next->next->next=newnode(8);
    head->next->next->next->next=newnode(10);



    //connecting last element(10) with 7.

    head->next->next->next->next->next=head->next->next;

    //here the loop has become 2->3->7->->8->10->7.

     if(detect_loop(head)){
        cout<<"loop found in list";
     }
     else{
        cout<<"loop not found in list";
     }

    return 0;
}
