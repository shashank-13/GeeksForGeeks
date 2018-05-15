int Solution::solve(const vector<int> &A, const vector<int> &B, const vector<int> &C) {

    int max_val=INT_MIN;
    for(int i=0;i<(int)A.size();i++)
    {
        max_val = max(max_val,A[i]);
    }
    max_val++;
    int dp[max_val];
    fill(dp,dp+max_val,INT_MAX);
    dp[0]=0;
    max_val--;
    for(int i=1;i<=max_val;i++)
    {
        for(int j=0;j<(int)B.size();j++)
        {
            if(i-B[j]>=0)
            {
                dp[i]=min(dp[i],dp[i-B[j]]+C[j]);
            }
        }
    }
    int answer = 0;
    for(int i=0;i<(int)A.size();i++)
    {
        answer+=dp[A[i]];
    }
    return answer;
}
