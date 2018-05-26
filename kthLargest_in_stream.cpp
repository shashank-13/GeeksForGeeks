#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int t,n,k,val;
	cin>>t;
	while(t--)
	{
	    cin>>k>>n;
	    priority_queue<int>max_heap;
	    priority_queue<int,vector<int>,greater<int>>min_heap;
	    int current_Median=-1;
	    for(int i=1;i<=n;i++)
	    {
	        cin>>val;
	        bool flag = false;
	        if(!max_heap.empty() && val<=max_heap.top())
	        {
	            max_heap.push(val);
	        }
	        else
	        {
	            flag = true;
	            min_heap.push(val);
	        }
	        if(i>=k)
	        {
	            if(flag && !min_heap.empty())
	            {
	                int top = min_heap.top();
	                min_heap.pop();
	                max_heap.push(top);
	            }
	            current_Median = max_heap.top();
	        }
	        
	        cout<<current_Median<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}