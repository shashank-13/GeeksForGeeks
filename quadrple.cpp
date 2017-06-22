#include<bits/stdc++.h>
using namespace std;


struct node
{
    int a,b,c,d;
};

bool comparator(node &a,node &b)
{
    return a.a<b.a;
}

int binarysearch(node arr[],int low,int high,int key,int ind)
{
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid].a==key)
       {
           if(arr[mid].c==arr[ind].c || arr[mid].c==arr[ind].d || arr[mid].d==arr[ind].c || arr[mid].d == arr[ind].d)
            return -1;
           return mid;
       }
        else if(arr[mid].a<key)
        low=mid+1;
        else if(arr[mid].a>key)
        high=mid-1;
    }
    return -1;
}

int main()
 {
	//code
	int t,n,global_k;
	scanf("%d",&t);
	while(t--)
	{
	    scanf("%d %d",&n,&global_k);
	    int arr[n];
	    int temp=n*n;
	    node store[temp],new_arr[temp];
	    for(int i=0;i<n;i++)
	    scanf("%d",&arr[i]);
	    int count=0;
	    for(int i=0;i<n;i++)
	    {
	        for(int j=i+1;j<n;j++)
	        {
	            if(i!=j)
	            {
	                new_arr[count].a=arr[i]+arr[j];
	                new_arr[count].b=count;
	                new_arr[count].c=i;
	                new_arr[count].d=j;
	                store[count].a=arr[i];
	                store[count].b=arr[j];
	                count++;
	            }
	        }
	    }

	    sort(new_arr,new_arr+count,&comparator);



	    node store_node[count];

	    int till_now=0;

	   for(int i=0;i<count;i++)
	   {
	       if(global_k>=new_arr[i].a)
	       {
	           //cout<<new_arr[i]<<" "<<global_k-new_arr[i]<<endl;
	           int x=binarysearch(new_arr,0,count-1,global_k-new_arr[i].a,i);
	           if(x!=-1)
	           {

	                int temp_arr[4];
	                int y;
	                x=new_arr[x].b;
	                y=new_arr[i].b;

	               temp_arr[0]=store[y].a;
	               temp_arr[1]=store[y].b;
	               temp_arr[2]=store[x].a;
	               temp_arr[3]=store[x].b;

                   sort(temp_arr,temp_arr+4);

                   if(temp_arr[0]==17 && temp_arr[1]==34 && temp_arr[2]==60 && temp_arr[3]==68)
                    printf("detected\n");



	               bool flag=false;

	               for(int k=0;k<till_now;k++)
                   {

                       if(store_node[k].a==temp_arr[0] && store_node[k].b==temp_arr[1] && store_node[k].c==temp_arr[2] && store_node[k].d == temp_arr[3])
                       {
                           if(temp_arr[0]==17 && temp_arr[1]==34 && temp_arr[2]==60 && temp_arr[3]==68)
                    printf("detected but eliminated \n");

                           flag=true;
                           break;
                       }

                   }
                   if(!flag)
                   {


                        store_node[till_now].a=temp_arr[0];
                        store_node[till_now].b=temp_arr[1];
                        store_node[till_now].c=temp_arr[2];
                        store_node[till_now].d=temp_arr[3];

                        till_now++;
                   }


	           }
	       }
	   }
	  /* if(till_now==0)
        printf("-1");

	  for(int i=0;i<till_now;i++)
       {
           printf("%d %d %d %d \n",store_node[i].a,store_node[i].b,store_node[i].c,store_node[i].d);
       }
       printf("\n");*/

	}
	return 0;
}
