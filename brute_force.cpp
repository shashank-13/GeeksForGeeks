#include<bits/stdc++.h>
using namespace std;
#define MAX 100005

long long arr[MAX];

// Segment tree part
long long  index_s;



long long getNormalSearch(long long  low,long long  high,long long key)
{
    if(low<=high)
    {
        long long  mid=(low+high)/(long long )2;
        if(arr[mid]>= key && (mid==0 || arr[mid-1]<key))
            return mid;
        else if(arr[mid]>=key)
           return getNormalSearch(low,mid-1,key);
        else if(arr[mid]<key)
            return getNormalSearch(mid+1,high,key);

    }
    else
    {
        return (long long )-1;
    }
}

int main()
{

    long long  t,n,k,q;
    scanf("%lld",&t);
     ofstream out_file;
        out_file.open("output1.in");
    while(t--)
    {
        scanf("%lld %lld",&n,&q);
        for(int i=0;i<n;i++){

            scanf("%lld",&arr[i]);

        }



        sort(arr,arr+n);





        for(int i=1;i<=q;i++)
        {
            scanf("%lld",&k);
            int first_index=getNormalSearch(0,n-1,k);


            if(first_index==0)
            {
                out_file<<n<<endl;
            }
            else
            {
                int answer=0;
                if(first_index==-1)
                    index_s=n-1;
                else
                {
                    answer+=(n-first_index);
                    index_s=first_index-(long long)1;
                }

                int rem=index_s;

                   for(int i=index_s;i>=0;i--)
                   {
                       if(k-arr[i]<=rem)
                       {
                           rem-=(k-arr[i]+1);
                           answer++;
                       }
                       else
                       {
                           break;
                       }
                   }

                    out_file<<answer<<endl;

            }
        }
    }

    return 0;
}

