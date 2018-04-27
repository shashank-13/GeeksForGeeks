vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
    int n=A.size();

    vector<pair<int,int>>pair_sum;
    vector<pair<int,int>>pair_index,p_ind;
    vector<int>p_sum;
    int count=0;

    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int sum=A[i]+A[j];
            pair_sum.push_back(make_pair(sum,count));
            p_sum.push_back(sum);
            pair_index.push_back(make_pair(A[i],A[j]));
            p_ind.push_back(make_pair(i,j));
            count++;
        }
    }
    sort(pair_sum.begin(),pair_sum.end());
    sort(p_sum.begin(),p_sum.end());
    set<vector<int>>mySet;

    for(int i=0;i<pair_sum.size();i++)
    {
        int other = B-pair_sum[i].first;
        int first=lower_bound(p_sum.begin(),p_sum.end(),other) - p_sum.begin();
        if(first != pair_sum.size())
        {
        int second = upper_bound(p_sum.begin(),p_sum.end(),other) - p_sum.begin();
        for(int k=first;k<second;k++)
        {
            if(k!=i)
            {

                int ind1=pair_sum[i].second;
                int ind2=pair_sum[k].second;
                pair<int,int>p_1=p_ind[ind1];
                pair<int,int>p_2=p_ind[ind2];
                /*cout<<pair_sum[i].first<<" "<<p_1.first<<" "<<p_1.second<<endl;
                cout<<pair_sum[k].first<<" "<<p_2.first<<" "<<p_2.second<<endl;*/
                set<int>t_s;
                t_s.insert(p_1.first);
                t_s.insert(p_1.second);
                t_s.insert(p_2.first);
                t_s.insert(p_2.second);
                if(t_s.size()==4)
                {
                pair<int,int>temp1 = pair_index[ind1];
                pair<int,int>temp2 = pair_index[ind2];
                vector<int>answer;
                answer.push_back(temp1.first);
                answer.push_back(temp1.second);
                answer.push_back(temp2.first);
                answer.push_back(temp2.second);
                sort(answer.begin(),answer.end());
                mySet.insert(answer);
                }
            }
        }
        }
    }
    vector<vector<int>>final_answer;
    for(auto it = mySet.begin();it!=mySet.end();it++)
    {
        final_answer.push_back(*it);
    }
    return final_answer;

}

