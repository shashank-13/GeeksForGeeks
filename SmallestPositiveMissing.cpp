#include<bits/stdc++.h>
using namespace std;
void swap(int *a,int *b)
{
    int temp =*a;
    *a=*b;
    *b=temp;
}
int getFirstMissing(int *arr,int n)
{
    for(int i=0;i<n;i++)
    {
        if(abs(arr[i])>0 && abs(arr[i])-1<n && arr[abs(arr[i])-1] >0)
        {
            arr[abs(arr[i])-1]=-arr[abs(arr[i])-1];
        }
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i]>0)
            return i+1;
    }
    return n+1;
}
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        int total_count =0;
        for(int i=0;i<n;i++)
        {
        if(arr[i]<=0){
                swap(&arr[i],&arr[total_count]);
        total_count++;
                    }
        }
        cout<<getFirstMissing(arr+total_count,n-total_count)<<endl;
    }
    return 0;
}
