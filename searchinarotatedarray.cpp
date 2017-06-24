#include<bits/stdc++.h>
using namespace std;
int getBinaryIndex(int arr[],int low,int high,int key)
{

    if(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]==key)
        {
             return mid;
        }

        else if(arr[mid]<key)
        {
            return getBinaryIndex(arr,mid+1,high,key);
        }

        else
        {

            return getBinaryIndex(arr,low,mid-1,key);
        }

    }
    else
    {

        return -1;
    }
}

int main()
{
    int t,n,k;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];

            cin>>k;
        int index=-1;
        for(int i=0;i<n;i++)
        {
            if(i+1<n && arr[i+1]< arr[i])
            {
                index=i+1;
                break;
            }

        }
        if(index==-1)
        {
            cout<<getBinaryIndex(arr,0,n-1,k)<<endl;
        }
        else
        {
            int f=getBinaryIndex(arr,0,index-1,k);
            if(f!=-1)
                cout<<f<<endl;
            else
            {
                cout<<getBinaryIndex(arr,index,n-1,k)<<endl;
            }
        }

    }

    return 0;
}
