#define MAX 1001
int dp[MAX][MAX];
int getHorses(string A,int *white,int *black,int ind,int k,int n)
{
    if(k==0)
    {
        int wD=white[n];
        int bD=black[n];
        if(ind>0)
        {
         wD-=white[ind-1];
         bD-=black[ind-1];
        }
        return wD*bD;
    }

    if(dp[ind][k]!=-1)
        return dp[ind][k];

    int answer=INT_MAX;
    int bCnt,wCnt;
    bCnt=wCnt=0;
    for(int i=ind;i<=n-k;i++)
    {
        if(A[i]=='W')
            wCnt++;
        else
            bCnt++;
        answer = min(answer,(bCnt*wCnt)+getHorses(A,white,black,i+1,k-1,n));
    }
    dp[ind][k]=answer;
    return answer;
}
int Solution::arrange(string A, int B) {

    int ind=0;
    while(ind < A.length() && (A[ind]=='W' || A[ind]=='B'))
    {
      ind++;
    }

    A=A.substr(0,ind);


    if( B==0 || B > A.length())
        return -1;

    for(int i=0;i<MAX;i++)
        for(int j=0;j<MAX;j++)
            dp[i][j]=-1;

    int n=A.length();
    int black[n],white[n];
    fill(black,black+n,0);
    fill(white,white+n,0);
    if(A[0]=='W')
        white[0]=1;
    else
        black[0]=1;

    for(int i=1;i<n;i++)
    {
        if(A[i]=='W')
        white[i]=1;
        else
           black[i]=1;
        white[i]+=white[i-1];
         black[i]+=black[i-1];
    }
    int answer=getHorses(A,white,black,0,B-1,n-1);
  return answer;

}
