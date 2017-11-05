#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,m;
    string a,b;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        cin>>a;
        cin>>b;
        int answer[n+1][m+1];
        for(int i=0;i<=n;i++)
            answer[i][0]=0;
        for(int i=0;i<=m;i++)
            answer[0][i]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(a[i-1]==b[j-1])
                    answer[i][j]=1+answer[i-1][j-1];
                else
                {
                    answer[i][j]=max(answer[i-1][j],answer[i][j-1]);
                }
            }
        }


                cout<<answer[n][m]<<endl;

    }
    return 0;
}
