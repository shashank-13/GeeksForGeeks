#include<bits/stdc++.h>
using namespace std;
int binarySearch(int arr[],int low,int high,int key)
{
    if(low<=high)
    {
        int mid = (low+high)/2;
        if(arr[mid]==key)
            return mid;
        else if(arr[mid]<key)
            return binarySearch(arr,mid+1,high,key);
        else
            return binarySearch(arr,low,mid-1,key);
    }
    else
        return -1;
}
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
        sort(arr,arr+n);
        bool flag=false;
        for(int i=0;i<n;i++)
        {
            int other_number = sum-arr[i];
            int index=binarySearch(arr,0,n-1,other_number);
            if(index!= -1 && index!=i)
            {
                flag=true;
                break;
            }
        }
        if(flag)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}
