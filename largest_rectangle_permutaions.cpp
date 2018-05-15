int Solution::solve(vector<vector<int> > &A) {

    int n=(int)A.size();
    int m=(int)A[0].size();

    vector<int>counts[n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            counts[i].push_back(0);
    }

    for(int j=0;j<m;j++)
    {
        for(int i=n-1;i>=0;i--)
        {
            if(A[i][j]==1)
                counts[i][j]=1;
            if(i<n-1 && A[i][j]>0)
                counts[i][j]+=counts[i+1][j];
        }
    }
    int answer = 0;
    for(int i=0;i<n;i++)
    {
        sort(counts[i].begin(),counts[i].end(),std::greater<int>());
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
           // cout<<"i = "<<i<<" j= "<<j<<" "<<counts[i][j]<<endl;
            answer=max(answer,(j+1)*counts[i][j]);
        }
    }
    return answer;
}

