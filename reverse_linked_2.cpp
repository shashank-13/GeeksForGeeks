/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    if(C==B)
     return A;

    ListNode *prevStart,*start,*end,*prevEnd;
    int count;
    count=1;
    prevStart=start=end=prevEnd=NULL;
    ListNode *current =A;
    while(current && count < B)
    {
        prevStart=current;
        current=current->next;
        count++;
    }
    start=current;
    count = 0;
    end = NULL;
    while(current && count <=C-B)
    {
        prevEnd=current->next;
        current->next=end;
        end=current;
        current = prevEnd;
        count++;
    }
    if(prevStart)
    {
    prevStart->next = end;
    start->next = prevEnd;
    return A;
    }
    else
    {
         start->next = prevEnd;
         return end;
    }

}

