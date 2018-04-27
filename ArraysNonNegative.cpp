vector<int> Solution::maxset(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for moredetails
    int n=A.size();
    struct node
{
    long long sum;
    int start,end;
};
        struct node edge;
        edge.sum=0;
        edge.start=edge.end=0;
         long long current_sum,max_sum,start;
          current_sum=max_sum=start=0;
          bool flag = false;
         for(int i=0;i<n;i++)
         {
             current_sum+=A[i];
             if(A[i]<0)
             {
                 current_sum=0;
                 start=i+1;
             }
             else if(current_sum>edge.sum)
             {
                 flag=true;
                 edge.sum=current_sum;
                 edge.start=start;
                 edge.end=i;
             }
             else if(current_sum==edge.sum)
             {
                 if(((i-start) > (edge.end-edge.start)) || (A[i]==0 && start<=edge.start))
                 {
                     flag=true;
                 edge.sum=current_sum;
                 edge.start=start;
                 edge.end=i;
                 }
             }
         }
         vector<int>return_Vector;
         if(flag)
         {
          for(int i=edge.start;i<=edge.end;i++)
         {
             return_Vector.push_back(A[i]);
         }

         }

    return return_Vector;
}
