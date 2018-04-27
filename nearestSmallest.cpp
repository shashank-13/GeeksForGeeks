vector<int> Solution::prevSmaller(vector<int> &A) {
    vector<int>result;
    stack<int>temp;
    for(int i=0;i<A.size();i++)
    {
        while(!temp.empty() && temp.top()>=A[i])
            temp.pop();
        if(!temp.empty())
            result.push_back(temp.top());
        else
            result.push_back(-1);
        temp.push(A[i]);
    }
    return result;
}
