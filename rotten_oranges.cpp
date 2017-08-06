#define MAX 110

#include<bits/stdc++.h>
using namespace std;
int input[MAX][MAX];
bool visited[MAX][MAX];
int count_Array[MAX][MAX];

int n,m;

int dfs(int i,int j )
{
    visited[i][j]=true;
   if(input[i][j]==2)
    return 0;

   int counter = INT_MAX;

   int temp_ans;



    if(i-1>=0 && !visited[i-1][j] &&(input[i-1][j]==1 || input[i-1][j]==2))
    {
         temp_ans=dfs(i-1,j);
         if(temp_ans!=INT_MAX)
            temp_ans++;
         counter=min(counter,temp_ans);
    }

    if(i+1<n  && !visited[i+1][j] &&(input[i+1][j]==1 || input[i+1][j]==2))
        {
         temp_ans= dfs(i+1,j);
         if(temp_ans!=INT_MAX)
            temp_ans++;
         counter=min(counter,temp_ans);
    }

    if(j-1>=0 && !visited[i][j-1] &&(input[i][j-1]==1 || input[i][j-1]==2))
    {
         temp_ans=dfs(i,j-1);
         if(temp_ans!=INT_MAX)
            temp_ans++;
         counter=min(counter,temp_ans);
    }

   if(j+1 < m  && !visited[i][j+1] &&(input[i][j+1]==1 || input[i][j+1]==2))
    {
         temp_ans= dfs(i,j+1);;
         if(temp_ans!=INT_MAX)
            temp_ans++;
         counter=min(counter,temp_ans);
    }
    if(count_Array[i][j]==0)
    count_Array[i][j]=counter;
    else
        count_Array[i][j]=min(counter,count_Array[i][j]);
    return counter;

}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>input[i][j];
                visited[i][j]=false;
                count_Array[i][j]=0;

            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if( input[i][j]==1)
                {
                    for(int a=0;a<n;a++)
                    {
                        for(int b=0;b<m;b++)
                        {

                            visited[a][b]=false;
                        }
                    }
                    dfs(i,j);
                }
            }
        }
        int final_answer=INT_MIN;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(input[i][j]==1)
                {
                    //cout<<i<<" "<<j<<" "<<count_Array[i][j]<<endl;
                     final_answer=max(final_answer,count_Array[i][j]);
                }

            }
        }
        if(final_answer==INT_MAX)
            cout<<"-1\n";
        else
            cout<<final_answer<<endl;
    }
    return 0;
}
