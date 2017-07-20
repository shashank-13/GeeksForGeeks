#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int arr[n];
        bool flag=true;
        int min_answer=INT_MIN;
        for(int i=0;i<n;i++)
        {
             cin>>arr[i];
             if(arr[i]>=0)
                flag=false;
             min_answer=max(min_answer,arr[i]);
        }
        if(flag)
            cout<<min_answer<<endl;
        else
        {
         int current_sum,max_sum;
          current_sum=max_sum=0;
         for(int i=0;i<n;i++)
         {
             current_sum+=arr[i];
             if(current_sum<0)
                current_sum=0;
             else
                max_sum=max(max_sum,current_sum);
         }
          cout<<max_sum<<endl;
        }

    }
    return 0;
}
