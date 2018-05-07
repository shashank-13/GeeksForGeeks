
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void flat(TreeNode** A)
{
    if((*A)->left)
    {
        TreeNode* move = (*A)->left;
        TreeNode* constant=move;
        while(move->right!=NULL)
            move=move->right;
        TreeNode** moveAdd = &move;
        (*moveAdd)->right = (*A)->right;
        (*A)->right=constant;
        (*A)->left=NULL;
    }
    if((*A)->right)
        flat(&(*A)->right);
}
TreeNode* Solution::flatten(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more detail
    flat(&A);
    return A;
}

