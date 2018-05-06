
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void invert(TreeNode** A)
{
    if(*A)
    {
        TreeNode* temp = (*A)->left;
        (*A)->left=(*A)->right;
        (*A)->right=temp;
        if((*A)->left)
            invert(&((*A)->left));
        if((*A)->right)
            invert(&((*A)->right));
    }
}
TreeNode* Solution::invertTree(TreeNode* A) {
    invert(&A);
    return A;
}
