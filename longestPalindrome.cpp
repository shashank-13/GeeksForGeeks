#include<bits/stdc++.h>
using namespace std;
int getMaxPal(int *arr,int low,int high)
{
    int matrix[high+1][high+1];
    for(int i=0;i<=high;i++)
    {
        for(int j=0;j<=high;j++)
        {
            if(i>j)
                matrix[i][j]=0;
            else if(i==j)
                matrix[i][j]=1;
            else
                matrix[i][j]=0;
        }
    }
    for(int i=1;i<=high;i++)
    {
        for(int j=0;j<=high-i;j++)
        {
            if(arr[j]==arr[j+i])
            {
               if(j+1<=high && matrix[j+1][j+i-1]==i-1)
                 matrix[j][j+i]=2+matrix[j+1][j+i-1];
            }

            else
            matrix[j][j+i]=max(matrix[j][j+i-1],(j+1<=high?matrix[j+1][j+i]:0));
        }
    }
    int answer=INT_MIN;

  for(int i=0;i<=high;i++)
    {
        for(int j=0;j<=high;j++)
        {
            answer=max(answer,matrix[i][j]);
        }
    }
//return the answer
return answer;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<getMaxPal(arr,0,n-1);
    return 0;
}
