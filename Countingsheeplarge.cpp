#include<bits/stdc++.h>
using namespace std;
bool arr[10];
bool checkCount()
{
    int counts=0;
    for(int i=0;i<10;i++)
    {
        if(arr[i]==1)
            counts++;
    }
    return (counts==10);
}
int main()
{
    long long n,t;
    /*ofstream out_file;
    out_file.open("out.in");*/
    scanf("%lld",&t);
    int test_case=1;
    while(t--)
    {
        scanf("%lld",&n);
        for(int i=0;i<10;i++)
            arr[i]=0;

        char buffer[30];
    if(n==0)
    {
        printf("Case #%d: INSOMNIA\n",test_case);
        //out_file<<buffer;
        test_case++;
        continue;
    }
        long long counter=1;
        long long initial=n;

        while(1)
        {
            n=initial*counter;
            long long temp=n;
            while(temp!=0)
            {
                long long x=temp%10;
                arr[x]=1;
                temp/=10;
            }
           // printf("%lld\n",n);
            if(checkCount())
            {
                printf("Case #%d: %lld\n",test_case,n);
                //out_file<<buffer;
                break;
            }
            counter++;
        }

     test_case++;
    }
    //out_file.close();
    return 0;
}

