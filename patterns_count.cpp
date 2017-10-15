#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    string s;
    cin>>t;
    while(t--)
    {
        cin>>s;
        vector<int>position_Vector;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='1')
                position_Vector.push_back(i);
        }
        int prev=-1;
        int final_answer=0;
        for(auto it=position_Vector.begin();it!=position_Vector.end();it++)
        {
            if(prev!=-1)
            {
                int current=(*it);
                bool flag=true;
                for(int j=prev+1;j<current;j++)
                {
                    if(s[j]!='0')
                    {
                        flag=false;
                        break;
                    }
                }
                if(flag && current-prev>1)
                    final_answer++;

            }
            prev=(*it);
        }
        cout<<final_answer<<endl;
    }
    return 0;
}
