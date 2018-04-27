#include<bits/stdc++.h>
using namespace std;
bool comparision(const std::string &s1,const std::string &s2)
{
    string first_String = s1+s2;
    string second_String =s2+s1;
    return first_String >= second_String;
}
string getSolution(vector<int>A)
{
     string final_Answer="";
     vector<string>arr;
    for(int i=0;i<A.size();i++)
    {
        arr.push_back(std::to_string(A[i]));
    }
    sort(arr.begin(),arr.end(),&comparision);
    for(int i=0;i<A.size();i++)
    {
        final_Answer+=arr[i];
      //  cout<<arr[i]<<" ";
    }


    return final_Answer;

}
int main()
{
    int n,val;
    cin>>n;
    vector<int>temp_Vector;
    for(int i=0;i<n;i++)
    {
        cin>>val;
        temp_Vector.push_back(val);
    }
    cout<<getSolution(temp_Vector);
    return 0;
}
