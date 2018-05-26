int Solution::jump(vector<int> &A) {
    int n = (int )A.size();
    int counts = 0;
    bool flag =false;
    for(int i=0;i<n-1;)
    {
        int current_max=INT_MIN;
        int index=-1;
        for(int j=1;j<=A[i];j++)
        {
            if(i+j>=n)
            {
                counts++;
                flag=true;
                break;
            }
            if(A[i+j]+i+j >current_max)
            {
                current_max=A[i+j]+i+j;
                index=i+j;
            }
        }
        if(index==-1 || flag)
            break;
        cout<<i<<" "<<index<<endl;
        counts++;
        i=index;
    }
    if(flag || n==1)
        return counts;
    return -1;
}

