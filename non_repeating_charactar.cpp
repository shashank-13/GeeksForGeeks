#include<bits/stdc++.h>
using namespace std;
struct node
{
  int count;
  int index;
};
int main()
 {
	//code
	int t,n;
	string s;
	cin>>t;
	while(t--)
	{
	    node arr[26];
	    for(int i=0;i<=25;i++)
	    {
	        arr[i].index=-1;
	        arr[i].count=0;
	    }
	    cin>>n;
	    getchar();
	    cin>>s;
	    for(int i=0;i<s.length();i++)
	    {

	        if(arr[s[i]-97].index==-1)
	            arr[s[i]-97].index=i;
	        arr[s[i]-97].count++;
	    }
	    int index=-1;
	    char c='a';
	    for(int i=0;i<=25;i++)
	    {
	      if(arr[i].count==1)
          {
              if(index==-1)
              {
                  c='a'+i;
                  index=arr[i].index;
              }
              else if(arr[i].index<index)
              {
                   c='a'+i;
                  index=arr[i].index;
              }
          }
	    }
	    if(index!=-1)
            cout<<c<<endl;
        else
            cout<<"-1\n";
	}

	return 0;
}
