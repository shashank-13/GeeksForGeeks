int Solution::singleNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int number[32];
    for(int i=0;i<=31;i++)
        number[i]=0;
    for(int i=0;i<A.size();i++)
    {
        int temp,j;
        temp=A[i],j=0;
        while(temp>0)
        {
            if(temp%2)
                number[j]=(number[j]+1)%3;
            temp/=2;
            j++;
        }
    }
    int answer=0;
    for(int i=0;i<=31;i++)
    {
        answer+=(pow(2,i)*number[i]);
    }
    return answer;
}
