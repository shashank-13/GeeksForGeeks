/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    bool flag=false;
    ListNode *current,*slow,*fast;
    current=slow=fast=A;
    while(slow && fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow && slow==fast)
        {
            flag=true;
            break;
        }
    }
    if(!flag)
    {
        return false;
    }
    else
    {
        while(current!=slow)
        {
            current=current->next;
            slow=slow->next;
        }
        return current;
    }
}
