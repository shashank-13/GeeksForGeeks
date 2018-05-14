vector<int> Solution::equal(vector<int> &A) {
    vector<int>answer;
    unordered_map<int,pair<int,int>>myMap;
    int n=(int)A.size();
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int sum=A[i]+A[j];
            if(myMap.find(sum)==myMap.end())
            {
                pair<int,int>temp;
                temp.first=i;
                temp.second=j;
                myMap.insert(make_pair(sum,temp));
            }
            else
            {

                    set<int>tempSet;
                    pair<int,int>temp = myMap[sum];
                    tempSet.insert(i);
                    tempSet.insert(j);
                    tempSet.insert(temp.first);
                    tempSet.insert(temp.second);
                    if((int)tempSet.size()==4)
                    {
                        if(answer.empty())
                        {
                            if(temp.first<i || (temp.first==i && temp.second <j))
                            {
                                answer.push_back(temp.first);
                                answer.push_back(temp.second);
                                answer.push_back(i);
                                answer.push_back(j);
                            }
                            else
                            {
                                answer.push_back(i);
                                answer.push_back(j);
                                answer.push_back(temp.first);
                                answer.push_back(temp.second);
                            }
                        }
                        else
                        {
                            int index1,index2,index3,index4;
                           if(temp.first<i || (temp.first==i && temp.second <j))
                            {
                                index1=temp.first;
                                index2=temp.second;
                                index3=i;
                                index4=j;
                            }
                            else
                            {
                                index1=i;
                                index2=j;
                                index3=temp.first;
                                index4=temp.second;
                            }
                            if(index1 < answer[0])
                            {
                                answer[0]=index1;
                                answer[1]=index2;
                                answer[2]=index3;
                                answer[3]=index4;
                            }
                            else if(index1==answer[0] && index2<answer[1])
                            {
                                answer[0]=index1;
                                answer[1]=index2;
                                answer[2]=index3;
                                answer[3]=index4;
                            }
                else if(index1==answer[0] && index2==answer[1] && index3<answer[2])
                {
                                answer[0]=index1;
                                answer[1]=index2;
                                answer[2]=index3;
                                answer[3]=index4;
                }
                else if(index1==answer[0] && index2==answer[1] && index3==answer[2] && index4 < answer[3])
                {
                                answer[0]=index1;
                                answer[1]=index2;
                                answer[2]=index3;
                                answer[3]=index4;
                }

                        }
                    }
                if(i<temp.first || (i==temp.first && j<temp.second))
                {
                 pair<int,int>temp1;
                temp1.first=i;
                temp1.second=j;
                myMap[sum]=temp1;
                }

            }
        }
    }

    return answer;
}

