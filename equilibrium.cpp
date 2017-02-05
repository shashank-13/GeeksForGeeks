#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int input[n+1],left[n+1],right[n+1];
        left[0]=right[0]=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&input[i]);
            left[i]=right[i]=0;
        }
        if(n==1)
        {
            printf("1\n");
        }
        else
        {
        for(int i=2;i<=n;i++)
        {
            left[i]=left[i-1]+input[i-1];
        }
        for(int i=n-1;i>=1;i--)
        {
            right[i]=right[i+1]+input[i+1];
        }
        bool flag=false;
        for(int i=1;i<=n;i++)
        {
            if(left[i]==right[i])
            {
                flag=true;
                printf("%d\n",i);
                break;
            }
        }
        if(!flag)
            printf("-1\n");
        }
    }
    return 0;
}
