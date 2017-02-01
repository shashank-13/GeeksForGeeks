#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int counts=0;
       long long x=log2(n)+1;
        for(long i=0;i<x;i++)
        {
            long long temp=pow((long long)2,i);
            if(temp&n){

                counts++;
            }
        }
        cout<<counts<<endl;
    }
    return 0;
}
