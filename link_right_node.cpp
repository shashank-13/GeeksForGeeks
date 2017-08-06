/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* struct Node
{
  int data;
  Node *left,  *right;
  Node *nextRight;  // This has garbage value in input trees
}; */
// Should set the nextRight for all nodes
void connect(Node *p)
{
   // Your Code Here
   int level =0;

   queue<pair<Node *,int>>my_queue;
   my_queue.push(make_pair(p,level+1));
   while(!my_queue.empty())
   {
       auto it= my_queue.front();
       my_queue.pop();
       Node *temp=it.first;

       level = it.second;

      //cout<<my_queue.size()<<endl;

       auto  jt=my_queue.front();

       if(!my_queue.empty() && it.second ==jt.second)
       {

           temp->nextRight=jt.first;
       }
       else
       {
            temp->nextRight=NULL;
            //level++;
       }

     // cout<<temp->data<<" "<<level<<endl;

       if(temp->left)
       my_queue.push(make_pair(temp->left,level+1));

       if(temp->right)
       my_queue.push(make_pair(temp->right,level+1));



   }

}

