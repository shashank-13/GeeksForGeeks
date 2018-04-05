#include<bits/stdc++.h>
using namespace std;
int getRotatedIndex(int *arr,int low,int high,int n)
{
    if(low<=high)
    {
        int mid = (low+high)/2;
        if((mid==0 || arr[mid]>arr[mid-1]) &&(mid==n-1 || arr[mid]>arr[mid+1]))
            return mid;
        else if((mid==0 || arr[mid]>arr[mid-1]) &&(mid==n-1 || arr[mid]<arr[mid+1]))
            return getRotatedIndex(arr,mid+1,high,n);
        else if ((mid==0 || arr[mid]<arr[mid-1]) &&(mid==n-1 || arr[mid]>arr[mid+1]))
            return getRotatedIndex(arr,low,mid-1,n);
        else
            return -1;
    }
    else
    {
        return -1;
    }
}
int binarySearch(int *arr,int low,int high,int key)
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
    {
        return -1;
    }
}
int binarySearchReverse(int *arr,int low,int high,int key)
{
    if(low<=high)
    {
        int mid = (low+high)/2;
        if(arr[mid]==key)
            return mid;
        else if(arr[mid]<key)
            return binarySearchReverse(arr,low,mid-1,key);
        else
            return binarySearchReverse(arr,mid+1,high,key);
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
        cin>>n>>k;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        int index = getRotatedIndex(arr,0,n-1,n);
        if(index==-1)
        {
            int answer = binarySearch(arr,0,n-1,k);
            if(answer==-1)
                cout<<"OOPS! NOT FOUND\n";
            else
                cout<<answer<<endl;
        }
        else
        {
           // cout<<"Index "<<index<<" "<<arr[index]<<endl;
            if(arr[index]==k)
                cout<<index<<endl;
             else if(binarySearch(arr,0,index-1,k)!=-1)
             {
                 cout<<binarySearch(arr,0,index-1,k)<<endl;
             }
             else if(binarySearchReverse(arr,index+1,n-1,k)!=-1)
             {
                 cout<<binarySearchReverse(arr,index+1,n-1,k)<<endl;
             }
             else
                cout<<"OOPS! NOT FOUND\n";
        }
    }
    return 0;
}
