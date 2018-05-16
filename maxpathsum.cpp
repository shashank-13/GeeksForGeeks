/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int pathSum(TreeNode *A,int &answer)
{
    if(A==NULL)
     {
         return 0;
     }
    if(A->left==NULL && A->right==NULL)
    {
        answer=max(answer,A->val);
        return A->val;
    }
    int leftSum=pathSum(A->left,answer);
    int rightSum=pathSum(A->right,answer);
    
    int current = A->val;
    int temp=current;
    current=max(current,max(current+leftSum+rightSum,max(current+leftSum,current+rightSum)));
    answer = max(answer,current);
    return max(temp,max(temp+leftSum,temp+rightSum));
}
int Solution::maxPathSum(TreeNode* A) {
    int answer = INT_MIN;
    pathSum(A,answer);
    return answer;
}
