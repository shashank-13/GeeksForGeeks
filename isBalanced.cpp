int getHeight(TreeNode *A)
{
    if(A==NULL)
        return 0;

    if(A->left==NULL && A->right==NULL)
        return 1;

    int temp1,temp2;
    temp1=temp2=INT_MIN;
    if(A->left)
        temp1=getHeight(A->left);
    if(A->right)
        temp2=getHeight(A->right);

    return max(temp1,temp2)+1;
}
int Solution::isBalanced(TreeNode* A) {

    if(A== NULL || (A->left==NULL && A->right==NULL))
        return 1;
    if(isBalanced(A->left) && isBalanced(A->right))
    {
        int leftHeight = getHeight(A->left);
        int rightHeight = getHeight(A->right);

        if(abs(leftHeight - rightHeight)>1)
            return 0;
        return 1;
    }
    else
        return 0;
}
