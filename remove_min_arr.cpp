vector<int> Solution::subUnsort(vector<int> &A) {
    bool flag=true;
    int n=A.size();

    for(int i=1;i<n;i++)
    {
        if(A[i]<A[i-1])
        {
            flag=false;
            break;
        }
    }
    if(flag)
    {
        vector<int>answer;
        answer.push_back(-1);
        return answer;
    }

    int low,high;
    low=0;
    high=n-1;
    while(low<n && A[low]<=A[low+1])
    {
        low++;
    }

    while(high>=0 && A[high]>=A[high-1])
    {
        high--;
    }
    int min_e,max_e;
    min_e=INT_MAX;
    max_e=INT_MIN;

    for(int i=low;i<=high;i++)
    {
        min_e=min(min_e,A[i]);
        max_e=max(max_e,A[i]);
    }
    while(low>=0 && A[low]>min_e)
        low--;
    while(high<n && A[high] < max_e)
        high++;

    low++;
    high--;
    vector<int>answer;
    answer.push_back(low);
    answer.push_back(high);
    return answer;
}
