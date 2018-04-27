int Solution::repeatedNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    if(A.size()==1)
        return -1;
    else if (A.size()==2)
    {
        if(A[0]==A[1])
            return A[0];
        return -1;
    }
    else
    {
        int n=round(sqrt(A.size()));
    int other_range,def;
    if((n*n)>A.size())
    {
     other_range=A.size()-(n*(n-1));
     other_range--;
     def=n-1;
    }
    else
    {
        other_range=A.size()-(n*n);
        other_range--;
        def=n;
    }
    int arr[n];
    bool flag=false;
    int number;

    for( int i=0 ; i<n; i++)
        arr[i]=0;
    for(int i=0;i<A.size();i++)
    {
        number =A[i]%n;
        arr[number]++;
        if(number >=1 && number<=other_range)
        {
         if(arr[number]>def+1)
        {
            flag=true;
            break;
        }
        }
        else
        {
            if(arr[number]>def)
        {
            flag=true;
            break;
        }
        }
    }
    if(flag)
    {
        unordered_map<int,bool>my_Map;
        for(int i=0;i<A.size();i++)
        {
            if(A[i]%n == number)
            {
                if(my_Map.find(A[i])!=my_Map.end())
                    return A[i];
                my_Map.insert(make_pair(A[i],true));
            }
        }
    }
    else
    return -1;
    }


}
