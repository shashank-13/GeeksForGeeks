vector<int> Solution::lszero(vector<int> &A) {

    int n=A.size();
    int prefix[n+1];

    for(int i=0;i<=n;i++)
        prefix[i]=0;

    int index1,index2,length;
    index1=index2=length=INT_MIN;
    unordered_map<int,int>myMap;

    for(int i=0;i<n;i++)
    {
        prefix[i+1]=prefix[i]+A[i];
        if(myMap.find(prefix[i+1])==myMap.end())
        {
            myMap.insert(make_pair(prefix[i+1],i));
        }
        else
        {
            myMap[prefix[i+1]]=i;
        }
    }
    for(int i=0;i<n;i++)
    {
        int sum=prefix[i];
        if(myMap.find(sum)!=myMap.end())
        {
            int index=myMap[sum];
            if((index>=i && (index-i+1)>length))
            {
                length=(index-i+1);
                index1=i;
                index2=index;
            }
        }
    }
   vector<int>answer;

   if(index1!=INT_MIN)
   {
       for(int i=index1;i<=index2;i++)
       {
           answer.push_back(A[i]);
       }
   }
   return answer;
}

