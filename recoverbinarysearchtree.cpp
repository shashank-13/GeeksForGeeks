/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 int getMax(TreeNode* A)
 {
     if(A==NULL)
        return INT_MIN;

     if(A->left==NULL && A->right==NULL)
        return A->val;

    return max(A->val,max(getMax(A->left),getMax(A->right)));

 }
  int getMin(TreeNode* A)
 {
     if(A==NULL)
        return INT_MAX;

     if(A->left==NULL && A->right==NULL)
        return A->val;

    return min(A->val,min(getMin(A->left),getMin(A->right)));

 }
 void getResult(TreeNode* A,vector<int> &result)
 {
     int leftMax=getMax(A->left);
     int rightMin=getMin(A->right);

     if(leftMax!=INT_MIN && rightMin!=INT_MAX && leftMax>A->val && rightMin<A->val)
     {
         result.push_back(leftMax);
         result.push_back(rightMin);
         return ;
     }
     else if(leftMax!=INT_MIN && leftMax>A->val)
     {
         result.push_back(A->val);
         result.push_back(leftMax);
         return ;
     }
     else if(rightMin!=INT_MAX && rightMin<A->val)
     {
         result.push_back(A->val);
         result.push_back(rightMin);
         return ;
     }
     else
     {
         if(A->left)
            getResult(A->left,result);
        if(A->right)
            getResult(A->right,result);
     }
 }

vector<int> Solution::recoverTree(TreeNode* A) {

    vector<int>result;
    getResult(A,result);
    sort(result.begin(),result.end());
    return result;

}

