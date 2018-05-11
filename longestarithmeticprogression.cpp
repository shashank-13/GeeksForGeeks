int Solution::solve(const vector<int> &A) {

    int n=(int)A.size();

    int dp[n][n];

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            dp[i][j]=1;


    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            dp[i][j]=2;
            int val = 2*A[i] - A[j];
            int index=-1;
            for(int k=i-1;k>=0;k--)
            {
                if(A[k]==val)
                {
                    index=k;
                    break;
                }
            }
            if(index!=-1)
                dp[i][j]=max(dp[i][j],dp[index][i]+1);
        }
    }

    int answer = INT_MIN;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            answer = max(answer,dp[i][j]);
        }
    }

    return answer;
}
