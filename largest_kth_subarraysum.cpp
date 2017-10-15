#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,k;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int arr[n],prefix[n];
        for(int i=0;i<n;i++)
        {
             cin>>arr[i];
                if(i==0)
                prefix[i]=arr[i];
                else
                    prefix[i]=arr[i]+prefix[i-1];
        }
         cin>>k;
        int subarray_Sum[n];

        for(int i=0;i<n;i++)
        {
         if(i==0)
            subarray_Sum[i]=arr[i];
         else
            subarray_Sum[i]=max(arr[i],arr[i]+subarray_Sum[i-1]);
        }
        int finalArray[n];
        for(int i=0;i<n;i++)
        {
            if(i<k)
            {
                finalArray[i]=prefix[i];
            }
            else
            {
                finalArray[i]=prefix[i]-prefix[i-k];
              //  cout<<finalArray[i]<<endl;

                    finalArray[i]+=max(subarray_Sum[i-k],0);

            }
        }
        int final_answer=INT_MIN;
        for(int i=k-1;i<n;i++){
           // cout<<i<<" "<<finalArray[i]<<endl;
             final_answer=max(final_answer,finalArray[i]);
        }

        printf("%d\n",final_answer);

    }
    return 0;
}
