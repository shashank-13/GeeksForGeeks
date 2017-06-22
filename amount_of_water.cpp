#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int arr[n],left_max[n],right_max[n];
        for(int i=0;i<n;i++)
            scanf("%d",&arr[i]);
        left_max[0]=arr[0];
        right_max[n-1]=arr[n-1];

        for(int i=1;i<n-1;i++)
        {
            if(arr[i]>left_max[i-1])
                left_max[i]=arr[i];
            else
                left_max[i]=left_max[i-1];
        }
        for(int i=n-2;i>0;i--)
        {
            if(arr[i]>right_max[i+1])
                right_max[i]=arr[i];
            else
                right_max[i]=right_max[i+1];
        }

        int total_water=0;

        for(int i=1;i<n-1;i++)
        {
            if(left_max[i]>=arr[i] && right_max[i]>=arr[i])
            {

                total_water+=min(left_max[i]-arr[i],right_max[i]-arr[i]);
            }

        }
        printf("%d\n",total_water);
    }
    return 0;
}
