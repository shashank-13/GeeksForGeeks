#include<bits/stdc++.h>
using namespace std;
#define MAX (long long)676
int main()
{
    long long t,n;
    char arr[28];
    for(int i=1;i<=26;i++)
    {
        arr[i]=64+i;
    }
    cin>>t;
    while(t--)
    {
        cin>>n;
        int value=n%26;
        if(n%26==0)
        {
           value=26;
        }
            n-=26;
     int count =0;
     int temp =n;

     while(temp>0)
     {
         count++;
         temp/=MAX;
     }
     if(n%MAX==0)
        count--;
     n=(n%MAX==0)?MAX:n%MAX;
     int times=n/26;
     if(n%26!=0)
        times++;

     for(int i=1;i<=count;i++)
        cout<<arr[times];
     cout<<arr[value]<<endl;

    }
    return 0;
}
