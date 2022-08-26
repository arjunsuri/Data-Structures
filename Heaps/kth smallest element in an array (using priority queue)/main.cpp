#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int kthSmallestElement(int arr[], int n, int k) {

priority_queue <int> max_priority;

for(int i=0; i<n; i++) {

    if(max_priority.size() >= k) {
      if(arr[i] < max_priority.top()) {
         max_priority.pop();
         max_priority.push(arr[i]);
        }
    } else {
      max_priority.push(arr[i]);
    }
}

return max_priority.top();
}

int main()
{
    int arr[] = {1, 5, 4, 9, 14, 2, 54, 34, 21};
    int n = 9;
    int k = 6;

    cout << k << "th smallest element:-" << endl;
    cout<< kthSmallestElement(arr, n, k);

    return 0;
}
