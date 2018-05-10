int Solution::seats(string A) {

    long long mod = 10000003;
    vector<long long>index;
    for(long long i=0;i<A.length();i++)
    {
        if(A[i]=='x')
            index.push_back(i);
    }
    long long n=(long long)index.size();
    long long med = n/2;
    long long answer=0;

    for(long long i=med-1;i>=0;i--)
    {
        long long temp = index[i+1]-index[i]-1;
        answer = (answer%mod + temp%mod)%mod;
        index[i]=index[i+1]-1;
    }
    for(long long i=med+1;i<=n-1;i++)
    {
        long long temp = index[i]-index[i-1]-1;
        answer = (answer%mod + temp%mod)%mod;
        index[i]=index[i-1]+1;
    }

    return answer;
}

