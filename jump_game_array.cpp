
int Solution::canJump(vector<int> &A) {

    int n=(int)A.size();
    int dp[n];
    fill(dp,dp+n,0);
    dp[0]=1;

    for(int i=0;i<n;i++)
    {
        if(dp[i])
        {
            for(int j=1;j<=A[i];j++)
            {
                int var=min(n-1,i+j);
                dp[var]=1;
            }
        }
    }
    return dp[n-1];
}
