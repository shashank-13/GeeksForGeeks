#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int arr[n][n];
		bool visited[n][n];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				scanf("%d",&arr[i][j]);

				visited[i][j]=false;
			}
		}

		pair<int,int> source_point,destination_point;

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(arr[i][j]==1)
				{
					source_point.first=i;
					source_point.second=j;

				}
				else if(arr[i][j]==2)
				{
					destination_point.first=i;
					destination_point.second=j;
				}
			}
		}


	 bool flag=false;

	 queue<pair<int,int> > my_queue;
	 my_queue.push(source_point);
	 visited[source_point.first][source_point.second]=true;

	 while(!my_queue.empty())
	 {
	 	pair<int,int> temp = my_queue.front();
	 	my_queue.pop();
	 	//printf("%d %d\n",temp.first,temp.second);
	 	if(temp.first == destination_point.first && temp.second == destination_point.second)
	 	{
         flag=true;
         break;
	 	}
	 	int x_index,y_index;
	 	x_index=temp.first;
	 	y_index=temp.second;
	 	if(x_index>0)
	 	{
	 		if(!visited[x_index-1][y_index] && arr[x_index-1][y_index] !=0)
	 		{
             pair<int,int>temp_pair;
             temp_pair.first=x_index-1;
             temp_pair.second=y_index;
             my_queue.push(temp_pair);
             visited[x_index-1][y_index]=true;
	 		}



	 	}

	 	if(y_index > 0)
	 	{
           if(!visited[x_index][y_index-1] && arr[x_index][y_index-1] !=0)
	 		{
             pair<int,int>temp_pair;
             temp_pair.first=x_index;
             temp_pair.second=y_index-1;
             my_queue.push(temp_pair);
             visited[x_index][y_index-1]=true;
	 		}
	 	}
	 	if(y_index < n-1)
	 	{
           if(!visited[x_index][y_index+1] && arr[x_index][y_index+1] !=0)
	 		{
             pair<int,int>temp_pair;
             temp_pair.first=x_index;
             temp_pair.second=y_index+1;
             my_queue.push(temp_pair);
             visited[x_index][y_index+1]=true;
	 		}
	 	}

	 	if(x_index<n-1)
	 	{
	 		if(!visited[x_index+1][y_index] && arr[x_index+1][y_index] !=0)
	 		{
             pair<int,int>temp_pair;
             temp_pair.first=x_index+1;
             temp_pair.second=y_index;
             my_queue.push(temp_pair);
             visited[x_index+1][y_index]=true;
	 		}
	 	}


	 }

	if(flag)
	 {
	 	printf("1\n");
	 }
	 else
	 {
	 	printf("0\n");
	 }
	}
	return 0;
}
