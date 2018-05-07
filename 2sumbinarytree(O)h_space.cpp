/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 stack<TreeNode*>first,second;

 int search(TreeNode* start,TreeNode* end,int B)
 {
    // cout<<"Start = "<<start->val<<" End = "<<end->val<<endl;
     if(start->val+end->val==B && start!=end)
        return 1;
     else if(start->val + end->val < B)
     {
      TreeNode* current = start->right;
      if(current)
      {
          while(current->left!=NULL)
          {
           first.push(current);
           current=current->left;
          }
      }
      if(current==NULL)
      {
          if(first.empty() || first.top()->val < start->val)
            return 0;
          current=first.top();
          first.pop();
      }
      start=current;
      return search(start,end,B);
     }
     else if(start->val + end->val > B)
     {
         TreeNode* endcurrent = end->left;
      if(endcurrent)
      {
          while(endcurrent->right!=NULL)
          {
              second.push(endcurrent);
              endcurrent = endcurrent->right;
          }
      }
      if(endcurrent==NULL)
      {
          if(second.empty() || second.top()->val > end->val)
            return 0;
           endcurrent = second.top();
           second.pop();
      }
      end=endcurrent;
       return search(start,end,B);
     }
     else
     {
         return 0;
     }

 }
int Solution::t2Sum(TreeNode* A, int B) {

    while(!first.empty())
        first.pop();
    while(!second.empty())
        second.pop();

    TreeNode *current = A;
    TreeNode *start,*end;
    while(current->left!=NULL)
    {
        first.push(current);
        current = current->left;
    }
    start=current;
    current = A;
    while(current->right!=NULL)
    {
        second.push(current);
        current = current->right;
    }
    end=current;

    if(start==end)
        return 0;

    return search(start,end,B);

}

