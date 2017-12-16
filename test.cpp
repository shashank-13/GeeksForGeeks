#include<bits/stdc++.h>
using namespace std;
#define MAX 505
int dist[MAX][MAX],arr[MAX][MAX];
bool visited[MAX][MAX];
int main()
{
    int t,n,m,max_val,a,b;
    max_val=INT_MIN;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>arr[i][j];
                if(arr[i][j]>max_val)
                {
                    max_val=arr[i][j];
                }
                    dist[i][j]=INT_MAX;
                    visited[i][j]=false;
            }
        }
        vector<pair<int,int>>total_Max;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(arr[i][j]==max_val)
                {
                    total_Max.push_back(make_pair(i,j));
                }
            }
        }
        a=n,b=m;
        queue<pair<int,int>>myqueue;
        myqueue.push(make_pair(a,b));
        dist[a][b]=0;
        visited[a][b]=true;
        while(!myqueue.empty())
        {
          pair<int,int>temp=myqueue.front();
          a=temp.first,b=temp.second;
          myqueue.pop();
          if(a==n && b==m)
          {
              for(auto it=total_Max.begin();it!=total_Max.end();it++)
              {
                  dist[it->first][it->second]=1;
                  visited[it->first][it->second]=true;
                  myqueue.push(make_pair(it->first,it->second));
              }
          }
          else
          {
           if(b-1>=0 && dist[a][b]+1<dist[a][b-1] && !visited[a][b-1])
          {
                dist[a][b-1]=dist[a][b]+1;
                visited[a][b-1]=true;
            myqueue.push(make_pair(a,b-1));
          }
          if(b+1<m && dist[a][b]+1<dist[a][b+1] && !visited[a][b+1])
          {
                dist[a][b+1]=dist[a][b]+1;
                visited[a][b+1]=true;
            myqueue.push(make_pair(a,b+1));
          }
          if(a-1>=0 && dist[a][b]+1<dist[a-1][b] && !visited[a-1][b])
          {
                dist[a-1][b]=dist[a][b]+1;
                visited[a-1][b]=true;
            myqueue.push(make_pair(a-1,b));
          }
         if(a+1<n && dist[a][b]+1<dist[a+1][b] && !visited[a+1][b])
          {
                dist[a+1][b]=dist[a][b]+1;
                visited[a+1][b]=true;
            myqueue.push(make_pair(a+1,b));
          }
          if(b+1<m && a-1>=0 && dist[a][b]+1<dist[a-1][b+1] && !visited[a-1][b+1])
          {
                dist[a-1][b+1]=dist[a][b]+1;
                visited[a-1][b+1]=true;
            myqueue.push(make_pair(a-1,b+1));
          }
          if(b+1<m && a+1<n && dist[a][b]+1<dist[a+1][b+1] && !visited[a+1][b+1])
          {
                dist[a+1][b+1]=dist[a][b]+1;
                visited[a+1][b+1]=true;
            myqueue.push(make_pair(a+1,b+1));
          }
          if(b-1>=0 && a-1>=0 && dist[a][b]+1<dist[a-1][b-1] && !visited[a-1][b-1])
          {
                dist[a-1][b-1]=dist[a][b]+1;
                visited[a-1][b-1]=true;
            myqueue.push(make_pair(a-1,b-1));
          }
          if(b-1>=0 && a+1<n && dist[a][b]+1<dist[a+1][b-1] && !visited[a+1][b-1])
          {
                dist[a+1][b-1]=dist[a][b]+1;
                visited[a+1][b-1]=true;
            myqueue.push(make_pair(a+1,b-1));
          }
          }

        }
       max_val=INT_MIN;
       for(int i=0;i<n;i++)
       {
          for(int j=0;j<m;j++)
          {
              if(dist[i][j]>max_val)
                max_val=dist[i][j];
          }
       }
       cout<<max_val-1<<endl;
    }
    return 0;
}
