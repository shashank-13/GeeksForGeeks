#include<bits/stdc++.h>
using namespace std;
#define MAX 1005
bool visited[MAX];
char input[MAX];
int n;

void dfs(int level,int val)
{
  visited[val]=true;
  if(level==0)
  {
    if(val+1 < n && !visited[val+1] && input[val+1]=='#')
    dfs(level,val+1);
    else if(val-1>=0 && !visited[val-1] && input[val-1]=='#')
    dfs(level,val-1);
    else if(!visited[n+val] && input[n+val]=='#')
    {

            dfs(level+1,n+val);
    }

  }
  else
  {
      if(val+1 < 2*n && !visited[val+1] && input[val+1]=='#')
    dfs(level,val+1);
    else if(val-1>=n && !visited[val-1] && input[val-1]=='#')
    dfs(level,val-1);
    else if(!visited[val-n] && input[val-n]=='#')
    {

            dfs(level-1,val-n);
    }

  }


}
int main()
{
    int t;
    string s1,s2;
    cin>>t;
   while(t--)
   {
       vector<int>pos_move;
       cin>>n;
       cin>>s1;
       cin>>s2;
       int total_count=0;
       for(int i=0;i<n;i++)
       {
            input[i]=s1[i];
            if(s1[i]=='#')
                total_count++;
            visited[i]=false;
       }

       for(int i=0;i<n;i++)
       {
           input[n+i]=s2[i];
           if(s2[i]=='#')
            total_count++;
           visited[n+i]=false;
       }
       input[2*n]='\0';
       int left_pos=-1,right_pos=-1;

       for(int i=0;i<n;i++)
       {
           if(s1[i]=='#'&& left_pos==-1){
            left_pos=i;
            right_pos=i;
           }

           else if(s1[i]=='#')
            right_pos=i;
       }

       if(left_pos!=-1)
        pos_move.push_back(left_pos);
       if(right_pos!=-1 && left_pos!=right_pos)
        pos_move.push_back(right_pos);
       left_pos=right_pos=-1;

       for(int i=0;i<n;i++)
       {
           if(s2[i]=='#'&& left_pos==-1){
            left_pos=n+i;
            right_pos=n+i;
           }

           else if(s2[i]=='#')
            right_pos=n+i;
       }

        if(left_pos!=-1)
        pos_move.push_back(left_pos);
       if(right_pos!=-1 && left_pos!=right_pos)
        pos_move.push_back(right_pos);

        bool flag=false;

        for(int i=0;i<2*n;i++)
        {
            if(input[i]=='#')
            {
                 if(i<n)
                dfs(0,i);
            else
                dfs(1,i);
            int temp_count=0;
            for(int i=0;i<2*n;i++)
            {
                if(visited[i])
                {
                    temp_count++;
                }
                visited[i]=0;
            }
            if(temp_count==total_count)
            {
                flag=true;
                break;
            }
            }

        }

        if(flag)
            cout<<"yes\n";
        else
            cout<<"no\n";


   }
    return 0;
}
