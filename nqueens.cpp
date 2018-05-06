bool isValid(vector<vector<int>>A,int a,int b,int n)
{
    for(int j=0;j<n;j++)
    {
        if(A[a][j]!=0)
            return false;
    }
    for(int i=0;i<n;i++)
    {
        if(A[i][b]!=0)
            return false;
    }
    int i,j;
    i=a;
    j=b;
    while(i<n && j<n)
    {
        if(A[i][j]!=0)
            return false;
        i++;
        j++;
    }
    i=a;
    j=b;
    while(i<n && j>=0)
    {
        if(A[i][j]!=0)
            return false;
        i++;
        j--;
    }

    i=a;
    j=b;
    while(i>=0 && j>=0)
    {
        if(A[i][j]!=0)
            return false;
        i--;
        j--;
    }

    i=a;
    j=b;
    while(i>=0 && j<n)
    {
        if(A[i][j]!=0)
            return false;
        i--;
        j++;
    }
    return true;

}
bool recurse(vector<vector<int>>A,int ind,int n,vector<vector<string>>&final_answer)
{
   if(ind==n)
   {
       vector<string>answer;
       for(int i=0;i<n;i++)
       {
           string s="";
           for(int j=0;j<n;j++)
           {
               if(A[i][j]==0)
               {
                   s+=".";
                  // cout<<".";
               }
               else
               {
                   s+="Q";
                   //cout<<"Q";
               }

           }
           answer.push_back(s);
       }
       final_answer.push_back(answer);


       return true;
   }

   for(int i=0;i<n;i++)
   {
       if(isValid(A,ind,i,n))
       {
          // cout<<"Row = "<<ind<<" Col = "<<i<<endl;
           A[ind][i]=1;
           recurse(A,ind+1,n,final_answer);
       }
       A[ind][i]=0;
   }
   return false;

}
vector<vector<string> > Solution::solveNQueens(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more detail
    vector<vector<int>>answer(A);
    for(int i=0;i<A;i++)
    {
        for(int j=0;j<A;j++)
        {
            answer[i].push_back(0);
        }
    }

    vector<vector<string>>final_answer;
    recurse(answer,0,A,final_answer);

    return final_answer;
}

