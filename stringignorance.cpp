#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int t;
	string s;
	bool visited[28];
	cin>>t;
	 getchar();
	while(t--)
	{
	    for(int i=0;i<=27;i++)
	    visited[i]=true;

	    std::getline(cin,s);
	    for(int i=0;i<s.length();i++)
	    {
	        int ind;
	        if(s[i]==' ')
	        ind=0;
	        else
            {
                 ind=toupper(s[i])-'0';
                 ind-=16;
            }
	      // cout<<ind<<endl;
	        if(visited[ind])
	        {
	            cout<<s[i];
	            visited[ind]=false;
	        }
	        else
	        {
	           visited[ind]=true;
	        }
	    }
	    cout<<endl;
	}
	return 0;
}
