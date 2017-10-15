#include<bits/stdc++.h>
using namespace std;
bool visited[1000001];
int binarySearch(int arr[],int low,int high,int key)
{
    if(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]==key)
            return mid;
        else if(arr[mid]>key)
            return binarySearch(arr,low,mid-1,key);
        else
            return binarySearch(arr,mid+1,high,key);
    }
    else
        return -1;
}
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int arr[n],brr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            brr[i]=arr[i];
            visited[arr[i]]=false;
        }
        sort(brr,brr+n);
        if(n==1)
            printf("%d\n",arr[0]);
        else
        {
            for(int i=0;i<n;i++)
            {
                visited[arr[i]]=true;
                if(i==n-1)
                    printf("%d\n",arr[i]);
                else
                {
                    if(i-1>=0 && i+1<n && (arr[i-1]>arr[i]) &&(arr[i+1]>arr[i])&&visited[arr[binarySearch(brr,0,n-1,arr[i])+1]])
                        printf("%d ",arr[i]);
                    else if(i-1>=0 && i+1<n && (arr[i]>arr[i-1]) &&(arr[i+1]>arr[i])&&visited[arr[binarySearch(brr,0,n-1,arr[i])+1]])
                         printf("%d ",arr[i]);
                }
            }
        }


    }
    return 0;
}
