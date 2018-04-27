#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int arr[n];
        int index,counts;
        index=counts=0;
        for(int i=0;i<n;i++)
        {
         cin>>arr[i];
         if(arr[i]<0)
         {
             index=i;
             counts++;
         }
        }
        if(counts==1)
            arr[index]=0;
        int final_prod,current_answer;
        final_prod=0;
        current_answer=1;
        for(int i=0;i<n;i++)
        {
            if(current_answer==0)
                current_answer=arr[i];
            else
                current_answer*=arr[i];
            final_prod=max(final_prod,current_answer);
        }
        cout<<final_prod<<endl;
    }
    return 0;
}
