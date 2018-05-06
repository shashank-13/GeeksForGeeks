#define MOD 1000000007
long long fact[101][101];
long long choose(long long n,long long k)
{
    if(k>n)
        return 0;
    if(n<=1)
        return 1;
    if(k==0)
    return 1;

    if(fact[n][k]!=-1)
        return fact[n][k];

    fact[n][k]=(choose(n-1,k)%MOD+choose(n-1,k-1)%MOD)%MOD;
    return fact[n][k];
}
long long power(long long n)
{
    long long answer=1;
    for(long long i=1;i<=n;i++)
    {
        answer*=2;
    }
    return answer;
}
// calculate l for give value of n
long long getLeft(long long n)
{
	if (n == 1)
		return 0;

	long long h = log2(n);


	long long numh = (1 << h); //(2 ^ h)


	long long last = n - ((1 << h) - 1);

	// if more than half-filled
	if (last >= (numh / 2))
		return (1 << h) - 1; // (2^h) - 1
	else
		return (1 << h) - 1 - ((numh / 2) - last);
}

long long getMaxHeap(long long n)
{
    if(n<=1)
        return 1;

    long long l=getLeft(n);


    long long answer = choose(n-1,l);
    return ((answer%MOD * getMaxHeap(l)%MOD)%MOD *getMaxHeap(n-1-l)%MOD)%MOD;

}
int Solution::solve(int A) {


    for(int i=0;i<=100;i++)
    {
        for(int j=0;j<=100;j++)
            fact[i][j]=-1;
    }

    return getMaxHeap(A);
}

