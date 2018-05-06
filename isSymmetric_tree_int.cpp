/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int isSymm(TreeNode* A,TreeNode* B)
{
     if(A==NULL && B==NULL)
        return 1;
    if((A && !B)||(B &&!A))
        return 0;
    return isSymm(A->left,B->right)&&isSymm(A->right,B->left);
}
int Solution::isSymmetric(TreeNode* A) {
    if(A->left==NULL && A->right==NULL)
        return 1;
    else if((A->left && !A->right)||(A->right &&!A->left))
        return 0;
    else
        return isSymm(A->left,A->right);
}

