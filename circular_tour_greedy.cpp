int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B) {

    int n=(int)A.size();

    int gas,cost;
    gas=cost=0;

    for(int i=0;i<n;i++)
    {
        gas+=A[i];
        cost+=B[i];
    }
    if(cost>gas)
        return -1;

    int prev,start,counts;
    prev=start=0;
    gas=cost=0;
    while(1)
    {
     if(prev==start && counts==n)
        return prev;
     gas+=A[start];
     cost+=B[start];
     if(cost>gas)
     {
         start=(start+1)%n;
         prev=start;
         counts=0;
         gas=cost=0;
     }
     else
     {
          start=(start+1)%n;
         counts++;
     }
    }

}
