vector<string> Solution::fullJustify(vector<string> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<string>temp;
    int current,end;
    current=end=0;
    while(end<A.size())
    {
        int length,org;
         length=org=0;
        while(end<A.size() && org+A[end].length()<=B)
        {
            length+=A[end].length();
            org+=A[end].length();
            org++;
            end++;
        }
       end--;
        int eq,ueq;
        if(end-current>0)
        {
            eq=(B-length)/(end-current);
            ueq=B-((length)+eq*(end-current));
        }
        else
        {
            eq=0;
            ueq=B-length;
        }
        string insert="";
     //   cout<<current<<" "<<end<<" "<<eq<<" "<<ueq<<" "<<length<<endl;
        for(int i=current;i<=end;i++)
        {
            if(end==A.size()-1)
            {
                insert+=A[i];
                if(B-length>0)
                {
                    insert+=' ';
                    length++;
                }
                if(i==end)
                {
                    for(int j=1;j<=(B-length);j++)
                        insert+=' ';
                }
            }
            else if(current==end)
            {
                insert+=A[i];
                for(int j=1;j<=ueq;j++)
                        insert+=' ';

            }
            else
            {
                if(i>current)
                {
                    if(ueq>0)
                    {
                        insert+=' ';
                        ueq--;
                    }
                    for(int j=1;j<=eq;j++)
                        insert+=' ';
                    insert+=A[i];
                }
                else
                {
                    insert+=A[i];
                }
            }

        }
        temp.push_back(insert);
        end++;
        current=end;
    }
    return temp;
}

