int Solution::numDecodings(string A) {

    int n=A.length();
    int dp[n];
    fill(dp,dp+n,0);

    for(int i=0;i<n;i++)
    {
        if(i>0 && ((A[i-1]=='1')||(A[i-1]=='2' && A[i]-48<=6)) && dp[i-1]>0)
        {
            if(A[i]-48 > 0)
                dp[i]=dp[i-1];
            if(i>1)3
                dp[i]+=dp[i-2];
            else
                dp[i]+=dp[i-1];
        }
        else
        {
            if(A[i]-48>0)
                dp[i]=(i==0)?1:dp[i-1];
        }
    }

    /*for(int i=0;i<n;i++)
    {
        cout<<A.substr(0,i+1)<<" "<<dp[i]<<endl;
    }*/
    return dp[n-1];
}

