int Solution::repeatedNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

int elem1,elem2,count1,count2,n;
elem1=elem2=-1;
count1=count2=0;
for(auto it =A.begin();it!=A.end();it++)
{
    if(elem1==(*it))
    count1++;
    else if(elem2==(*it))
    count2++;
    else if(elem1==-1)
    {
        elem1=(*it);
        count1=1;
    }
    else if(elem2==-1)
    {
        elem2=(*it);
        count2=1;
    }
    else
    {
        count1--;
        count2--;
        if(count1==0)
        elem1=-1;
        if(count2==0)
        elem2=-1;
    }
}
count1=count2=0;
for(auto it =A.begin();it!=A.end();it++)
{
    if(elem1!=-1 && (*it)==elem1)
    count1++;
    else if(elem2!=-1 && (*it)==elem2)
    count2++;
}
if(count1 >(A.size()/3))
    return elem1;
else if(count2 > (A.size()/3))
    return elem2;
return -1;
}
