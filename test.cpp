#include<bits/stdc++.h>
using namespace std;
int main()
{
   int a=0,b=1,c=2;
   *((a+1==1)?&b:&a) =a ?b:c;
    cout<<a<<" "<<b<<" "<<c;
    return 0;
}
