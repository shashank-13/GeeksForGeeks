vector<int> Solution::stepnum(int A, int B) {
    
    queue<int>myQueue;
    unordered_map<int,int>myMap;
    vector<int>answer;
    
    if(A>B)
        return answer;
    for(int i=0;i<=9;i++)
    {
        if(i<=B)
        {
              myQueue.push(i);
              myMap.insert(make_pair(i,true));
    
        }
    }
  
    while(!myQueue.empty())
    {
        int f = myQueue.front();
        myQueue.pop();
        if(f>=A && f<=B)
            answer.push_back(f);
        string s = to_string(f);
        char c = s[s.length()-1];
        if(c+1 <= 57)
        {
            c=c+1;
            string k = s+c;
            f=stoi(k);
            if(myMap.find(f)==myMap.end() && f<=B )
            {
                myQueue.push(f);
                myMap.insert(make_pair(f,true));
            }
        }
        c=s[s.length()-1];
         if(c-1>=48)
        {
            c=c-1;
            s+=c;
            f=stoi(s);
            if(myMap.find(f)==myMap.end() && f<=B )
            {
                myQueue.push(f);
                myMap.insert(make_pair(f,true));
            }
        }
    }
    sort(answer.begin(),answer.end());
    return answer;
}
