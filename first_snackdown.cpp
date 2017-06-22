#include<bits/stdc++.h>
using namespace std;
long long getNormalSearch(long long arr[],long long  low,long long  high,long long key)
{
    if(low<=high)
    {
        long long  mid=(low+high)/(long long )2;
        if(arr[mid]>= key && (mid==low || arr[mid-1]<key))
            return mid;
        else if(arr[mid]>=key)
           return getNormalSearch(arr,low,mid-1,key);
        else if(arr[mid]<key)
            return getNormalSearch(arr,mid+1,high,key);

    }
    else
    {
        return (long long )-1;
    }
}
int main()
{
    long long  t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        long long arr[n];
        long long total_sum=0;
        for(int i=0;i<n;i++)
        {
              cin>>arr[i];
              total_sum+=arr[i];

        }
        sort(arr,arr+n);

          long long grt_cnt=1;
          long long nex_try=1;
          long long low=0;

          for(long long i=0;i<n;i++)
          {

              long long x = getNormalSearch(arr,low,n-1,nex_try);
              if(x==-1)
                break;
              else if(n!=1 && n-x==1)
              {
                  grt_cnt++;
                  break;
              }
              else{
                low=x+2;
                grt_cnt=nex_try;
                nex_try++;
              }
          }

          cout<<total_sum-(grt_cnt*grt_cnt)<<endl;
    }
}
