
void Solution::merge(vector<int> &A, vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int i,j;
    i=j=0;
    int n=(int)A.size();
    int m=(int)B.size();
    int count = 0;

    int low=0;

    while(count <n && j<m)
    {
        //cout<<i<<" "<<j<<endl;
        if(A[i]<=B[j])
        {
            i++;
            low++;
            count++;
        }
        else
        {
            A.insert(A.begin()+low,B[j]);
            j++;
            low++;
            i++;
        }
    }

    while(j<m)
    {
       A.insert(A.begin()+low,B[j]);
        j++;
        low++;
    }
}
