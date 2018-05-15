
int Solution::numTrees(int A) {
    long long dp[A+1];
    dp[0]=1;
    for(int i=1;i<=A;i++)
    {
        long long sum=0;
        for(int j=1;j<=i;j++)
        {
            sum=(sum+dp[j-1]*dp[i-j]);
        }
        dp[i]=sum;
    }
    return dp[A];
}
