/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* A, int B) {

    if(A == NULL)
        return A;
    ListNode *prev,*current;
    prev=NULL;
    current=A;
    for(int i=1;(i<=B) && (current);i++)
    {
        ListNode *temp=current->next;
        current->next=prev;
        prev=current;
        current=temp;
    }
    A->next=reverseList(current,B);
    return prev;
}
