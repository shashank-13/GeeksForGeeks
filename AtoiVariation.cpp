int Solution::atoi(const string &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int current,size,end;
    bool flag=false;
    current=0;
    size=A.length();
    while(current<size && A[current]==' ')
    current++;
    if(current>=size)
        return 0;
    if(A[current]=='-')
    {
        flag=true;
        current++;
    }
    else if(A[current]=='+')
    current++;
    else if(A[current]-'0'<0||A[current]-'0'>9)
        return 0;
    if(A[current]-'0'<0||A[current]-'0'>9)
        return 0;
    vector<int>temp_v;
    while(current<size && (A[current]-'0'>=0 && A[current]-'0'<=9))
    {
        temp_v.push_back(A[current]-'0');
        current++;
    }
    
    int final_answer=0;
    end=0;
    
    for(int i=temp_v.size()-1;i>=0;i--)
    {
        int temp=pow(10,end)*temp_v[i];
        if(temp<0)
        {
            if(flag)
                return INT_MIN;
            else
            return INT_MAX;
        }
        if(final_answer+temp<final_answer)
        {
            if(flag)
            return INT_MIN;
            else
            return INT_MAX;
        }
        final_answer+=temp;
        end++;
    }
    if(flag)
        final_answer*=-1;
    return final_answer;
}
