#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n;
    char d;
    cin>>t;
    while(t--)
    {
        cin>>n;
        map<int,char> sorted_map;
        unordered_map<char,int> unsorted_map;
        for(int i=1;i<=n;i++)
        {

            cin>>d;

            auto got= unsorted_map.find(d);

            if(got==unsorted_map.end())
            {

                unsorted_map.insert(make_pair(d,i));
                sorted_map.insert(make_pair(i,d));
                auto it=sorted_map.begin();
                cout<<it->second<<" ";
            }
            else
            {
                if(got->second==-1)
                {
                    if(!sorted_map.empty())
                    {
                        auto it=sorted_map.begin();
                     cout<<it->second<<" ";
                    }
                    else
                    {
                        cout<<"-1 ";
                    }
                }
                else
                {
                    unsorted_map.erase(d);
                    sorted_map.erase(got->second);
                    unsorted_map.insert(make_pair(d,-1));
                    if(!sorted_map.empty())
                    {
                        auto it=sorted_map.begin();
                     cout<<it->second<<" ";
                    }
                    else
                    {
                        cout<<"-1 ";
                    }

                }
            }
        }
        cout<<"\n";
    }
    return 0;
}
