#include <bits/stdc++.h>

using namespace std;

void addElements(vector<int> arr[], int u, int v) {
  arr[u].push_back(v);
  arr[v].push_back(u);
}

void printGraph(vector<int> arr[], int V) {
   for(int i=0; i<V; i++) {
     vector<int> vec = arr[i];
     for(int j=0; j<vec.size(); j++) {
        cout<<vec[j]<<" ";
     }
     cout<<endl;
   }
}

int main() {
    int V = 5;
    vector<int> arr[V];
    addElements(arr, 0, 1);
    addElements(arr, 1, 2);
    addElements(arr, 2, 3);
    addElements(arr, 1, 3);
    addElements(arr, 3, 4);
    printGraph(arr, V);

    return 0;
}
