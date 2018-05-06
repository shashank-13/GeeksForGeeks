bool comparator(vector<string>A,vector<string>B)
{
    int n=(int)A.size();
    int m=(int)B.size();
    int i,j;
    i=j=0;

    bool flag = false;
    while(i<n && j<m)
    {
        if(A[i].length()<B[j].length())
        {
            flag=true;
            break;
        }
        if(B[j].length()<A[i].length())
            return false;
        i++;
        j++;
    }

    if(j<m || flag)
        return true;

    return false;

}
bool isPal(string s)
{
    int n=s.length();
    int k=n/2;
    for(int i=0;i<=k;i++)
    {
        if(s[i]!=s[n-i-1])
            return false;
    }
    return true;
}
void permuteString(string A,string s,int ind,vector<vector<string>>&final_answer)
{
    if(ind>=A.length())
    {
        vector<string>answer;
        int i=0;
        while(i<s.length())
        {
            string temp="";
            while(s[i]!=',')
            {
                temp+=s[i];
                i++;
            }
            i++;
            answer.push_back(temp);
        }
        final_answer.push_back(answer);
        return ;
    }
     for(int j=1;j+ind<=A.length();j++)
        {
            if(isPal(A.substr(ind,j)))
            {

                string temp = A.substr(ind,j);
                //cout<<s<<" "<<i<<" "<<j<<endl;
                permuteString(A,s+temp+",",ind+j,final_answer);
            }
        }
}
vector<vector<string> > Solution::partition(string A) {
    // Do not write main() function.
    // Do not read in+put, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more detail
    vector<vector<string>>final_answer;
    permuteString(A,"",0,final_answer);
    sort(final_answer.begin(),final_answer.end(),&comparator);
    return final_answer;

}

