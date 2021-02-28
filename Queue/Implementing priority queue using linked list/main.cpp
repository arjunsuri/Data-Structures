#include <iostream>

using namespace std;

struct node {

int data;
int priority;
node* next;

};


struct node* new_node(int data, int priority) {
node* temp = new node();
temp->data = data;
temp->next = NULL;
temp->priority = priority;
return temp;
}

bool isEmpty(struct node** head_ref) {

 if((*head_ref) == NULL)
    return true;

 return false;

}

int peek(struct node** head_ref) {

if(isEmpty(head_ref)) {
    cout<<"list is empty"<<endl;
    return -1;
}
return (*head_ref)->data;

}

void pop(struct node** head_ref) {

if(isEmpty(head_ref)) {
    cout<<"list is empty"<<endl;
    return;
}

struct node* temp = (*head_ref);
(*head_ref) = (*head_ref)->next;
delete(temp);

}

void push(struct node** head_ref, int data, int priority) {

struct node* newNode = new_node(data, priority);
node* start = (*head_ref);

if(priority < (*head_ref)->priority) {
   newNode->next = start;
   start = newNode;
}

else {

  while(start->next != NULL && start->next->priority < priority) {
   start = start->next;
  }

  newNode->next = start->next;
  start->next = newNode;
}

}


int main()
{
    struct node* head = new_node(8, 1);

    push(&head, 7, 2);
    push(&head, 10, 1);
    push(&head, 18, 4);
    push(&head, 54, 2);
    push(&head, 98, 6);

    cout << "Priority Queue:-" <<endl;
    while(!isEmpty(&head)) {
        cout << peek(&head) <<endl;
        pop(&head);
    }
}
