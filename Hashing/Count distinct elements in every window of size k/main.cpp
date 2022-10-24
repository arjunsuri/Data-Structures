#include <iostream>
#include<map>

using namespace std;

void count_elements(int arr[],int n,int k) {

   map<int, int> dist_element;
   int dist_count = 0;

   for(int i=0; i<k; i++) {
     if(dist_element[arr[i]] == 0) {
        dist_count++;
     }
     dist_element[arr[i]]++;
   }

   cout<< dist_count << endl;
   for(int i=k; i<n; i++) {
     if(dist_element[arr[i-k]] == 1) {
        dist_count--;
     }
     dist_element[arr[i-k]]--;

     if(dist_element[arr[i]] == 0) {
       dist_count++;
     }
     dist_element[arr[i]]++;
     cout << dist_count << endl;
   }
}

int main() {
    int arr[]={1,2,1,3,4,2,3,3};
    int n=7;
    int k=4;

    cout<<"\ndistinct elements in every window of size k:-"<<endl;
    count_elements(arr,n,k);

    return 0;
}
