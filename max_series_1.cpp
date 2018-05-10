
vector<int> Solution::maxone(vector<int> &A, int B) {

    int low,high,start,end,maxlen;
    low=high=0;
    int counts = 0;
    int n=(int)A.size();

    while(high<n)
    {
        if(A[high]==0 && counts<B)
        {
            counts++;
        }
        else if(A[high]==0 && counts==B)
        {
            while(A[low]!=0)
                low++;
            low++;
        }
        if(high-low+1 >maxlen)
        {
            start=low;
            end = high;
            maxlen = high-low+1;
        }
        high++;
    }
    vector<int>answer;
    for(int i =start;i<=end;i++)
    {
       answer.push_back(i);
    }
    return answer;

}
