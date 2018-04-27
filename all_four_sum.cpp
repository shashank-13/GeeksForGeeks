#include<bits/stdc++.h>
using namespace std;
int arr[1001];
struct node
{
  int i,j;
  int sum;
};
bool comparator(pair<int,string>&a ,pair<int,string>&b)
{
    if(a.first==b.first)
    {
        string first[4],second[4];
        string s1=a.second;
        string s2=b.second;
        s1=s1.substr(0,s1.length()-2);
        s2=s2.substr(0,s2.length()-2);
       stringstream ssin(s1);
       stringstream ssin1(s2);
       int i=0;
    while (ssin.good() && ssin1.good() && i < 4){
        ssin >> first[i];
        ssin1 >> second[i];
        ++i;
    }
    if(first[0]==second[0])
    {
        if(first[1]==second[1])
        {
            if(first[2]==second[2])
            {
                return first[3]<second[3];
            }
            else
            {
                return first[2] < second[2];
            }
        }
        else
        {
            return first[1]<second[1];
        }
    }
    else
    {
        return first[0]<second[0];
    }

   }
    return a.first < b.first;
}
int main()
 {
	//code
	int t,n,k;
	cin>>t;
	while(t--)
	{
	    cin>>n>>k;
	    for(int i=0;i<n;i++)
	        cin>>arr[i];
	    node st_arr[n*n];
	    int index=0;
	    for(int i=0;i<n;i++)
	    {
	        for(int j=i+1;j<n;j++)
	        {
	            st_arr[index].i=i;
	            st_arr[index].j=j;
	            st_arr[index].sum=arr[i]+arr[j];
	            index++;
	        }
	    }
	    bool flag=false;
	    unordered_map<string,bool>map_check;
	    vector<pair<int,string>>answer;
	    for(int i=0;i<index;i++)
	    {
	        for(int j=0;j<index;j++)
	        {
	            if(st_arr[j].sum==(k-st_arr[i].sum))
                {
                set<int>temp;
	            temp.insert(st_arr[i].i);
	            temp.insert(st_arr[i].j);
	            temp.insert(st_arr[j].i);
	            temp.insert(st_arr[j].j);
	            if(temp.size()==4)
                {
                    vector<int>temp1;
                    temp1.push_back(arr[st_arr[i].i]);
                    temp1.push_back(arr[st_arr[i].j]);
                    temp1.push_back(arr[st_arr[j].i]);
                    temp1.push_back(arr[st_arr[j].j]);
                    sort(temp1.begin(),temp1.end());
                    string s="";
                    string res="";
                    int sum=0;
                    for(auto it=temp1.begin();it!=temp1.end();it++)
                    {
                      s+=to_string(*it)+",";
                      res+=to_string(*it)+" ";
                      sum+=(*it);
                    }
                    res+="$";
                    if(map_check.find(s)==map_check.end())
                    {
                        /*cout<<st_arr[i].i<<" "<<st_arr[i].j<<" "<<st_arr[j].i<<" "<<st_arr[j].j<<endl;
                        cout<<arr[st_arr[i].i]<<" "<<arr[st_arr[i].j]<<" "<<arr[st_arr[j].i]<<" "<<arr[st_arr[j].j]<<endl;
                        cout<<s<<endl;*/
                        flag=true;
                        map_check.insert(make_pair(s,true));
                        answer.push_back(make_pair(sum,res));
                    }
                }

                }

	        }
	    }
	    if(!flag)
            cout<<"-1";
        else
        {
            sort(answer.begin(),answer.end(),comparator);
            for(auto it=answer.begin();it!=answer.end();it++)
                cout<<(it->second);
        }
	    cout<<endl;
	}
	return 0;
}
