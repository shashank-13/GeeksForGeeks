/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* buildtree(vector<int>A,int low,int high)
{
    if(low>high)
        return NULL;
    int max_val,index;
    max_val=INT_MIN;

    for(int i=low;i<=high;i++)
    {
        if(A[i]>max_val)
        {
            max_val = A[i];
            index=i;
        }
    }
    TreeNode *root = new TreeNode(A[index]);
    root->left = buildtree(A,low,index-1);
    root->right = buildtree(A,index+1,high);
    return root;
}
TreeNode* Solution::buildTree(vector<int> &A) {
    int n=(int)A.size();
    return buildtree(A,0,n-1);
}

