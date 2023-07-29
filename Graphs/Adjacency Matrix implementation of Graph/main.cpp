#include <iostream>

using namespace std;

int main()
{
    int n, m, u, v;
    cout<<"Enter no. of vertices:-"<<endl;
    cin >> n;
    cout<<"Enter no. of edges:-"<<endl;
    cin>>m;

    int adjMat[n][n];

    for(int i = 0; i < n; i++) {
       for(int j = 0; j < n; j++) {
         adjMat[i][j] = 0;
       }
    }

    for (int i = 0; i < m; i++) {
        cout<<"Enter first vertex of edge:-"<<endl;
        cin>>u;
        cout<<"Enter second vertex of edge:-"<<endl;
        cin>>v;
        adjMat[u][v] = 1;
        adjMat[v][u] = 1;
    }


    for(int i=0; i<n; i++) {
       for(int j=0; j<n; j++) {
        cout << adjMat[i][j] << " ";
       }
       cout<<endl;
    }

    return 0;
}
