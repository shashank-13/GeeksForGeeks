int Solution::maximalRectangle(vector<vector<int> > &A) {

    int n=(int)A.size();
    int m=(int)A[0].size();

    int dp[n][m];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            dp[i][j]=0;

    for(int i=0;i<n;i++)
    {
        for(int j=m-1;j>=0;j--)
        {
            if(A[i][j]>0)
                dp[i][j]=(j==m-1)?1:dp[i][j+1]+1;
        }
    }

    int answer = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(dp[i][j]>0)
            {
                int k = i;
                int length = dp[i][j];
                while(k<n && dp[k][j]!=0)
                {
                    length=min(length,dp[k][j]);
                    int area = length *(k-i+1);
                    //cout<<i<<" "<<i+dp[i][j]-1<<" "<<k<<" "<<k+dp[k][j]-1<<" "<<area<<endl;
                    answer = max(area,answer);
                    k++;
                }
            }

        }
    }

    return answer;
}

