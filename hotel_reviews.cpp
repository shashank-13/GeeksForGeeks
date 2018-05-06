
bool comparator(const pair<int,int>&a ,const pair<int,int>&b)
{
    if(a.second==b.second)
        return a.first < b.first;
    return a.second > b.second;
}
vector<int> Solution::solve(string A, vector<string> &B) {

    unordered_map<string,bool>myMap;
    int n=A.length();
    int i=0;
    while(i<n)
    {
        string temp="";
        while(i<n && A[i]!='_')
        {
            temp+=A[i];
            i++;
        }
        if(temp!="")
            myMap.insert(make_pair(temp,true));
        i++;
    }
    vector<pair<int,int>>answer;
    for(int j=0;j<(int)B.size();j++)
    {
         n=B[j].length();
         i=0;
         int counts=0;
        while(i<n)
        {
            string temp="";
            while(i<n && B[j][i]!='_')
            {
                temp+=B[j][i];
                i++;
            }
            if(myMap.find(temp)!=myMap.end())
                counts++;
            i++;
        }
        answer.push_back(make_pair(j,counts));

    }
    sort(answer.begin(),answer.end(),&comparator);
    vector<int>final_answer;
    for(auto it=answer.begin();it!=answer.end();it++)
    {
        final_answer.push_back(it->first);
    }
    return final_answer;
}
