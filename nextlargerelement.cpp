#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        stack<int>front_stack,back_stack;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int i=n-1;i>=0;i--)
        {
            int answer;
            while(!front_stack.empty() && front_stack.top()<arr[i])
            {
                front_stack.pop();
            }
            if(front_stack.empty())
                answer=-1;
            else
                answer=front_stack.top();
            front_stack.push(arr[i]);
            back_stack.push(answer);
        }
        while(!back_stack.empty())
        {
            cout<<back_stack.top()<<" ";
            back_stack.pop();
        }
        cout<<"\n";
    }
    return 0;
}
