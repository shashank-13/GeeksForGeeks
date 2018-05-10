
int Solution::longestSubsequenceLength(const vector<int> &A) {

    int n=(int)A.size();
    int left[n],right[n];

    for(int i=0;i<n;i++)
    {
        left[i]=right[i]=1;
    }

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(A[j]<A[i] && left[i]<left[j]+1)
                left[i]=left[j]+1;
        }
    }

    for(int i=n-2;i>=0;i--)
    {
        for(int j=n-1;j>i;j--)
        {
            if(A[j]<A[i] && right[i] < right[j]+1)
                right[i]=right[j]+1;
        }
    }

    int answer = 0;

    for(int i=0;i<n;i++)
    {
        answer=max(answer,left[i]+right[i]-1);
    }

    return answer;
}
