/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int checkSum(TreeNode* A,int B,int sum)
{
    sum+=A->val;
    if(sum>B && A->left == NULL && A->right ==NULL)
        return 0;
    if(sum ==B && A->left == NULL && A->right ==NULL)
        return 1;
    if(A->left && A->right)
    {
        if(checkSum(A->left,B,sum) || checkSum(A->right,B,sum))
            return 1;
        return 0;
    }
    else if(A->left)
    {
        if(checkSum(A->left,B,sum))
            return 1;
        return 0;
    }
    else if(A->right)
    {
        if(checkSum(A->right,B,sum))
            return 1;
        return 0;
    }
    else
        return 0;
}
int Solution::hasPathSum(TreeNode* A, int B) {

    return checkSum(A,B,0);
}

