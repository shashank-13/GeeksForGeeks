#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long  t,n,k;
    cin>>t;
    while(t--)
    {
        cin>>n;
        long long arr[n];

    for(int i=0;i<n;i++)
        cin>>arr[i];

    cin>>k;


    long long prefix[n+1];

    for(int i=0;i<=n;i++)
        prefix[i]=0;

        prefix[n-1]=arr[n-1];
    for(int i=n-2;i>=n-k;i--)
    {
        prefix[i]=prefix[i+1]+arr[i];
    }

    long long final_answer=prefix[n-k];

    for(int i=n-k-1;i>=0;i--)
    {
       // cout<<arr[i]<<" "<<prefix[i+1]<<" "<<prefix[i+k]<<endl;
        prefix[i]=max(arr[i]+prefix[i+1],arr[i]+prefix[i+1]-prefix[i+k]);
        final_answer=max(final_answer,prefix[i]);
       //cout<<final_answer<<" "<<prefix[i]<<endl;
    }

    cout<<final_answer<<endl;

    }
    return 0;
}
