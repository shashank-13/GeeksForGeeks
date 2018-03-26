#include<bits/stdc++.h>
using namespace std;
bool comparator(int& a,int& b)
{
    string first = to_string(a);
    string second = to_string(b);

    return first+second > second+first;

}
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr,arr+n,comparator);
        for(int i=0;i<n;i++)
            cout<<arr[i];
        cout<<endl;
    }
    return 0;
}
