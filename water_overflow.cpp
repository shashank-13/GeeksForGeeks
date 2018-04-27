#include<bits/stdc++.h>
#define MAX 1001
using namespace std;
double arr[MAX][MAX];
int main()
{
    int t,i,j;
    double k;
    cin>>t;
    while(t--)
    {
    for(int i=1;i<MAX;i++)
    {
        for(int j=1;j<=i;j++)
            arr[i][j]=0;
    }

    cin>>k>>i>>j;
    bool flag=true;
    int index=1;
    arr[1][1]=k;
    while(flag)
    {
        flag=false;
        for(int i=1;i<=index;i++)
        {
            if(arr[index][i]>1)
            {
                double rem=arr[index][i]-1;
                arr[index][i]=1;
                arr[index+1][i]+=rem/(2.0);
                arr[index+1][i+1]+=rem/(2.0);
                flag=true;
            }
        }
        if(!flag)
            break;
        else
            index++;
    }
    cout.precision(6);
    cout<<fixed<<arr[i][j]<<endl;

    }

    return 0;
}
