#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,sum;
    cin>>t;
    while(t--)
    {
        cin>>n>>sum;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        int left,right;
        left=1;
        right=0;
     int total_sum=0;
     for(int i=0;i<n;i++)
     {
         total_sum+=arr[i];
         right++;
         while(total_sum>sum)
         {
             total_sum-=arr[left-1];
             left++;
         }
         if(total_sum==sum)
            break;
     }
     if(total_sum==sum)
        cout<<left<<" "<<right<<endl;
     else
        cout<<-1<<endl;

    }
    return 0;
}
