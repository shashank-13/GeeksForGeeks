#include<bits/stdc++.h>
using namespace std;
int getPivot(vector<int> A,int low,int high)
{
        if(low<=high)
    {
        int mid=(low+high)/2;

        if(mid+1<=high && (A[mid]>A[mid+1]))
            return mid;

                int k= binarySearch(A,low,mid-1,key);
                if(k!=-1)
                return k;
                return binarySearch(A,mid+1,high,key);
    }
    else
        return -1;
}
int binarySearch(vector<int> A,int low,int high,int key)
{
    if(low<=high)
    {
        int mid=(low+high)/2;

        //cout<<A[low]<<" "<<A[mid]<<" "<<A[high]<<" "<<key<<" "<<low<<" "<<mid<<" "<<high<<endl;
        if(A[mid]==key)
            return mid;
        else if(A[mid]>key)
        {
        return binarySearch(A,low,mid-1,key);
        }
        else
        {
        return binarySearch(A,mid+1,high,key);
        }
    }
    else
        return -1;
}
int main()
{
    int n,val,key,t;
    cin>>t;
    while(t--)
    {
       cin>>n>>key;
    vector<int>temp;
    for(int i=0;i<n;i++)
    {
        cin>>val;
        temp.push_back(val);
    }
    int g=getPivot(temp,0,temp.size()-1);

    int k1=binarySearch(temp,0,pivot,key);
    int k2=binarySearch(temp,pivot+1,n-1,key);
    if(k1==-1 && k2==-1)
        cout<<"OOPS! NOT FOUND\n";
    else
    {
        if(k1!=-1)
            cout<<k1+1<<endl;
        else
            cout<<k2+1<<endl;
    }

    }
        return 0;
}
