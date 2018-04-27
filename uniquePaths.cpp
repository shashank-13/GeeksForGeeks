long long expo(long long n,long long k)
{
    if(k>n-k)
        k=n-k;
    long long final_answer=1;
    for(long long i=0;i<k;i++)
    {
        final_answer*=(n-i);
        final_answer/=(i+1);
    }
    return final_answer;
}
int Solution::uniquePaths(int A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    return expo(A-1+B-1,B-1);
}
