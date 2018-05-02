vector<int> Solution::findSubstring(string A, const vector<string> &B) {

    int n = A.length();
    int l=B[0].length();
    int k = (int)B.size();


    vector<int>answer;
    unordered_multimap<string,bool>myMap,tempMap;

    for(int i=0;i<k;i++)
    {
        myMap.insert(make_pair(B[i],true));
    }


    for(int i=0;i<=n-l;)
    {
        //cout<<i<<" "<<A.substr(i,l)<<endl;
        if(myMap.find(A.substr(i,l))!=myMap.end())
        {
            if(tempMap.find(A.substr(i,l))==tempMap.end())
            {
                tempMap.insert(make_pair(A.substr(i,l),true));
                if(k==(int)tempMap.size())
                {
                    answer.push_back(i-(l*(k-1)));
                     int f=(int)tempMap.size();
                     f--;
                    f*=l;
                    i-=f;
                    i++;
                    tempMap.clear();
                }
                else
                {
                    i+=l;
                }
            }
            else if(tempMap.count(A.substr(i,l))<myMap.count(A.substr(i,l)))
            {
                tempMap.insert(make_pair(A.substr(i,l),true));
                if(k==(int)tempMap.size())
                {
                    answer.push_back(i-(l*(k-1)));
                     int f=(int)tempMap.size();
                     f--;
                    f*=l;
                    i-=f;
                    i++;
                    tempMap.clear();
                }
                else
                {
                    i+=l;
                }
            }
            else
            {
                int f=(int)tempMap.size();
                f*=l;
                i-=f;
                i++;
                tempMap.clear();
            }
        }
        else
        {
             int f=(int)tempMap.size();
            f*=l;
            i-=f;
            i++;
            tempMap.clear();
        }

    }

    return answer;
}
