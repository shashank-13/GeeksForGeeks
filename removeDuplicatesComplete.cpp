/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {

    ListNode *head,*prev;
    head=prev=NULL;
    ListNode *current = A;

    while(current)
    {
        int temp = current->val;
        ListNode *move = current->next;
        while(move && move->val == temp)
            move = move->next;
        if(move == current->next)
        {
            if(head==NULL)
                head = current;
            if(prev)
                prev->next=current;
            prev=current;
            current->next=NULL;
        }
        current = move;
    }

    return head;
}
