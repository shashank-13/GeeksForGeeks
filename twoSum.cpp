#include<bits/stdc++.h>
using namespace std;
vector<int>twoSum(const vector<int> &A, int B) {
   unordered_map<int,pair<int,int>>myMap;

    for(int i=0;i<A.size();i++)
    {
       if(myMap.find(A[i])==myMap.end())
       {
           pair<int,int>temp;
           temp.first=i+1;
           temp.second=INT_MAX;
           myMap.insert(make_pair(A[i],temp));
       }
       else
       {
           pair<int,int>temp = myMap[A[i]];
           if(i+1 <temp.first)
           {
               temp.first=i+1;
               myMap[A[i]] = temp;
           }
           else if(i+1 < temp.second)
            {
                temp.second=i+1;
                myMap[A[i]] = temp;
            }
       }
    }

    vector<int>answer;
    int index1,index2;
    index1=index2=INT_MAX;

    for(int i=0;i<A.size();i++)
    {
        if(index2<index1)
        {
            int temp=index1;
            index1=index2;
            index2=temp;
        }
        int other = B-A[i];
        auto it = myMap.find(other);
        if(it!=myMap.end())
        {
            pair<int,int>temp = it->second;
            //cout<<other<<" "<<temp.first<<" "<<temp.second<<endl;
            if(temp.first != i+1)
            {
                if(index2==-1)
                {
                    index2=temp.first;
                    index1=i+1;
                }
                else if(temp.first < index2)
                {
                    index2=temp.first;
                    index1=i+1;
                }
                else if(temp.first ==index2 && i+1 <index1)
                {
                    index2=temp.first;
                    index1=i+1;
                }
            }
            else if(temp.first==i+1 && temp.second !=-1)
            {
                 if(index2==-1)
                {
                    index2=temp.second;
                    index1=i+1;
                }
                else if(temp.second < index2)
                {
                    index2=temp.second;
                    index1=i+1;
                }
                else if(temp.second ==index2 && i+1 <index1)
                {
                    index2=temp.second;
                    index1=i+1;
                }
            }

        }
    }

    if(index1!=-1)
    {
        answer.push_back(index1);
        answer.push_back(index2);
    }
    return answer;
}
int main()
{
    vector<int>answer;
    int n,val,B;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>val;
        answer.push_back(val);
    }
    cin>>B;
    twoSum(answer,B);
    return 0;
}
