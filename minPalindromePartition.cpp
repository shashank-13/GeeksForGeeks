#define MAX 1005
int palindrome[MAX][MAX];
int dp[MAX];
int getMinCut(int ind,int n)
{
    if(ind>=n)
        return 0;

    if(dp[ind]!=-1)
        return dp[ind];

    int answer = INT_MAX;
    for(int i=1;i<=n-ind;i++)
    {

            if(palindrome[ind][ind+i-1]){
                int cut=0;
                if(ind+i<n)
                    cut++;
                answer=min(answer,cut+getMinCut(ind+i,n));
            }
    }
    //cout<<ind<<" "<<answer<<endl;
    dp[ind]=answer;
    return answer;
}
int Solution::minCut(string A) {

    int n=A.length();

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
            {
                palindrome[i][j]=1;
            }
            else
            {
                palindrome[i][j]=0;
            }
        }
        dp[i]=-1;
    }
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<=n-i;j++)
        {
            if(A[j]==A[j+i-1] && (i==2 || palindrome[j+1][j+i-2]>0))
                palindrome[j][j+i-1]=i;
        }
    }

    return getMinCut(0,n);

}
