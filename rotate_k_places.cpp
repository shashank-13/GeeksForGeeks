
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* A, int B) {


    ListNode *current = A;
    int length =0;
    ListNode *last=NULL;
    while(current)
    {
        length++;
        last = current;
        current=current->next;
    }

    if(B>=length)
        B = B%length;

    if(B==0)
    return A;

    int move = length-B;
    int i=1;
        ListNode *prev=NULL;
        current = A;
        while(i<=move)
        {
            prev=current;
            current = current->next;
            i++;
        }
        if(prev)
        prev->next=NULL;
        last->next=A;
        return current;
}
