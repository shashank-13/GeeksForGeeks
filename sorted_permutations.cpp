#define MOD (long long)1000003
long long factorial[58];
bool visited[58];
int ranks[58];
void precompute()
{
    factorial[0]=1;
    for(long long i=1;i<=57;i++)
    {
        factorial[i] = (factorial[i-1]%MOD * (i%MOD))%MOD;
    }
}
int Solution::findRank(string A) {
    precompute();
    long long diff=65;
    fill(visited,visited+58,false);
    fill(ranks,ranks+58,0);

    string B = A;
    sort(B.begin(),B.end());

    for(int i=0;i<B.length();i++)
    {
        ranks[B[i]-diff]=i;
    }

    long long final_answer =0;

    long long n = A.length();
    for(int i=0;i<A.length();i++)
    {
        long long temp = ranks[A[i]-diff];
        long long k=A[i]-diff;
        for(int j=0;j<58;j++)
        {
            if(visited[j] && j<k)
                temp--;
        }
        if(temp>0)
        {
            temp = (factorial[n-1]%MOD * temp%MOD)%MOD;
            final_answer = (final_answer%MOD + temp%MOD)%MOD;
           // cout<<n<<" "<<temp<<" "<<final_answer<<endl;
        }
        visited[k] = true;
        n--;
    }
    final_answer=(final_answer%MOD + 1%MOD)%MOD;

    return final_answer;
}

