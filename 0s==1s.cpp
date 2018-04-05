#include<bits/stdc++.h>
using namespace std;
int main()
{
 int t,n;
 cin>>t;
 while(t--)
 {
     cin>>n;
     int arr[n];
     int sum[n+1];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        sum[i]=0;
    }
    sum[n]=0;
    sum[0]=0;
    for(int i=0;i<n;i++)
    sum[i+1]+=sum[i]+arr[i];
    int answer=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j+=2)
        {
            if(((j-i+1)/2)==(sum[j+1]-sum[i]))
            {
                if(answer<(j-i+1))
                {
                    answer=j-i+1;
                 //    cout<<i+1<<" "<<j+1<<" "<<answer<<endl;
                }

            }
        }
    }
    cout<<answer<<endl;

 }
 return 0;
}
