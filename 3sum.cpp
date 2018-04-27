int Solution::threeSumClosest(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    sort(A.begin(),A.end());
    int answer,compare;
    compare=INT_MAX,answer=0;
    int n=A.size();
    for(int i=0;i<n-2;i++)
    {
        int first,second;
        first=i+1,second=n-1;
        while(first<second)
        {
            if(abs(B-(A[first]+A[second]+A[i])) < compare)
            {
                compare = abs(B-(A[first]+A[second]+A[i]));
                answer=A[i]+A[first]+A[second];
            }
            if((A[first]+A[second])==(B-A[i]))
                break;
            else if((A[first]+A[second])<(B-A[i]))
                first++;
            else
             second--;
        }
    }
    return answer;
}
