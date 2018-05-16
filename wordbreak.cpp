unordered_map<string,bool>myMap;
int check(string A,int ind,int *arr)
{
    if(ind>=A.length())
        return 1;
        
    if(arr[ind]!=-1)
        return arr[ind];
        
    int answer = 0;
    for(int i=1;i<=A.length()-ind;i++)
    {
        if(myMap.find(A.substr(ind,i))!=myMap.end())
            {
             //  cout<<ind<<" "<<i<<endl;
                answer=check(A,ind+i,arr);
                if(answer)
                    break;
            }
    }
    arr[ind]=answer;
    
    return answer;
    
}
int Solution::wordBreak(string A, vector<string> &B) {
    myMap.clear();
    int ind=0;
    while(A[ind]>=97 && A[ind]<=122)
        ind++;
    A=A.substr(0,ind);
    
    int n=A.length();
    int arr[n];
    fill(arr,arr+n,-1);
    for(int i=0;i<(int)B.size();i++)
    {
        myMap.insert(make_pair(B[i],true));
    }
    
    
    return check(A,0,arr);
}
