#include <iostream>

using namespace std;

bool check(int arr[], int n) {

 int lastSuccessor = arr[n-1];
 int nextSuccessor;

 for(int i=0; i<n; i++) {
    nextSuccessor = arr[i+1];
    if((nextSuccessor > arr[i] && lastSuccessor < arr[i]) ||
       (nextSuccessor < arr[i] && lastSuccessor > arr[i])) {
        return false;
    }
 }

 return true;
}

int main()
{
   int arr[]={20,10,11,13,12};
   int n=5;

   if(check(arr, n)) {
       cout<<"exactly one child.";
   }

   else {
      cout<<"not exactly one child.";
   }

    return 0;
}
