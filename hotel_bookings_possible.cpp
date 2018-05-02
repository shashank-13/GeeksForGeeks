
bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {

    int n=(int)arrive.size();
    int index1,index2;

    index1 = index2 = 0;

    int count = 0;

    sort(arrive.begin(),arrive.end());
    sort(depart.begin(),depart.end());

    while (index1 < n && index2 < n)
    {
        if(depart[index2]<=arrive[index1])
        {
            if(count>0)
            count--;
            index2++;
        }
        else
        {
         if(count<K)
            count++;
           else
            return false;
         index1++;
        }
    }
    return true;
}
