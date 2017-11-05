#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,val;
    cin>>n;
    priority_queue<int>max_heap;
    priority_queue<int,vector<int>,greater<int>>min_heap;
    int current_Median=-1;
    for(int i=0;i<n;i++)
    {
        cin>>val;
        if(current_Median==-1)
        {
            min_heap.push(val);
        }
        else
        {
            if(val>=current_Median)
                min_heap.push(val);
            else
                max_heap.push(val);
        }
        if(abs(min_heap.size()-max_heap.size())>1)
        {
            if(min_heap.size()>max_heap.size())
            {
                while(min_heap.size()-max_heap.size()>1)
                {
                    int temp=min_heap.top();
                    min_heap.pop();
                    max_heap.push(temp);
                }
            }
            else
            {
                while(max_heap.size()-min_heap.size()>1)
                {
                    int temp=max_heap.top();
                    max_heap.pop();
                    min_heap.push(temp);
                }
            }
        }
        if(min_heap.size()==max_heap.size())
        {
            current_Median=(min_heap.top()+max_heap.top())/2;
        }
        else if(min_heap.size()>max_heap.size())
            current_Median=min_heap.top();
        else
            current_Median=max_heap.top();
        cout<<current_Median<<endl;
    }
    return 0;
}
