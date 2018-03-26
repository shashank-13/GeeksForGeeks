#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int arr[n],left[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        int current_max=INT_MIN;
        for(int i=0;i<n;i++)
        {
            left[i]=current_max;
            current_max=max(current_max,arr[i]);
        }
        vector<int>star,superstar;
        current_max=INT_MIN;
        for(int i=n-1;i>=0;i--)
        {
            if(arr[i]>current_max)
            {
                current_max=arr[i];
                star.push_back(arr[i]);
                if(arr[i]>left[i])
                    superstar.push_back(arr[i]);
            }
        }
        for(int i=star.size()-1;i>=0;i--)
            cout<<star[i]<<" ";
        cout<<endl;
        if(superstar.size()==0)
            cout<<"-1\n";
        else
        {
            for(int i=superstar.size()-1;i>=0;i--)
            cout<<superstar[i]<<" ";
        cout<<endl;
        }
    }
    return 0;
}
