
int Solution::maximumGap(const vector<int> &A) {

    int n=(int)A.size();

    if(n==0)
        return -1;
    int minVal[n],maxVal[n];

    for(int i=0;i<n;i++)
    {
        minVal[i]=INT_MAX;
        maxVal[i]=INT_MIN;
    }

    minVal[0]=A[0];
    maxVal[n-1]=A[n-1];

    for(int i=1;i<n;i++)
    {
        minVal[i]=min(minVal[i-1],A[i]);
    }
    for(int i=n-2;i>=0;i--)
    {
        maxVal[i]=max(maxVal[i+1],A[i]);
    }

    int i,j,maxlen=-1;
    i=j=0;
    while(i<n && j<n)
    {
        if(minVal[i]<=maxVal[j])
        {
            maxlen=max(maxlen,j-i);
            j++;
        }
        else
            i++;
    }
    return maxlen;
}
