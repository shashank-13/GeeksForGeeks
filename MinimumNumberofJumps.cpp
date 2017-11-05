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
        bool flag =false;
        queue<int>my_queue;
        my_queue.push(0);
        int steps=0;
        while(!my_queue.empty())
        {
            int top = my_queue.front();
            my_queue.pop();
         //   cout<<top<<" "<<arr[top]<<endl;
            steps+=1;
            if(arr[top]+top+1>=n)
            {
                flag=true;
                break;
            }
            for(int i=top+1;i<=min(n-1,arr[top]+top);i++)
            {
                my_queue.push(i);
            }
        }
        steps-=1;
        if(!flag)
            cout<<"-1\n";
        else
            cout<<steps<<endl;

    }
    return 0;
}
