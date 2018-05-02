vector<int> Solution::solve(vector<int> &A, vector<int> &B) {

    unordered_map<string,bool>myMap;
    priority_queue<pair<int,string>> myQueue;

    vector<int>answer;
    int n=(int)A.size();
    int count=0;

    sort(A.begin(),A.end());
    sort(B.begin(),B.end());

    string s = to_string(n-1)+","+to_string(n-1);
    myQueue.push(make_pair(A[n-1]+B[n-1],s));
    myMap.insert(make_pair(s,true));

    while(count<n)
    {
        pair<int,string> temp = myQueue.top();
        myQueue.pop();
        answer.push_back(temp.first);

        int del=temp.second.find(',');
        int left = stoi(temp.second.substr(0,del));
        int right = stoi(temp.second.substr(del+1));

        string s1=to_string(left)+","+to_string(right-1);
        string s2=to_string(left-1)+","+to_string(right);

        if(myMap.find(s1)==myMap.end())
        {
            myMap.insert(make_pair(s1,true));
             myQueue.push(make_pair(A[left]+B[right-1],s1));
        }
        if(myMap.find(s2)==myMap.end())
        {
            myMap.insert(make_pair(s2,true));
             myQueue.push(make_pair(A[left-1]+B[right],s2));
        }

        count++;
    }
    return answer;
}
