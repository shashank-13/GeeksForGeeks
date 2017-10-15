#include<bits/stdc++.h>
using namespace std;
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int arr[s.length()];
        for(int i=0;i<s.length();i++)
            arr[i]=s[i]-'0';
        int flag =true;
        for(int i=0;i<s.length()-1;i++)
        {
            if(arr[i+1]>arr[i])
            {
                flag=false;
                break;
            }
        }
        if(flag)
        {
            cout<<"not possible\n";
        }
        else
        {
            for(int i=s.length()-1;i>0;i--)
            {
              for(int j=i-1;j>0;j--)
              {
                  if(arr[i]>arr[j])
                  {
                      swap(&arr[i],&arr[j]);
                      flag=true;
                  }
              }
            }
            if(flag)
            {
                for(int i=0;i<s.length();i++)
                    cout<<arr[i];
                cout<<endl;
            }
            else
            {
                int val=arr[0];
                int current_min=INT_MAX;
                for(int i=1;i<s.length();i++)
                {
                    if(arr[i]>val && arr[i]<current_min)
                        current_min=arr[i];
                }
                cout<<current_min;
                int temp_count=0;
                sort(arr,arr+s.length());
                for(int i=0;i<s.length();i++)
                {
                    if(arr[i]==current_min && temp_count<1)
                    {
                        temp_count++;
                        continue;
                    }
                    cout<<arr[i];
                }
                cout<<endl;
            }
        }
    }
    return 0;
}
