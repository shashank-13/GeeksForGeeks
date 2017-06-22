#include<bits/stdc++.h>
using namespace std;
#define MAX 10010
int min_answer , max_answer ;
vector<vector<pair<int,int>>>graph(MAX);

void dfs(int x,int k)
{
    for(auto it=graph[x].begin();it!=graph[x].end();it++)
    {
        int temp=k^it->second;
        if(temp>max_answer)
        {

            max_answer=temp;
        }
        if(temp<min_answer)
        {
            min_answer=temp;
        }
        if(x==0)
        return;
        dfs(it->first,k);
    }
}
int main()
{
    unordered_map<int,int> myMap;
    int current_count=0;

   int  N,Q,R,u,v,k,t,key;



    cin >> N >> Q;
    cin >> R >> key;

    graph[0].push_back(make_pair(0,key));
    myMap.insert(make_pair(R,current_count));
    current_count++;



    for (int i = 0; i < N - 1; i++)
    {
        cin >> u >> v >> k;
        int first,second;
        if(myMap.find(u)==myMap.end())
        {
           myMap.insert(make_pair(u,current_count));
           first=current_count;
           current_count++;
        }
        else
        {
            first=myMap.find(u)->second;
        }
        if(myMap.find(v)==myMap.end())
        {
           myMap.insert(make_pair(v,current_count));
           second=current_count;
           current_count++;
        }
        else
        {
            second=myMap.find(v)->second;
        }
        graph[first].push_back(make_pair(second,k));

    }


    int last_answer = 0;

    for (int i = 0; i < Q; i++)
    {
        cin >> t;

        // find real value of t
        t ^= last_answer;


        if (t == 0)
        {
            cin >> v >> u >> k;

            // find real values for u, v, and k
            u ^= last_answer;
            v ^= last_answer;
            k ^= last_answer;

             int first,second;
        if(myMap.find(u)==myMap.end())
        {
           myMap.insert(make_pair(u,current_count));
           first=current_count;
           current_count++;
        }
        else
        {
            first=myMap.find(u)->second;
        }
        if(myMap.find(v)==myMap.end())
        {
           myMap.insert(make_pair(v,current_count));
           second=current_count;
           current_count++;
        }
        else
        {
            second=myMap.find(v)->second;
        }
        graph[first].push_back(make_pair(second,k));



        }
        else
        {
            cin >> v >> k;

            // find real values for v, and k
            v ^= last_answer;
            k ^= last_answer;

            int real_vertex=myMap.find(v)->second;



            if(real_vertex==0)
            {
                min_answer=key^k;
                max_answer=key^k;
                cout<<min_answer<<" "<<max_answer<<endl;
                last_answer = min_answer ^ max_answer;
            }

            else
            {
                // compute the requested values
            min_answer=INT_MAX;
            max_answer=0;
            dfs(real_vertex,k);

            cout<<min_answer<<" "<<max_answer<<endl;

            // update last_answer
            last_answer = min_answer ^ max_answer;
            }


        }
    }

return 0;

}
