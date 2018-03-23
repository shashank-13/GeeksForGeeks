#include<bits/stdc++.h>
using namespace std;
int org_cnt[26],temp_cnt[26];
int main()
{
    int t;
    string text,pattern;
    cin>>t;
    while(t--)
    {
        fill(org_cnt,org_cnt+26,0);
        cin>>text;
        getchar();
        cin>>pattern;
        for(int i=0;i<pattern.length();i++)
        {
            org_cnt[pattern[i]-97]++;
        }
        int length=INT_MAX;
        string answer="";
        for(int i=0;i<text.length();i++)
        {
            int counts=0;
            fill(temp_cnt,temp_cnt+26,0);
            for(int k=0;k<=25;k++)
            {
                temp_cnt[k]=org_cnt[k];
            }

            for(int j=i;j<text.length();j++)
            {
                if(temp_cnt[text[j]-97]>0)
                {
                    counts++;
                    temp_cnt[text[j]-97]--;
                    //cout<<i<<" "<<j<<" "<<counts<<" "<<text.substr(i,j-i+1)<<endl;
                    if(counts==pattern.length())
                    {
                        if(j-i+1<length)
                        {
                            length=j-i+1;
                            answer=text.substr(i,length);
                           // cout<<i<<" "<<j<<" "<<text.substr(i,j-i+1)<<endl;
                        }
                        break;
                    }
                }
            }
        }
        if(length==INT_MAX)
            cout<<"-1\n";
        else
            cout<<answer<<endl;
    }
    return 0;
}

