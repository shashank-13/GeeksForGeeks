int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {

    int i,j,k,a,b,c;
    a=(int)A.size();
    b=(int)B.size();
    c=(int)C.size();

    i=j=k=0;
    int answer=INT_MAX;
    while(i<a && j<b && k<c)
    {
        int max1,max2,max3;
        max1=max2=max3=INT_MAX;
        answer=min(answer,max(abs(A[i]-B[j]),max(abs(A[i]-C[k]),abs(B[j]-C[k]))));
        if(i+1<a)
            max1=max(abs(A[i+1]-B[j]),max(abs(A[i+1]-C[k]),abs(B[j]-C[k])));
        if(j+1<b)
            max2=max(abs(A[i]-B[j+1]),max(abs(A[i]-C[k]),abs(B[j+1]-C[k])));
        if(k+1<c)
            max3=max(abs(A[i]-B[j]),max(abs(A[i]-C[k+1]),abs(B[j]-C[k+1])));
        int temp=min(max1,min(max2,max3));
        if(temp==max1)
            i++;
        else if(temp==max2)
            j++;
        else if(temp==max3)
            k++;
    }

    return answer;
}
