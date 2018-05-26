int Solution::maxcoin(vector<int> &A) {
    
    int n=(int)A.size();
    int dp[n][n];
    int a,b;
    
    for(int i=0;i<n-1;i++)
    {
        dp[i][i+1]=max(A[i],A[i+1]);
        dp[i][i]=A[i];
    }
    dp[n-1][n-1]=A[n-1];
    
    for(int i=3;i<=n;i++)
    {
        for(int j=0;j+i<n;j++)
        {
            a=j;
            b=j+i-1;
            dp[a][b]=max(A[a]+min(dp[a+2][b],dp[a+1][b-1]),A[b]+min(dp[a][b-2],dp[a+1][b-1]));
        }
    }
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    
}
