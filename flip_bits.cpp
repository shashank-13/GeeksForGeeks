vector<int> Solution::flip(string A) {

    vector<int>answer;
    int count=0;
    for(int i=0;i<A.length();i++)
    {
        if(A[i]=='1')
            count++;
    }
    if(count == A.length())
        return answer;

    int cost[A.length()];

    for(int i=0;i<A.length();i++)
    {
        if(A[i]=='0')
            cost[i]=1;
        else
            cost[i]=-1;
    }
    int max_sum=-1;
    int maxlen=-1;
    int current=0;
    int index1,index2;
    index1=index2=INT_MAX;
    int length1=0;
    int length2=0;

    int low=0;

    for(int i=0;i<A.length();i++)
    {
        current+=cost[i];
        if(cost[i]==1)
            length1++;
        else
            length2++;
        if(current<0)
        {
            current =0;
            low=i+1;
            length1=0;
            length2=0;
        }
        else if(current>max_sum)
        {
            max_sum=current;
            index1=low;
            index2=i;
            maxlen=length1-length2;
        }
        else if(current==max_sum && length1-length2>maxlen)
        {
            index1=low;
            index2=i;
            maxlen=length1-length2;
        }
    }

    answer.push_back(index1+1);
    answer.push_back(index2+1);

    return answer;


}


