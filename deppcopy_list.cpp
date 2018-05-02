/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode* Solution::copyRandomList(RandomListNode* A) {

    RandomListNode *head,*prev;
    head = prev = NULL;

    unordered_map<RandomListNode*,int>numberMap;
    unordered_map<int,RandomListNode*>addressMap;
    RandomListNode *current = A;
    while(current != NULL)
    {
      numberMap.insert(make_pair(current,current->label));
      current = current->next;
    }
    current = A;
    while(current != NULL)
    {
        RandomListNode *newNode = new RandomListNode(current->label);
        newNode ->label=current->label;
        newNode->random=newNode->next=NULL;
        if(prev!=NULL)
            prev->next = newNode;
        if(head==NULL)
            head = newNode;
        prev=newNode;
        addressMap.insert(make_pair(newNode->label,newNode));
        current = current->next;
    }
    current = A;
    RandomListNode *mCurrent = head;
    while(current!=NULL)
    {
        if(current->random!=NULL)
        {
            int val = numberMap[current->random];
            RandomListNode *dest = addressMap[val];
            mCurrent->random = dest;
        }
        current = current->next;
        mCurrent = mCurrent->next;
    }
    return head;
}
