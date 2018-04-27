vector<vector<int> > Solution::threeSum(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<vector<int>> first_Vector;
    
    
    sort(A.begin(),A.end());
    int n=A.size();
    for(int i=0;i<n-2;i++)
    {
        int first,second;
        first=i+1,second=n-1;
        while(first<second)
        {
            if(A[first]+A[second]+A[i]==0)
            {
                vector<int>temp;
                temp.push_back(A[i]);
                temp.push_back(A[first]);
                temp.push_back(A[second]);
                first_Vector.push_back(temp);
                first++;
            }
            else if((A[first]+A[second]+A[i])<0)
                first++;
            else
             second--;
        }
    }
    sort( first_Vector.begin(), first_Vector.end() );
    first_Vector.erase( unique( first_Vector.begin(), first_Vector.end() ), first_Vector.end() );
    return first_Vector;
}
