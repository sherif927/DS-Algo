#include <bits/stdc++.h>
using namespace std;

int KnapsackRec(int W,int wt[],int val[],int n)
{
   if(n==0 || w==0)
      return 0;
   else if(wt[n-1] > w)
         return KnapsackRec(W,wt,val,n-1);
   else
      return max((val[n-1] + KnapsackRec(W-wt[n-1],wt,val,n-1)),
                 KnapsackRec(W,wt,val,n-1));
}

int Knapsack(int W,int wt[],int val[],int n)
{
   int K[n+1][W+1];

   for(int i=0;i<=n;i++)
   {
      for(int w=0;w<=W;w++)
      {
         if(i == 0 || w == 0)
            K[i][w] = 0;
         else if( wt[i-1] <= w )
            k[i][w] = max(val[i-1]+k[i-1][W-wt[i-1],k[i-1][w]);
         else
            k[i][w] = k[i-1][w];
      }
   }

   return k[n][W];
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
