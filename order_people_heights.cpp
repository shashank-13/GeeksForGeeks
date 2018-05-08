vector<int> Solution::order(vector<int> &A, vector<int> &B) {

    int n=(int)A.size();
    unordered_map<int,int>myMap;
    for(int i=0;i<n;i++)
    {
        myMap.insert(make_pair(A[i],B[i]));
    }
    int index[n];
    fill(index,index+n,-1);

    sort(A.begin(),A.end());

    for(int i=0;i<n;i++)
    {
        int pos = myMap[A[i]];
        int j=0;
        int counts=0;

        while(j<n && counts<pos)
        {
            if(index[j]!=-1 && index[j] < A[i])
            {
                j++;
            }
            else if(index[j]==-1)
            {
                counts++;
                j++;
            }
            else
            {
                j++;
            }
        }
        while(j<n && index[j]!=-1)
            j++;
        index[j]=A[i];
    }
    vector<int>answer;
    for(int i=0;i<n;i++)
        answer.push_back(index[i]);
    return answer;
}
