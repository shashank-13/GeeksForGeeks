int numberofPainters(vector<int> &A,int maxlen)
{
    int total=0;
    int num=1;
    for(int i=0;i<(int)A.size();i++)
    {
        total+=A[i];
        if(total>maxlen)
        {
            total=A[i];
            num++;
        }
    }
    return num;
}
int Solution::books(vector<int> &A, int B) {
    if(B>(int)A.size())
        return -1;
    int low=INT_MIN;
    int high=0;
    for(int i=0;i<(int)A.size();i++)
    {
        low=max(low,A[i]);
        high+=A[i];
    }
    while(low<high)
    {
        int mid=(low+high)/2;
        int k=numberofPainters(A,mid);
        if(k<=B)
         high=mid;
        else
            low=mid+1;
    }
    return low;
}

