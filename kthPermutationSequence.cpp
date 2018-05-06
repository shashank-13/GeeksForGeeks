string Solution::getPermutation(int A, int B) {

    long long fact[A+1];
    fact[0]=fact[1]=1;
    for(long long i=2;i<=A;i++)
        fact[i]=fact[i-1]*i;

    string answer="";
    bool visited[A+1];
    fill(visited,visited+A+1,false);

    for(int i=A-1;i>=0;i--)
    {
      long long fac = fact[i];
      int k=1;
      long long cons = ceil((B)/(fac*1.0));
      for(long long j=1;j<cons;j++)
      {

          while(visited[k])
          k++;
         // cout<<"i = "<<i<<" j= "<<j<<" k ="<<k<<endl;
          k++;
          B-=fac;
      }
      while(visited[k])
          k++;
      visited[k]=true;
      answer+=to_string(k);
    }
    for(int i=1;i<=A;i++)
    {
        if(!visited[i])
        {
            answer+=to_string(i);
            break;
        }
    }

    return answer;
}

