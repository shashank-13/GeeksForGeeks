vector<vector<int> > Solution::anagrams(const vector<string> &A) {

    unordered_map<string,vector<int>>myMap;
    int count[26];
    for(int i=0;i<A.size();i++)
    {
        fill(count,count+26,0);
        string s = A[i];
        for(int j=0;j<s.length();j++)
        {
            count[s[j]-97]++;
        }
        string temp="";
        for(int k=0;k<26;k++)
        {
            temp+=to_string(count[k]);
            temp+=",";
        }
        if(myMap.find(temp)==myMap.end())
        {
            vector<int>answer;
            answer.push_back(i+1);
            myMap.insert(make_pair(temp,answer));
        }
        else
        {
            vector<int>answer=myMap[temp];
            answer.push_back(i+1);
            myMap[temp] = answer;
        }
    }
    vector<vector<int>>final_Answer;

    for(auto it =myMap.begin();it!=myMap.end();it++)
    {
        vector<int>answer = it->second;
        final_Answer.push_back(answer);
    }

    return final_Answer;
}

