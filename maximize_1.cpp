#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int t,n,m;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	        cin>>arr[i];
	    cin>>m;
	    int length,first=-1;
	    length=0;
	    int result,final_ans;
	    final_ans=result= 0;
	    for(int i=0;i<n;i++)
	    {
	        if(arr[i]==1)
	        {
	            result++;
	            final_ans = max(final_ans,result);
	        }

	        else
	        {
	            if(m==0)
	               result=0;
	            else
	            {
	                if(length == m)
	                {
	                  //  cout<<i<<" "<<first<<endl;
	                    result = i-first;
	                    first++;
	                    while(first<n && arr[first]!=0)
	                        first++;
	                    final_ans = max(final_ans,result);
	                }
	                else
	                {
	                    result++;
	                    final_ans = max(final_ans,result);
	                    if(first==-1)
	                        first=i;
	                    length++;
	                }
	            }
	        }
	    }
	    cout<<final_ans<<endl;
	}
	return 0;
}
