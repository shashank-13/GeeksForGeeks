#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int t,n,W;
	cin>>t;

	while(t--)
	{
	    cin>>n;
	    cin>>W;

	    int arr[n],value[n];
	    for(int i=0;i<n;i++)
	    cin>>value[i];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];

	    int weight[n+1][W+1];

	    for(int i=0;i<=W;i++)
	    weight[0][i]=0;
	    for(int i=0;i<=n;i++)
	    weight[i][0]=0;

	    for(int i=1;i<=n;i++)
	    {
	        for(int j=1;j<=W;j++)
	        {
	            if(arr[i-1]<=j)
	            {
	                weight[i][j]=max(weight[i-1][j],value[i-1]+weight[i-1][j-arr[i-1]]);
	            }
	            else
	            {
	                weight[i][j]=weight[i-1][j];

	            }
	        }
	    }
	    cout<<weight[n][W]<<endl;
	}
	return 0;
}
