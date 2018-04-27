int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
bool Solution::isPower(int A) {
    if(A==1)
        return true;
    else if(A<=3)
    return false;
    vector<int>powers;
    int count=0;
    while(A%2==0)
    {
        A=A/2;
        count++;
    }
    if(count>0)
    powers.push_back(count);
    count=0;
    for(int i=3;i<=sqrt(A);i+=2)
    {
        count=0;
        while(A%i==0)
        {
            A/=i;
            count++;
        }
        if(count>0)
           powers.push_back(count);
    }
    if(A>2 || powers.size()==0)
        return false;
    else
    {
        int current_gcd=-1;
        for(int i=0;i<powers.size()-1;i++)
        {
            if(current_gcd==-1){
                current_gcd=gcd(powers[i],powers[i+1]);
                if(current_gcd==1)
                return false;
            }

            else
            {
                int temp_gcd=gcd(powers[i],powers[i+1]);
                if(current_gcd!=temp_gcd)
                    return false;
            }
        }
        return true;
    }
}

