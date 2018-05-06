void chPermute(vector<int>A,string s,int ind,vector<vector<int>>&final_Answer)
{
    if(ind==(int)A.size())
    {
        vector<int>answer;
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
            answer.push_back(stoi(temp));
        }
        final_Answer.push_back(answer);
        return ;
    }
    for(int i=0;i<(int)A.size();i++)
    {
        string key = to_string(A[i]);
        if(s.find(key)==std::string::npos)
        {
            chPermute(A,s+key+",",ind+1,final_Answer);
        }
    }
}
vector<vector<int> > Solution::permute(vector<int> &A) {
    vector<vector<int>>final_Answer;
    chPermute(A,"",0,final_Answer);
    return final_Answer;
}
