{
//Author- Sajal Agrawal
//sajal.agrawal1997@gmail.com
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
int indx,ans;
struct Node{
    int data;
    Node *left,*right;
    Node(int d){
        data=d;
        left=right=NULL;
    }
};
int pairsViolatingBST(Node *root,int n);
void insert(Node *root,int a,int b,char ch);
int main() {
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
		indx=0;
		ans=0;
        Node *root=NULL;
        for(int j=0;j<n;j++){
            int a,b;
            char ch;
            cin>>a>>b>>ch;
            if(root==NULL){
                root=new Node(a);
                switch(ch){
                    case 'L':root->left=new Node(b);
                            break;
                    case 'R':root->right=new Node(b);
                            break;
                }
            }else{
                insert(root,a,b,ch);
            }
        }
		cout<<pairsViolatingBST(root,n)<<"
";
    }
	return 0;
}
void insert(Node *root,int a,int b,char ch){
    if(root==NULL)return;
    if(root->data==a){
        switch(ch){
            case 'L':root->left=new Node(b);
                    break;
            case 'R':root->right=new Node(b);
                    break;
        }
    }else{
        insert(root->left,a,b,ch);
        insert(root->right,a,b,ch);
    }
}

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* The structure of Node
struct Node{
    int data;
    Node *left,*right;
    Node(int d){
        data=d;
        left=right=NULL;
    }
}; */
/*You are required to complete below method */
long long mod = 1000000007;
long long merge(vector<int>&arr,long long l,long long m,long long r)
{
    long long count=0;
long long n1,n2,i,j,k;
n1=m-l+1;
n2=r-m;
int arr1[n1],arr2[n2];

for(i=0;i<n1;i++)
{
 arr1[i]=arr[l+i];
}
    for(j=0;j<n2;j++)
    {
        arr2[j]=arr[m+1+j];

    }


    i=0;
    j=0;
    k=l;
    while(i<n1&&j<n2)
    {
        if(arr1[i]<=arr2[j])
        {
            arr[k]=arr1[i];
            i++;
        }
      else
      {
          arr[k]=arr2[j];
          count=(count%mod + (n1-i)%mod)%mod;
            j++;

      }
      k++;
    }
    while(i<n1)
    {
        arr[k]=arr1[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k]=arr2[j];
        j++;
        k++;
    }
return count;
}
long long mergesort(vector<int>&arr,long long l,long long r)
{
    long long count=0;
    long long m;
    if(l<r)
    {
        m=(l+r)/2;
       count= mergesort(arr,l,m);
        count=(count%mod +mergesort(arr,m+1,r)%mod)%mod;
        count=(count%mod +merge(arr,l,m,r)%mod)%mod;

    }
    return count;
}

void recurse(Node *root,vector<int>&A)
{
    if(root->left)
        recurse(root->left,A);
    A.push_back(root->data);
    if(root->right)
        recurse(root->right,A);
}
int pairsViolatingBST(Node *root,int n){
    if(root==NULL)
        return 0;
          /*Your code here */
        vector<int>arr;
        recurse(root,arr);
        return mergesort(arr,(long long)0,(long long)arr.size()-1);

}

