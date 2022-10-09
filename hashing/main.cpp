#include<bits/stdc++.h>

using namespace std;

bool isDuplicate(int arr[],int n,int k) {

  set<int> duplicateSet;

  for(int i=0; i<n; i++) {
    if(duplicateSet.find(arr[i]) != duplicateSet.end()) {
        return true;
    }
    duplicateSet.insert(arr[i]);
    if(i >= k) {
      duplicateSet.erase(arr[i-k]);
    }
  }
  return false;
}

int main()
{
    int arr[20];
    int n;
    cout<<"\nenter the size of array";
    cin>>n;

    for(int i=0;i<n;i++) {
      cin>>arr[i];
    }

    int k;
    cout<<"enter value of k";
    cin>>k;

    if(isDuplicate(arr,n,k)) {
        cout<<"\nThere is a duplicate under k distance in the array";
    }
    else {
        cout<<"\nAll duplicates are more than k distance in the array";
    }

    return 0;
}
