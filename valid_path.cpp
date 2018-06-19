unordered_map<string,bool>myMap,visited;
bool isReachable(int a,int b,int x,int y)
{
    string s = to_string(a)+","+to_string(b);
    visited.insert(make_pair(s,true));
    if(a==x && b==y)
        return true;
    if(a+1<=x && myMap.find(to_string(a+1)+","+to_string(b))==myMap.end())
    {
        if(visited.find(to_string(a+1)+","+to_string(b))==visited.end() && isReachable(a+1,b,x,y))
            return true;
    }
     if(a-1>=0 && myMap.find(to_string(a-1)+","+to_string(b))==myMap.end())
    {
        if(visited.find(to_string(a-1)+","+to_string(b))==visited.end() && isReachable(a-1,b,x,y))
            return true;
    }
    if(b+1<=y && myMap.find(to_string(a)+","+to_string(b+1))==myMap.end())
    {
        if(visited.find(to_string(a)+","+to_string(b+1))==visited.end() && isReachable(a,b+1,x,y))
            return true;
    }
    if(b-1>=0 && myMap.find(to_string(a)+","+to_string(b-1))==myMap.end())
    {
        if(visited.find(to_string(a)+","+to_string(b-1))==visited.end() && isReachable(a,b-1,x,y))
            return true;
    }
    if(a+1<=x && b+1<=y && myMap.find(to_string(a+1)+","+to_string(b+1))==myMap.end())
    {
        if(visited.find(to_string(a+1)+","+to_string(b+1))==visited.end() && isReachable(a+1,b+1,x,y))
            return true;
    }
    if(a+1<=x && b-1>=0 && myMap.find(to_string(a+1)+","+to_string(b-1))==myMap.end())
    {
        if(visited.find(to_string(a+1)+","+to_string(b-1))==visited.end() && isReachable(a+1,b-1,x,y))
            return true;
    }
    if(a-1>=0 && b+1<=y && myMap.find(to_string(a-1)+","+to_string(b+1))==myMap.end())
    {
        if(visited.find(to_string(a-1)+","+to_string(b+1))==visited.end() && isReachable(a-1,b+1,x,y))
            return true;
    }
    if(a-1>=0 && b-1>=0 && myMap.find(to_string(a-1)+","+to_string(b-1))==myMap.end())
    {
        if(visited.find(to_string(a-1)+","+to_string(b-1))==visited.end() && isReachable(a-1,b-1,x,y))
            return true;
    }
    return false;
}

string Solution::solve(int A, int B, int C, int D,vector<int> &E, vector<int> &F) {

    myMap.clear();
    visited.clear();
    
    for(int i=0;i<=A;i++)
    {
        for(int j=0;j<=B;j++)
        {
            bool flag = false;
            for(int k=0;k<C;k++)
            {
                if(sqrt(((i-E[k])*(i-E[k]))+((j-F[k])*(j-F[k])))<=D)
                {
                    flag=true;
                    break;
                }
            }
            if(flag)
            {
                string s = to_string(i)+","+to_string(j);
                myMap.insert(make_pair(s,true));
            }
        }
    }
    
    if(isReachable(0,0,A,B))
        return "YES";
    else
        return "NO";
    
}

