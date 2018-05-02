int solution[76],target[76];
bool isValid()
{
    for(int i=0;i<=75;i++)
    {
        if(target[i]<solution[i])
            return false;
    }
 return true;
}
string Solution::minWindow(string A, string B) {

    fill(solution,solution+76,0);
    fill(target,target+76,0);

    for(int i=0;i<B.length();i++)
    {
        solution[B[i]-48]++;
    }

    int low;
    low=0;

    int length,index1,index2;
    length=index1=index2=INT_MAX;

    for(int i=0;i<A.length();i++)
    {
         target[A[i]-48]++;

        if(isValid())
        {
           int prev;
           while(isValid())
           {
               target[A[low]-48]--;
               low++;
           }
           prev=low-1;
         //  cout<<"Prev = "<<prev<<" Low = "<<low<<" High = "<<i<<endl;
           if((i-prev+1)<length)
           {
               length=i-prev+1;
               index1=prev;
               index2=i;
           }
           else if((i-prev+1)==length && prev < index1)
           {
                length=i-prev+1;
               index1=prev;
               index2=i;
           }
          else if((i-prev+1)==length && prev==index1 && i<index2)
           {
                length=i-prev+1;
               index1=prev;
               index2=i;
           }
        }

    }

    string final_answer="";

    if(length == INT_MAX)
        return final_answer;
    final_answer=A.substr(index1,length);

    return final_answer;
}

