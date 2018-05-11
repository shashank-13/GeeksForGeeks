
void Solution::connect(TreeLinkNode* A) {

    int level =0;

   queue<pair<TreeLinkNode *,int>>my_queue;
   my_queue.push(make_pair(A,level));
   while(!my_queue.empty())
   {
       auto it= my_queue.front();
       my_queue.pop();
       TreeLinkNode *temp=it.first;

       level = it.second;


       auto  jt=my_queue.front();

       if(!my_queue.empty() && it.second ==jt.second)
       {

           temp->next=jt.first;
       }
       else
       {
            temp->next=NULL;

       }


       if(temp->left)
       my_queue.push(make_pair(temp->left,level+1));

       if(temp->right)
       my_queue.push(make_pair(temp->right,level+1));
   }
}
