vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    if(B>A.size())
    {
        int answer = INT_MIN;
        for(int i=0;i<A.size();i++)
        {
            if(A[i]>answer)
                answer=A[i];
        }
        vector<int>result;
        result.push_back(answer);
        return result;
    }
    else
    {
        multiset<int>mySet;
        vector<int>result;
        int prev=INT_MIN;
        for(int i=0;i<B;i++)
        {
            mySet.insert(A[i]);
        }
        for(int i=0;i<=A.size()-B;i++)
        {
            if(prev==INT_MIN)
            {
                auto it = mySet.end();
                it--;
                result.push_back((*it));
            }
            else
            {
                mySet.erase(mySet.equal_range(prev).first);

                mySet.insert(A[i+B-1]);
                auto it = mySet.end();
                it--;
                result.push_back((*it));
            }
            prev=A[i];
        }
        return result;
    }
}
