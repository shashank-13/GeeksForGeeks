vector<string>final_Answer;
unordered_map<string,bool>myMap;
bool comparator(const string a,const string b)
{
    return a<b;
}
void check(string A,int ind,string s)
{
    if(ind>=A.length())
    {
     if(!s.empty())
        final_Answer.push_back(s);
    }
    
    for(int i=1;i<=A.length()-ind;i++)
    {
        if(myMap.find(A.substr(ind,i))!=myMap.end())
            {
                string temp="";
                if(!s.empty())
                    temp = s+" "+A.substr(ind,i);
                else
                    temp=A.substr(ind,i);
                check(A,ind+i,temp);
            }
    }
}
vector<string> Solution::wordBreak(string A, vector<string> &B) {
    
    myMap.clear();
    while(!final_Answer.empty())
        final_Answer.pop_back();
        
    int ind=0;
    while(A[ind]>=97 && A[ind]<=122)
        ind++;
    A=A.substr(0,ind);
    
    int n=A.length();
    for(int i=0;i<(int)B.size();i++)
    {
        myMap.insert(make_pair(B[i],true));
    }
     check(A,0,"");
     sort(final_Answer.begin(),final_Answer.end(),&comparator);
     
     return final_Answer;
}
