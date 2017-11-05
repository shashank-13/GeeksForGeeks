#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int t,n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    int lis[n];
	    for(int i=0;i<n;i++)
	    cin>>lis[i];
	    int arr[n];
	    for(int i=0;i<n;i++)
    	    arr[i]=1;
    	for(int i=1;i<n;i++)
    	{
    	    int count =0;
    	    for(int j=0;j<i;j++)
    	    {
    	        if(lis[j] < lis[i])
    	         count = max(count,arr[j]);
    	    }
    	    arr[i]=max(arr[i],count+1);
    	}
    	int final_answer=0;
    	for(int i=0;i<n;i++)
    	{
    	    final_answer=max(final_answer,arr[i]);
    	}
    	cout<<final_answer<<endl;

	}
	return 0;
}
