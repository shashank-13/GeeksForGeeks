#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long t,n;
    cin>>t;
    while(t--)
{
        cin>>n;
        long long arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    long long max_answer,cur_answer;
    max_answer=cur_answer=1;
    for(int i=0;i<n;i++)
    {
       cur_answer*=arr[i];
       if(cur_answer<0 && (i+1==n || arr[i+1]>=0))
            cur_answer=1;
       else if(cur_answer==0)
        cur_answer=1;
       else if(cur_answer>max_answer)
        max_answer=cur_answer;
    }
    cout<<max_answer<<endl;

}
    return 0;
}
