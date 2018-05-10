int Solution::nTriang(vector<int> &A) {

    sort(A.begin(),A.end());
    long long index = upper_bound(A.begin(),A.end(),0) - A.begin();
    int n=(int)A.size();
    long long mod=1000000007;
    long long answer=0;

    for(long long i=index;i<=n-3;i++)
    {
        long long k= i+2;
        for(long long j=i+1;j<=n-2;j++)
        {
            while(k<n && A[i]+A[j]>A[k])
                k++;
            answer = (answer%mod + (k-j-1)%mod)%mod;
        }
    }

    return answer;
}

