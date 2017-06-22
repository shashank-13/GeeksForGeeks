#include<bits/stdc++.h>
using namespace std;
struct node
{
    set<char>temp_Set;
};
int main()
{
    int t;
    string s;
    cin>>t;
    while(t--)
    {
        cin>>s;
        int n=s.length();
        node arr[n];
        for(int i=0;i<n;i++)
        {
            set<char> new_set;
            new_set.insert(s[i]);
            arr[i].temp_Set=new_set;
        }
        int distinct,window_length;
        distinct=window_length=1;
        for(int k=2;k<=n;k++)
        {
            for(int i=0;i<=n-k;i++)
            {
              arr[i].temp_Set.insert(s[i+k-1]);
               if(arr[i].temp_Set.size()>distinct)
               {
                   distinct=arr[i].temp_Set.size();
                   window_length=k;
               }


            }
        }

        cout<<window_length<<endl;
    }
    return 0;
}
