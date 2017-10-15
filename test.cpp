#include<bits/stdc++.h>
using namespace std;
int main()
{
    unsigned int t,n,f;
    cin>>t;
    while(t--)
    {
        cin>>n;
        f=n/2;
        unsigned int final_val = (pow(2,32)-1)/(n+1);
        unsigned int other_val = (pow(2,32)-1)-(final_val*(n));
        other_val=min(other_val,100000u);

       for(int i=0;i<n;i++)
           {
               if(i==f)
                cout<<other_val<<" ";
               else
                cout<<final_val<<" ";
           }
        cout<<"\n";
    }
    return 0;
}
