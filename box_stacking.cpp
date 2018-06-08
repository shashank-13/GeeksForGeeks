#include<bits/stdc++.h>
using namespace std;
struct box
{
  int h,w,l;
};
bool comparator(const box a,const box b)
{
	if((a.w*a.l) == (b.w*b.l))
		return a.h > b.h;
	return (a.w*a.l) > (b.w*b.l);
}
int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		box arr[3*n];
		int index=0;
		int h,w,l;
		for(int i=0;i<n;i++)
		{
			cin>>h>>w>>l;
			arr[index].h=h;
			arr[index].l=min(l,w);
			arr[index].w=max(l,w);

			index++;

			arr[index].h=l;
			arr[index].l=min(w,h);
			arr[index].w=max(w,h);

			index++;

			arr[index].h=w;
			arr[index].l=min(h,l);
			arr[index].w=max(h,l);

			index++;
		}

		int answer[3*n];
		sort(arr,arr+(3*n),comparator);

		for(int i=0;i<(3*n);i++)
		{
			answer[i]=arr[i].h;
		}
		for(int i=0;i<(3*n);i++)
		{
			for(int j=0;j<i;j++)
			{
				if(arr[j].l > arr[i].l && arr[j].w > arr[i].w && answer[i] < answer[j]+arr[i].h)
				{
				   // cout<<"answer[j] "<<answer[j]<<" answer[i] "<<answer[i]<<" h= "<<arr[i].h<<endl;
					answer[i]=answer[j]+arr[i].h;
				}
			}
		}
		int final_answer=INT_MIN;
		for(int i=0;i<(3*n);i++)
		{
			final_answer = max(final_answer,answer[i]);
		}
		cout<<final_answer<<endl;
	}

  return 0;
}
