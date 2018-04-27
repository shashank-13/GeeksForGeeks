string Solution::countAndSay(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    string answer="1";
    for(int i=1;i<A;i++)
    {
        string temp="";
        int current=0;
        while(current<answer.length())
        {
            char inc=answer[current];
            int count=0;
            while(current<answer.length() && answer[current]==inc)
            {
                current++;
                count++;
            }
            temp+=to_string(count);
            temp+=inc;
        }
        answer=temp;
    }
    return answer;
}
