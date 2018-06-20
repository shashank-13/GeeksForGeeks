int Solution::isInterleave(string A, string B, string C) {
    
    int a = A.length();
    int b = B.length();
    int c = C.length();
    
    if(a+b!=c)
        return 0;
    
    bool dp[c+1][a+1][b+1];
    
    for(int i=0;i<=a;i++)
    {
        for(int j=0;j<=b;j++)
        {
            dp[0][i][j]=1;
        }
    }
    
    for(int i=0;i<=c;i++)
    {
        for(int j=0;j<=b;j++)
        {
            dp[i][0][j]=1;
        }
    }
    
     for(int i=0;i<=c;i++)
    {
        for(int j=0;j<=a;j++)
        {
            dp[i][j][0]=1;
        }
    }
    
    
    for(int k=1;k<=c;k++)
    {
        for(int i=1;i<=a;i++)
        {
            for(int j=1;j<=b;j++)
            {
                if(C[k-1]==A[i-1] && C[k-1]==B[j-1])
                {
                    dp[k][i][j] = dp[k-1][i-1][j] || dp[k-1][i][j-1];
                }
                else if(C[k-1]==A[i-1])
                {
                    dp[k][i][j] = dp[k-1][i-1][j];
                }
                else if(C[k-1]==B[j-1])
                {
                    dp[k][i][j] = dp[k-1][i][j-1];
                }
                else
                    dp[k][i][j] = 0;
            }
        }
    }
    
   return dp[c][a][b];
}
