#include<bits/stdc++.h>
using namespace std;
#define MAX 1010
int n,m;
long long first[MAX],second[MAX],dp[MAX][MAX];
long long getMax(int i,int j)
{
    if(i>=n || j>=m)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    
    if(i+(m-j)>n)
    {
     dp[i][j]=0;
     return dp[i][j];
    }
        //cout<<i<<" "<<j<<endl;
    dp[i][j] = max((first[i]*second[j])+getMax(i+1,j+1),getMax(i+1,j));
    return dp[i][j];
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        for(int i=0;i<MAX;i++)
        {
            for(int j=0;j<MAX;j++)
                dp[i][j]=-1;
        }
        cin>>n>>m;
        for(int i=0;i<n;i++)
            cin>>first[i];
        for(int i=0;i<m;i++)
            cin>>second[i];
        cout<<getMax(0,0)<<endl;
    }
    return 0;
}
