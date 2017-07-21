#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        int s[n];
        s[0]=1;
        stack<int>span_stack;
        span_stack.push(0);
        for(int i=1;i<n;i++)
        {
            while(!span_stack.empty() && arr[span_stack.top()]<=arr[i])
            {
                span_stack.pop();
            }
            if(span_stack.empty())
            {
                s[i]=i+1;
            }
            else
            {
                s[i]=i-span_stack.top();
            }
            span_stack.push(i);
        }

        int left=0,prev;

        bool flag=false;

        while(left<n)
        {
          while(left<n && s[left]==1)
          {
              prev=left;
           left++;
          }
          if(left>=n)
            break;
          while(left<n-1 && s[left]<s[left+1])
          {
              left++;
          }
          if(arr[prev]!=arr[left])
          {
               flag=true;
               cout<<"("<<prev<<" "<<left<<") ";
          }
          left++;
        }
        if(!flag)
            cout<<"No Profit";
        cout<<endl;
    }

    return 0;
}
