vector<vector<int>>Ar;
vector<vector<int>>B(2);
int get(int i,int j,int n)
{
    if(j>=n)
        return 0;

    if(B[i][j])
        return B[i][j];

    if(i==0)
    {
        B[i][j]=max(Ar[i][j]+get(i,j+2,n),max(Ar[i][j]+get(i+1,j+2,n),get(i,j+1,n)));
    }
    else
    {
     B[i][j]=max(Ar[i][j]+get(i,j+2,n),max(Ar[i][j]+get(i-1,j+2,n),get(i,j+1,n)));
    }

    return B[i][j];

}
int Solution::adjacent(vector<vector<int> > &A) {

    Ar.clear();
    B.clear();
    Ar.push_back(A[0]);
    Ar.push_back(A[1]);
    int m=(int)A[0].size();
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<m;j++)
            B[i].push_back(0);
    }

    return max(get(0,0,m),get(1,0,m));
}

