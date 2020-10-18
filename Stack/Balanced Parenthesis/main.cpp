#include <iostream>
#include<conio.h>
#include<stdlib.h>


using namespace std;


struct node
{
   int data;
   struct node* next;
};



bool isEmpty(struct node* head_ref)  //check if stack is empty or not.
{
    if(head_ref==NULL)
    {
        return true;

    }

    else{

        return false;

    }


}



bool isMatchingPair(char ch1,char ch2)  //checks the two characters if they are same or not.
{
    if(ch1=='(' && ch2==')')
    {
        return true;
    }


    else if(ch1=='{' && ch2=='}')
    {
        return true;
    }


    else if(ch1=='[' && ch2==']')
    {
        return true;
    }

    else{
        return false;
    }


}


void push(struct node** head_ref,int new_data)
{
    struct node* new_node=(struct node*)malloc(sizeof(struct node));

    new_node->data=new_data;

    new_node->next=*head_ref;

    *head_ref=new_node;



}



int pop(struct node* head_ref)
{
  if(isEmpty(head_ref))
  {
      cout<<"stack underflow";

      return 0;
  }

   else
    {
  struct node* temp=head_ref;
  head_ref=temp->next;
  int res=temp->data;

  free(temp);

  return res;
}


}



bool areParenthesisBalanced(char arr[])
{
    struct node* head=NULL;

    int i=0;

    while(arr[i])
    {
        if(arr[i]=='{' || arr[i]=='[' || arr[i]=='(')
        {
           push(&head,arr[i]);

        }

        if(arr[i]=='}' || arr[i]==']' || arr[i]==')')
        {
            if(head==NULL)       //if stack is empty we cannot compare it with other symbols in stack,hence return.
            {
                return 0;
            }




           else if(!(isMatchingPair(pop(head),arr[i])))
           {
              return 0;
           }

        }

        i++;
    }

    if(head== NULL)
    {
        return 1;
    }

    else{

      return 0;
    }



}


int main()
{

    char arr[]="[{()}]";

    if(areParenthesisBalanced(arr))
    {
        cout<<"balanced";
    }

    else{

        cout<<"not balanced";
    }


    return 0;

}

