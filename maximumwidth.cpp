/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*  Structure of a Binary Tree 
struct Node
{
    int data;
    Node* left, *right;
}; */
/* Function to get the maximum width of a binary tree*/
int getMaxWidth(Node* root)
{
   // Your code here
   int width[105];
   for(int i=0;i<=104;i++)
        width[i]=0;
   int final_answer=0;
   queue<pair<Node*,int>>myqueue;
   myqueue.push(make_pair(root,1));
   while(!myqueue.empty())
   {
       pair<Node*,int>temp=myqueue.front();
       myqueue.pop();
       width[temp.second]++;
       if(width[temp.second]>final_answer)
        final_answer=width[temp.second];
       if(temp.first->left)
        myqueue.push(make_pair(temp.first->left,temp.second+1));
       if(temp.first->right)
        myqueue.push(make_pair(temp.first->right,temp.second+1));
   }
   return final_answer;
}
