#include <bits/stdc++.h>
using namespace std;

void LongestIncreasingSubSequence(int n,int arr[])
{
   int LIS[n];

   for(int i=0;i<n;i++)
      LIS[i]=1;

   for(int i=1;i<n;i++)
   {
      for(int j=0;j<i;j++)
      {
         if(arr[i] > arr[j])
         {
            LIS[i] = max(LIS[i],LIS[j] +  1);
         }
      }
   }

   for(int i=0;i<n;i++)
   {
      cout<<i<<"->"<<LIS[i]<<endl;
   }
}


int main()
{
    int arr []= {10,22,9,33,21,50,41,60};
    LongestIncreasingSubSequence(8,arr);
    return 0;
}
