#include <iostream>
#include<map>

using namespace std;

bool checkPair(int arr[],int n,int k) {

    if(n%2 != 0)
      return false;

    map<int,int> freq;

    for(int i=0; i<n; i++) {
        freq[((arr[i]%k)+k)%k]++;
    }

    for(int i=0; i<n; i++) {
        int rem = ((arr[i]%k)+k)%k;

        if((k/2) == rem) {
            if(freq[rem]%2 != 0) {
                return false;
            }
        }
        else if(rem == 0) {
            if(freq[rem]%2 != 0) {
                 return false;
            }
        }
        else {
            if(freq[rem] != freq[k-rem]) {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int arr[]={92,76,65,48,45,34};
    int n=6;
    int k=10;

    if(checkPair(arr,n,k)) {
        cout<<"array can be divided in pairs.";
    }
    else {
        cout<<"array cannot be divided in pairs.";
    }

    return 0;
}
