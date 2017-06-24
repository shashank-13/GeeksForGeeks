#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,k;
    cin>>t;
    while(t--)
    {
        cin>>k;
        cin>>n;
        int arr[n];
        int max_val,max_ind,min_val,min_ind;
        max_val=INT_MIN,min_val=INT_MAX,max_ind=min_ind=-1;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            if(arr[i]>max_val)
            {
                max_val=arr[i];
                max_ind=i;
            }
            if(arr[i]<min_val)
            {
                min_val=arr[i];
                min_ind=i;
            }
        }
        int current_min=min(min_val+k,max_val-k);
        int current_max=max(min_val+k,max_val-k);

        for(int i=0;i<n;i++)
        {
            if(i!=max_ind&& i!=min_ind)
            {
                if(!((arr[i]+k<=current_max)|| (arr[i]-k>=current_min)))
                {
                    int temp_min=arr[i]-k;
                    int temp_max=arr[i]+k;
                    if(current_max-temp_min<=temp_max-current_min)
                    {
                        current_min=temp_min;
                    }
                    else
                    {
                        current_max=temp_max;
                    }

                }
            }
        }

        cout<<min(current_max-current_min,max_val-min_val)<<endl;

    }
    return 0;
}
