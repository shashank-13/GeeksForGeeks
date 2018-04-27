#include<bits/stdc++.h>
using namespace std;
void swap(char *a,char *b)
{
    char temp = *a;
    *a=*b;
    *b=temp;
}
int main()
{
    int t,k;
    string s;
    cin>>t;
    while(t--)
    {
        cin>>k;
        getchar();
        cin>>s;
        int start=1;
        int swp=0;
        while(k>0 && start<s.length())
        {
            char max_v=s[swp];
            int index=-1;
            string temp="";
            int alt_index=-1;
            char alt_max='0';
            for(int i=start;i<s.length();i++)
            {
                if(s[i]>max_v)
                {
                    max_v=s[i];
                    index=i;
                    temp=s;
                    temp[swp]=s[i];
                    temp[i]=s[swp];
                }
                else if(s[i]==max_v && index!=-1)
                {
                    string tem=s;
                    tem[swp]=s[i];
                    tem[i]=s[swp];
                    if(tem > temp)
                    {
                        temp=tem;
                        max_v=s[i];
                        index=i;

                    }
                }

                if(alt_index==-1 || s[i]>=alt_max)
                {
                    alt_max=s[i];
                    alt_index=i;
                }

            }
            if(index!=-1)
            {
               // printf("First Swapping %c %d to %c %d\n",s[swp],swp,s[index],index);
                swap(&s[swp],&s[index]);
                k--;
                swp++;
                start++;
                cout<<s<<endl;
            }
            else
            {
                bool flag=false;
                for(int a=start;a<s.length();a++)
                {
                    if(s[a]<alt_max && a < alt_index)
                    {
                       printf("Second Swapping %c %c %d to %c %d\n",alt_max ,s[a],a,s[alt_index],alt_index);
                        swap(&s[a],&s[alt_index]);
                        k--;
                        start++;
                        flag=true;
                        break;
                    }
                }
                if(!flag)
                    break;
            }
        }
        cout<<s<<endl;
    }
    return 0;
}
