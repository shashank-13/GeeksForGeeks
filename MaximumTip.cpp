#include<bits/stdc++.h>
using namespace std;
int n;
#define MAX 110
int arr[MAX],brr[MAX];
int final_answer[MAX][MAX][MAX];
int getMax(int x,int y,int ind)
{
    if(final_answer[x][y][ind]!=-1)
        return final_answer[x][y][ind];
 else if(ind ==n-1)
 {
     if(x>0 && y>0)
     {
      final_answer[x][y][ind]= max(arr[ind],brr[ind]);
      return final_answer[x][y][ind];
     }
     else if(x>0)
     {
      final_answer[x][y][ind]= arr[ind];
      return final_answer[x][y][ind];
     }
     else if(y>0)
     {
        final_answer[x][y][ind] = brr[ind];
        return final_answer[x][y][ind];
     }
     else
     {
        final_answer[x][y][ind]=0;
        return final_answer[x][y][ind];
     }
 }
 else
 {
     if(x>0 && y>0)
     {
         final_answer[x][y][ind]= max(arr[ind]+getMax(x-1,y,ind+1),brr[ind]+getMax(x,y-1,ind+1));
         return final_answer[x][y][ind];
     }
     else if(x>0)
     {
         final_answer[x][y][ind]= arr[ind]+getMax(x-1,y,ind+1);
         return final_answer[x][y][ind];
     }
     else if(y>0)
     {
         final_answer[x][y][ind] = brr[ind]+getMax(x,y-1,ind+1);
         return final_answer[x][y][ind];
     }
     else
     {
        final_answer[x][y][ind]=0;
        return final_answer[x][y][ind];
     }

 }
}
int main()
{
    int t,x,y;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d",&n,&x,&y);
        for(int i=0;i<=x;i++)
        {
            for(int j=0;j<=y;j++)
            {
                for(int k=0;k<=n-1;k++)
                    final_answer[i][j][k] = -1 ;
            }
        }
        for(int i=0;i<n;i++)
            scanf("%d",&arr[i]);
        for(int i=0;i<n;i++)
            scanf("%d",&brr[i]);
        printf("%d\n",getMax(x,y,0));
    }
    return 0;
}
