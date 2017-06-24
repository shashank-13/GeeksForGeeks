#include<bits/stdc++.h>
using namespace std;
struct node
{
    int a,b;
};

bool comparator(node &f1,node &f2)
{
    if(f1.a==f2.a)
        return f1.b<f2.b;
    else
        return f1.a < f2.a;
}

int getBinaryIndex(node arr[],int low,int high,int index)
{

    if(low<=high)
    {
        int mid=(low+high)/2;
        bool flag=false;;
        if(arr[index].a>arr[mid].b || arr[mid].a>arr[index].b)
            flag=true;
        bool flag1=false;
        if(mid-1>=low)
        {
            if(arr[index].a>arr[mid-1].b || arr[mid-1].a>arr[index].b)
            flag1=true;
        }
        if(flag &&(!flag1))
        {
           // cout<<"returned called"<<endl;
             return mid;
        }

        else if(!flag)
        {
            //cout<<"Higher part called"<<endl;
            return getBinaryIndex(arr,mid+1,high,index);
        }

        else
        {
            //cout<<"Lower part called"<<endl;
            return getBinaryIndex(arr,low,mid-1,index);
        }

    }
    else
    {

        return -1;
    }
}

int main()
{
    int t,n;
    string s;
    cin>>t;
    while(t--)
    {
        cin>>n;
        node arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>s;
            if(s.length()==4)
            {
                string S1=s.substr(0,2);
                string S2=s.substr(2);
                int a=stoi(S1)*60 + stoi(S2);
                arr[i].a=a;
            }
            else
            {
                string S1=s.substr(0,1);
                string S2=s.substr(1);
                int a=stoi(S1)*60 + stoi(S2);
                arr[i].a=a;
            }
        }
        for(int i=0;i<n;i++)
        {
            cin>>s;
            if(s.length()==4)
            {
                string S1=s.substr(0,2);
                string S2=s.substr(2);
                int b=stoi(S1)*60 + stoi(S2);
                arr[i].b=b;
            }
            else
            {
                string S1=s.substr(0,1);
                string S2=s.substr(1);
                int b=stoi(S1)*60 + stoi(S2);
                arr[i].b=b;
            }
        }
        sort(arr,arr+n,&comparator);

     //   int temp_index=getBinaryIndex(arr,0,n-1,0);

        int final_answer=1;
       for(int i=0;i<n;i++)
       {
           int temp_index=getBinaryIndex(arr,i,n-1,i);
           if(temp_index==-1)
            temp_index=n-1;
            final_answer=max(final_answer,temp_index-i);

       }
       cout<<final_answer<<endl;
    }

    return 0;
}
