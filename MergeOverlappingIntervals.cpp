/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 bool comparator(const Interval &a1,const Interval &a2)
 {
     if(a1.start==a2.start)
        return a1.end >= a2.end;
    else
    return a1.start<=a2.start;
 }
vector<Interval> Solution::merge(vector<Interval> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    sort(A.begin(),A.end(),&comparator);
    int total_Count=0;
    for(int i=1;i<A.size();i++)
    {
        Interval i1=A[total_Count];
        Interval i2=A[i];
        if(i2.start<=i1.end)
        {
            Interval i3;
            i3.start=i1.start;
            i3.end=max(i1.end,i2.end);
            A[total_Count]=i3;
        }
        else
        {
            total_Count++;
            A[total_Count]=A[i];
        }

    }
    total_Count++;
    A.erase(A.begin()+total_Count,A.end());
    return A;
}

