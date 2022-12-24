#include<iostream>
#include<map>

using namespace std;

bool arePairsFound(int arr[],int n)  //complexity=O(n^2).
{
pair<int,int> pp;
map<int, pair<int,int> > dataset;  //store information in this way:-
                                   //   sum--->(index1,index2)
for(int i=0;i<n-1;i++)             //   7--->(3,4)
{                                  //   10-->(3,7)
  for(int j=i+1;j<n;j++)           //   4--->(3,1)  if sum is found then print previous pair and 2 new values in the array.
  {
      int sum=arr[i]+arr[j];

      if(dataset.find(sum)==dataset.end())
      {
          dataset[sum]=make_pair(i,j);
      }

      else{

        pp=dataset[sum];  //pp points to the founded sum.
        if(arr[pp.first]!=arr[i] && arr[pp.second]!=arr[j])  //if all 4 keys are different.
        {
        cout<<"pairs are"<<"("<<arr[pp.first]<<","<<arr[pp.second]<<")"<<"and"<<"("<<arr[i]<<","<<arr[j]<<")"<<endl;
        return true;
        }

      }


  }


}

cout<<"no pairs found";

return false;


}


int main()
{
     int n,arr[20];
     cout<<"enter length of array";
     cin>>n;
     cout<<"enter values in array";
     for(int i=0;i<n;i++)
     {
         cin>>arr[i];
     }

    arePairsFound(arr,n);


    return 0;

}
