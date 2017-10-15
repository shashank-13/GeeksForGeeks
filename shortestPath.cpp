#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        int arr[n][m];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                cin>>arr[i][j];
        }
        int cur_x,cur_y,prev_x,prev_y;
        cur_x=cur_y=prev_x=prev_y=0;
        int row=1,col=0;
        while((cur_x>=0 && cur_x<n) && (cur_y>=0 && cur_y<m))
        {
            if(arr[cur_x][cur_y]==1)
            {
                arr[cur_x][cur_y]=0;
                                if(row==1 && col==0)
                {
                    prev_x=cur_x;
                    prev_y=cur_y;
                    cur_x+=1;
                    row=0;
                    col=-1;
                }
                else if(row==-1 && col==0)
                {
                    prev_x=cur_x;
                    prev_y=cur_y;
                    cur_x-=1;
                    row=0;
                    col=1;
                }
                else if(row==0 && col ==-1)
                {
                    prev_x=cur_x;
                    prev_y=cur_y;
                    cur_y-=1;
                    row=-1;
                    col=0;
                }
                else if(row ==0 && col==1)
                {
                    prev_x=cur_x;
                    prev_y=cur_y;
                    cur_y+=1;
                    row=1;
                    col=0;
                }

            }
            else
            {
                if(row==1 && col==0)
                {
                    prev_x=cur_x;
                    prev_y=cur_y;
                    cur_y+=1;
                }
                else if(row==-1 && col==0)
                {
                    prev_x=cur_x;
                    prev_y=cur_y;
                    cur_y-=1;
                }
                else if(row==0 && col ==-1)
                {
                    prev_x=cur_x;
                    prev_y=cur_y;
                    cur_x+=1;
                }
                else if(row ==0 && col==1)
                {
                    prev_x=cur_x;
                    prev_y=cur_y;
                    cur_x-=1;
                }
            }
        }
        cout<<prev_x<<" "<<prev_y<<endl;
    }
    return 0;
}
