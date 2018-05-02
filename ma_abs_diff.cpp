int Solution::maxArr(vector<int> &A) {
    int n = A.size();
    int first[n],second[n];
    for(int i=0 ;i<n;i++)
    {
        first[i]=A[i]-(i+1);
        second[i]=A[i]+(i+1);
    }
    int max_val_1,max_val_2;
    max_val_1=max_val_2= INT_MIN;
    int min_val_1,min_val_2;
    min_val_1=min_val_2= INT_MAX;
    for(int i=0;i<n;i++)
    {
        max_val_1=max(max_val_1,first[i]);
        min_val_1=min(min_val_1,first[i]);
        max_val_2=max(max_val_2,second[i]);
        min_val_2=min(min_val_2,second[i]);
    }
    //cout<<max_val_1<<" "<<min_val_1<<" "<<max_val_2<<" "<<min_val_2<<endl;
    return max((max_val_2-min_val_2),(max_val_1-min_val_1));
}
