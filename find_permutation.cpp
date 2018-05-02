vector<int> Solution::findPerm(const string A, int B) {

    vector<int>answer;
    int low,high;
    low = 1;
    high = B;
    for(int i=0;i<A.length();i++)
    {
        if(A[i]=='D')
        {
            answer.push_back(high);
            high--;
        }
        else
        {
            answer.push_back(low);
            low++;
        }
    }

    answer.push_back(low);

    return answer;

}

