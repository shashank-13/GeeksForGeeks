
int Solution::braces(string A) {
    stack<int>myStack;
    int diff=-1;
    for(int i=0;i<A.length();i++)
    {
        if(A[i]=='(')
            myStack.push(i);
        else if(A[i]==')')
        {
            int temp=myStack.top();
            myStack.pop();
            int current = i-temp;
            if(diff!=-1 && diff+2==current)
                return 1;
            else if(current == 2)
                return 1;
            diff=current;
        }
    }
    return 0;
}
