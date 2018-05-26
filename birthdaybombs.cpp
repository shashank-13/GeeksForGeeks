vector<int> Solution::solve(int A, vector<int> &B) {

    int n=(int)B.size();
    int min_el =INT_MAX;

    for(int i=0;i<n;i++)
        min_el = min(min_el,B[i]);

    int hits = A/min_el;

    min_el=INT_MAX;
    vector<int>index;
    for(int i=0;i<n;i++)
    {
        if(min_el<=B[i])
            continue;
        min_el=min(min_el,B[i]);
        index.push_back(i);
    }


    int x=(int)index.size();



    vector<int>answer;


    while(A>0)
    {
        int ref=A;
        int ind=-1;
        for(int i=0;i<x-1;i++)
        {
            if(hits>0 && ((hits-1)*B[index[x-1]] + B[index[i]])<=A)
            {
               // cout<<A<<" "<<B[index[i]]<<endl;
                ind=i;
                answer.push_back(index[i]);
                hits--;
                A-=B[index[i]];

            }
        }
        if(ind==-1)
        {
            while(hits>0)
            {
                answer.push_back(index[x-1]);
                A-=B[index[x-1]];
                hits--;
            }
        }

        if(ref==A)
            break;
    }

    sort(answer.begin(),answer.end());

    return answer;

}

