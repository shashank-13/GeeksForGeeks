/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/
/*returns min element from stack*/
int _stack :: getMin()
{
   //Your code here
  if(s.empty())
  return -1;
  return minEle;
}
/*returns poped element from stack*/
int _stack ::pop()
{
   //Your code here
   if(!s.empty())
   {
    int temp_pop=s.top();
    s.pop();
    if(temp_pop>=minEle)
    return temp_pop;
    else
    {
        int prev_min=2*minEle-temp_pop;
        int temp=minEle;
        minEle=prev_min;
        return temp;
    }

   }
else
{
    return -1;
}
}
/*push element x into the stack*/
void _stack::push(int x)
{
   if(s.empty())
   {
       s.push(x);
       minEle=x;
   }
   else if(x>=minEle)
   {
       s.push(x);
   }
   else
   {
       int insert_val = 2*x-minEle;
       s.push(insert_val);
       minEle = x;
   }

}

