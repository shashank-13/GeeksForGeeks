#include<iostream>
using namespace std;
int main()
{
    int n,x,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        x=2*n-1;
        int half=(x-1)/2;
        if(n==1)
            cout<<"1"<<endl;
        else
        {
            for(int i=1;i<=x;i++)
            {
                cout<<n;
            }
            cout<<" ";
            int low=2,high=x-1;
            int value=n;
            for(int i=1;i<=x-1;i++)
            {
                if(i<=half)
                {
                    value--;
                    for(int j=low-1;j>0 && j<low;j++)
                        cout<<n;
                    for(int j)

                }
                else
                {

                }
            }
        }
    }
    return 0;
}
