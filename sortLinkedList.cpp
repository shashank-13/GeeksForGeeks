/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* merge(ListNode *A,ListNode *B)
{
    ListNode *prev,*head;
    prev=head=NULL;

    while(A && B)
    {
        if(A->val<=B->val)
        {
            if(head==NULL)
                head = A;
            if(prev)
                prev->next=A;
            prev=A;
            A=A->next;
        }
        else
        {
            if(head==NULL)
                head = B;
            if(prev)
                prev->next=B;
            prev=B;
           B=B->next;
        }
    }

    while(A)
    {
        if(head==NULL)
                head = A;
            if(prev)
                prev->next=A;
            prev=A;
            A=A->next;
    }

    while(B)
    {
          if(head==NULL)
                head = B;
            if(prev)
                prev->next=B;
            prev=B;
           B=B->next;
    }

    return head;
}
void splitList(ListNode *A,ListNode **frontHead,ListNode **backHead)
{
    ListNode *slow,*fast,*prev;
    slow=fast=A;
    while(slow&&fast && fast->next)
    {
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    *frontHead = A;
    *backHead=slow;
    prev->next=NULL;
}
void mergeSort(ListNode **A)
{
    ListNode *head = *A;
    if(head == NULL || head->next==NULL)
        return ;

    ListNode *A1,*B1;
    splitList(head,&A1,&B1);
    mergeSort(&A1);
    mergeSort(&B1);
    *A = merge(A1,B1);
}
ListNode* Solution::sortList(ListNode* A) {
 mergeSort(&A);
 return A;
}

