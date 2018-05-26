/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
int count1,count2;
count1=count2=0;
ListNode *root1,*root2;
root1=A;
root2=B;
while(root1)
{
    count1++;
    root1=root1->next;
}
while(root2)
{
    count2++;
    root2=root2->next;
}
int diff=abs(count1-count2);
if(count1<count2)
{
    int x=0;
    while(x<diff)
    {
        x++;
        B=B->next;
    }
}
else if(count1 > count2)
{
    int x=0;
    while(x<diff)
    {
        x++;
        A=A->next;
    }
}
//cout<<A->val<<" "<<B->val<<endl;
while(A && B)
{
    if(A==B)
        return A;
    A=A->next;
    B=B->next;
}
return NULL;
}
