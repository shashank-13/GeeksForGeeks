/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reorderList(ListNode* A) {
    //Calculate the length of list
    int count =0;
    ListNode *current = A;
    while(current!=NULL)
    {
        count++;
        current = current->next;
    }
    count = ceilf(count/2.0);

    current = A;

    int i=1;
    while(i<=count)
    {
        current = current->next;
        i++;
    }


    ListNode *firstHead,*secondHead;
    firstHead = A;
    ListNode *prev=NULL;
    while(current)
    {
        ListNode *temp=current->next;
        current->next = prev;
        prev=current;
        current = temp;
    }
    secondHead = prev;
    while(firstHead && secondHead)
    {
        current = firstHead->next;
        prev = secondHead->next;
        firstHead->next = secondHead;
        secondHead->next = current;
        firstHead=current;
        secondHead=prev;
    }
    if(firstHead)
        firstHead->next=NULL;
    return A;
}

