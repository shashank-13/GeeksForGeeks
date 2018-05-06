
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
   unordered_multimap<int,ListNode*>myMap;
   priority_queue<int,vector<int>,std::greater<int>>myQueue;
   ListNode *prev,*head;
   prev=head=NULL;
   for(int i=0;i<(int)A.size();i++)
   {
       if(A[i])
       {
           myQueue.push(A[i]->val);
           myMap.insert(make_pair(A[i]->val,A[i]));
       }
   }
   while(!myQueue.empty())
   {
       int val= myQueue.top();
       myQueue.pop();
       auto it = myMap.equal_range(val).first;
       ListNode *newNode = it->second;
       if(head==NULL)
        head=newNode;
       if(prev)
        prev->next = newNode;
       prev=newNode;
       myMap.erase(myMap.equal_range(val).first);
       if(newNode->next)
       {
           myQueue.push(newNode->next->val);
           myMap.insert(make_pair(newNode->next->val,newNode->next));
       }
   }
   return head;
}
