int Solution::largestRectangleArea(vector<int> &A) {

    int n = A.size();
    int left[n],right[n];
    stack<int>first,second;

    for(int i=0;i<n;i++)
    {
        while(!first.empty() && first.top()>=A[i])
        {
            first.pop();
            second.pop();
        }
        if(first.empty())
        {
            left[i]=-1;
        }
        else
        {
            left[i]=second.top();
        }
        first.push(A[i]);
        second.push(i);
    }
    while(!first.empty())
    {
        first.pop();
        second.pop();
    }

    for(int i=n-1;i>=0;i--)
    {
        while(!first.empty() && first.top()>=A[i])
        {
            first.pop();
            second.pop();
        }
        if(first.empty())
        {
            right[i]=n;
        }
        else
        {
            right[i]=second.top();
        }
        first.push(A[i]);
        second.push(i);
    }
    int final_answer=INT_MIN;
    for(int i=0;i<n;i++)
    {
        int temp =(right[i]-left[i]-1)*A[i];
        if(temp>final_answer)
            final_answer = temp;
    }

    return final_answer;
}
