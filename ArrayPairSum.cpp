#include<bits/stdc++.h>
using namespace std;
#define MAX 100009
int counts[MAX];
int main()
{
    int t,n,k;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        cin>>k;
        if(n%2)
            cout<<"False\n";
        else
        {
            for(int i=0;i<k;i++)
            counts[i]=0;

            for(int i=0;i<n;i++)
            {
            arr[i]=arr[i]%k;
            counts[arr[i]]++;
            }
       int flag=0;
        for(int i=0;i<n;i++)
        {
            counts[arr[i]]--;
            counts[k-arr[i]]--;
            //cout<<arr[i]<<" "<<counts[arr[i]]<<" "<<k-arr[i]<<" "<<counts[k-arr[i]]<<endl;
            if(counts[arr[i]]<0 || counts[k-arr[i]]<0)
            {
                flag+=2;
            }
        }
        if(flag==n)
            cout<<"True\n";
        else
            cout<<"False\n";
        }
    }
    return 0;
}
