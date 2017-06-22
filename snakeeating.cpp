#include<bits/stdc++.h>
using namespace std;
#define MAX 100005

long long arr[MAX],bit1[MAX],bit2[MAX];

// Segment tree part
long long  index_s;

long long getsum1(long long indx)
{
	long long sum=0;
	while(indx>0)
	{
		sum+=bit1[indx];
		indx-=indx&(-indx);
	}
	return sum;
}
long long getsum2(long long indx)
{
	long long sum=0;
	while(indx>0)
	{
		sum+=bit2[indx];
		indx-=indx&(-indx);
	}
	return sum;
}

void update1(long long  indx,long long n,long long val)
{
	while(indx<=n)
	{
		bit1[indx]+=val;
		indx+=indx&(-indx);
	}
}

void update2(long long  indx,long long  n,long long val)
{
	while(indx<=n)
	{
		bit2[indx]+=val;
		indx+=indx&(-indx);
	}
}


long long getNormalSearch(long long  low,long long  high,long long key)
{
    if(low<=high)
    {
        long long  mid=(low+high)/(long long )2;
        if(arr[mid]>= key && (mid==0 || arr[mid-1]<key))
            return mid;
        else if(arr[mid]>=key)
           return getNormalSearch(low,mid-1,key);
        else if(arr[mid]<key)
            return getNormalSearch(mid+1,high,key);

    }
    else
    {
        return (long long )-1;
    }
}

long long getExtensiveSearch(long long  low,long long  high,long long key)
{
    if(low<=high)
    {
       long long  mid=(low+high)/(long long )2;
        long long temp_sum,b,count1,count2,temp1_sum;

        b=index_s+(long long )1;

         count1=getsum1(mid)*(mid)-getsum2(mid);
		 count2=getsum1(b)*b-getsum2(b);
		temp_sum=count2-count1;
		temp_sum*=(long long )-1;

        if(mid>0){
             count1=getsum1(mid-(long long )1)*(mid-(long long )1)-getsum2(mid-(long long )1);
		 count2=getsum1(b)*b-getsum2(b);
		  temp1_sum=count2-count1;
		  temp1_sum*=(long long )-1;
        }

     //cout<<"Mid Answer "<<low<<" "<<mid<<" "<<high<<" "<<temp_sum<<endl;

            if(mid>=temp_sum && (mid==0 || ((mid-(temp_sum+(long long )1))<temp1_sum-temp_sum)))
                return (index_s-mid)+(long long )1;
            else if(mid>=temp_sum)
                return getExtensiveSearch(low,mid-1,key);
            else if(temp_sum>mid)
                return getExtensiveSearch(mid+1,high,key);

    }
    else
    {
        return (long long )0;
    }
}

int main()
{

    long long  t,n,k,q;
    scanf("%lld",&t);
     ofstream out_file;
        out_file.open("output2.in");
    while(t--)
    {
        scanf("%lld %lld",&n,&q);
        for(int i=0;i<n;i++){

            scanf("%lld",&arr[i]);
            bit1[i]=bit2[i]=0;
        }

        bit1[n]=bit2[n]=0;

        sort(arr,arr+n);

       /* for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";*/



        for(long long i=1;i<=n;i++)
        {

            update1(i,n,arr[i-1]);
			update1(i+1,n,-arr[i-1]);
			update2(i,n,arr[i-1]*(i-(long long )1));
			update2(i+1,n,-arr[i-1]*i);
        }




        for(int i=1;i<=q;i++)
        {
            scanf("%lld",&k);
            int first_index=getNormalSearch(0,n-1,k);


            if(first_index==0)
            {
               out_file<<n<<endl;
            }
            else if(first_index==1)
            {
                out_file<<n-1<<endl;
            }
            else
            {
                int answer=0;
                if(first_index==-1)
                    index_s=n-1;
                else
                {
                    answer+=(n-first_index);
                    index_s=first_index-(long long)1;
                }

                    long long temp_index=index_s+1;

                    long long val= k *(long long )-1;

                    update1(1,n,val);
                    update1(temp_index+1,n,-val);
                    update2(1,n,(long long )0);
                    update2(temp_index+1,n,-val*temp_index);

                    answer+=getExtensiveSearch(0,index_s,k);

                    val*=(long long )-1;



                    update1(1,n,val);
                    update1(temp_index+1,n,-val);
                    update2(1,n,(long long )(0));
                    update2(temp_index+1,n,-val*temp_index);

                    out_file<<answer<<endl;


            }
        }
    }

    return 0;
}
