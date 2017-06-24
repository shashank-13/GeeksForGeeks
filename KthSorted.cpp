// A randomized approach to 0(N) solution

#include<bits/stdc++.h>
using namespace std;

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

int partitionquick(int arr[],int low,int high)
{
    int pivot=arr[high];
    int index=low-1;
    for(int j=low;j<=high-1;j++)
    {
      //  cout<<index<<" "<<arr[j]<<" "<<pivot<<endl;
        if(arr[j]<=pivot)
        {
         //   cout<<"SwAPPED"<<endl;
            index++;
            swap(&arr[index],&arr[j]);
        }
    }
    swap(&arr[index+1],&arr[high]);
    return index+1;
}

int RandomizedPartition(int arr[],int low,int high)
{
    int n=(high-low+1);
    int pivot=rand()%n;
    swap(&arr[low+pivot],&arr[high]);
    return partitionquick(arr,low,high);
}

void quicksort(int arr[],int low,int high,int k)
{

    if(low<high)
    {
        int pos=RandomizedPartition(arr,low,high);
        //cout<<pos<<endl;
        if(pos+1==k)
        {
          //  cout<<"Returned Here\n";
              return ;
        }

        else
        {
            if(pos+1<k)
              quicksort(arr,pos+1,high,k);
            else
            quicksort(arr,low,pos-1,k);
        }
    }
}
int main()
{
    int t,n,k;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        cin>>k;
        quicksort(arr,0,n-1,k);
        cout<<arr[k-1]<<endl;
    }
    return 0;
}
