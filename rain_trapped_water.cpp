int Solution::trap(const vector<int> &A) {

    int n=A.size();
    int left[n],right[n];
    int current_max=INT_MIN;
    left[0]=right[n-1]=0;

    for(int i=0;i<n-1;i++)
    {
        current_max=max(current_max,A[i]);
        left[i+1]=current_max;
    }
    current_max=INT_MIN;
    for(int i=n-1;i>0;i--)
    {
        current_max = max(current_max,A[i]);
        right[i-1]=current_max;
    }
    int sum=0;
    for(int i=0;i<n;i++)
    {
        int temp=min(left[i],right[i]);
        if(temp>A[i])
            sum+=(temp-A[i]);
    }
    return sum;
}
