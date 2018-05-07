/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 bool search(TreeNode* A,int key)
 {
     if(A==NULL)
        return false;

     if(A->val==key)
        return true;

     if(search(A->left,key) || search(A->right,key))
        return true;
    return false;
 }
 int lcaNode(TreeNode*A,int B,int C)
 {
     if(A==NULL)
        return INT_MIN;

    if(A->val==B || A->val==C)
        return A->val;
    int val1=lcaNode(A->left,B,C);
    int val2=lcaNode(A->right,B,C);

    if(val1!=INT_MIN && val2!=INT_MIN)
        return A->val;
    return max(val1,val2);
 }
int Solution::lca(TreeNode* A, int B, int C) {
    if(search(A,B) && search(A,C))
    {
        return lcaNode(A,B,C);
    }
    else
    {
        return -1;
    }
}
