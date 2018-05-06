/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 void checkSum(TreeNode* A,int B,int sum,vector<int>answer,vector<vector<int>>&final_Answer)
{
    sum+=A->val;
    answer.push_back(A->val);

 /*   if(sum>B && A->left == NULL && A->right ==NULL)
    {
        answer.pop_back();
    }*/
    if(sum ==B && A->left == NULL && A->right ==NULL)
    {
        final_Answer.push_back(answer);
        answer.pop_back();
    }
    if(A->left)
    {
       checkSum(A->left,B,sum,answer,final_Answer);
    }
    if(A->right)
    {
        checkSum(A->right,B,sum,answer,final_Answer);
    }
       answer.pop_back();

}
vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    vector<int>answer;
    vector<vector<int>>final_Answer;
    checkSum(A,B,0,answer,final_Answer);
    return final_Answer;
}

