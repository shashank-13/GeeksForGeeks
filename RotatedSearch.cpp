#include<bits/stdc++.h>
using namespace std;
int getPivot(vector<int>A,int low,int high)
{
    if(low==high)
        return low;
    else if(low<=high)
    {
        int mid=(low+high)/2;
        if(mid<high && A[mid+1]<A[mid])
            return mid+1;
        else if(low<mid && A[mid]<A[mid-1])
            return mid;
        else
        {
            if(A[high]>A[mid])
                return getPivot(A,low,mid-1);
            else
                return getPivot(A,mid+1,high);
        }
    }
    else
    {
        return 0;
    }
}
int binarySearch(vector<int> A,int low,int high,int key)
{
    if(low<=high)
    {

        int mid=(low+high)/2;

        cout<<low<<" "<<mid<<" "<<high<<" "<<key<<A[mid]<<endl;
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
    int pivot=getPivot(temp,0,temp.size()-1);

    //cout<<"Pivot Index "<<temp[pivot]<<endl;

     if(key>=temp[pivot] && key<=temp[temp.size()-1])
     {
        // cout<<"Right Index "<<pivot<<" "<<temp.size()-1<<endl;
         int fix=binarySearch(temp,pivot,temp.size()-1,key);
         if(fix!=-1)
         cout<<fix<<endl;
         else
         cout<<"OOPS! NOT FOUND\n";

     }

    else if(pivot>0)
    {
        //cout<<"Left Index 0 "<<pivot<<endl;
        int fix=binarySearch(temp,0,pivot,key);
        if(fix!=-1)
         cout<<fix<<endl;
         else
         cout<<"OOPS! NOT FOUND\n";
    }

    else
 cout<<"OOPS! NOT FOUND\n";

    }
        return 0;
}

