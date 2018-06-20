int Solution::calculateMinimumHP(vector<vector<int> > &A) {
    
    int n = (int)A.size();
    int m= (int)A[0].size();
    
    int dp[n][m];
    
    dp[n-1][m-1]=(A[n-1][m-1]>0)?1:1-A[n-1][m-1];
    
    //Filling bottom row
    for(int i=m-2;i>=0;i--)
    {
        dp[n-1][i] = max(dp[n-1][i+1]-A[n-1][i],1);
    }
    
    //Filling top row
    
    for(int i=n-2;i>=0;i--)
    {
        dp[i][m-1]=max(dp[i+1][m-1]-A[i][m-1],1);
    }
    
    for(int i=n-2;i>=0;i--)
    {
        for(int j=m-2;j>=0;j--)
        {
          int min_points = min(dp[i+1][j],dp[i][j+1]);
          dp[i][j]=max(min_points-A[i][j],1);
        }
    }
    
    return dp[0][0];
    
}
