void Solution::nextPermutation(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    bool flag = true;
    int n=(int)A.size();
    for(int i=1;i<n;i++)
    {
        if(A[i]>A[i-1])
        {
            flag=false;
            break;
        }
    }
    if(flag)
    {
     sort(A.begin(),A.end());
    }
    else
    {
        int index1,index2;
        index1=index2=INT_MIN;

        for(int i=n-1;i>=0;i--)
        {
            int low=i-1;
            while(low>=0 && A[low]>=A[i])
            {
                low--;
            }
            if(low>=0)
            {
                if(low>index1)
                {
                    index1=low;
                    index2=i;
                }
            }
        }
        if(index1 != INT_MIN)
        {
            int temp = A[index1];
            A[index1] = A[index2];
            A[index2] = temp;
            index1++;
            sort(A.begin()+index1,A.end());
        }
    }
}

