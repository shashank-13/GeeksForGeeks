
bool comparator(vector<int>A,vector<int>B)
{
    int n=(int)A.size();
    int m=(int)B.size();
    int i,j;
    i=j=0;

    bool flag = false;
    while(i<n && j<m)
    {
        if(A[i]<B[j])
        {
            flag=true;
            break;
        }
        if(B[j]<A[i])
            return false;
        i++;
        j++;
    }

    if(j<m || flag)
        return true;

    return false;

}
vector<vector<int> > Solution::subsets(vector<int> &A) {

    vector<vector<int>>final_answer;
    sort(A.begin(),A.end());

    int n=(int)A.size();
    int pow_n=pow(2,n);

    for(int i=0;i<pow_n;i++)
    {
        vector<int>answer;
        for(int j=0;j<n;j++)
        {
            if(i & (1<<j))
                answer.push_back(A[j]);
        }

        final_answer.push_back(answer);

    }
    sort(final_answer.begin(),final_answer.end(),&comparator);

    return final_answer;
}
