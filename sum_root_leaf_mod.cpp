/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void checkSum(TreeNode* A,vector<long long>answer,vector<vector<long long>>&final_Answer)
{

    answer.push_back((long long)A->val);
    if(A->left == NULL && A->right ==NULL)
    {
        final_Answer.push_back(answer);
    }
    if(A->left)
    {
       checkSum(A->left,answer,final_Answer);
    }
    if(A->right)
    {
        checkSum(A->right,answer,final_Answer);
    }

    answer.pop_back();

}
long long power(long long n)
{
    long long mod=1003;
    long long answer = 1;

    for(int i=1;i<=n;i++)
    {
        answer = (answer%mod *10)%mod;
    }
    return answer;
}
int Solution::sumNumbers(TreeNode* A) {

    long long mod=1003;
    vector<long long>answer;
    vector<vector<long long>>final_Answer;
    checkSum(A,answer,final_Answer);

    long long total = 0;
    for(int i=0;i<(int)final_Answer.size();i++)
    {
        vector<long long>temp=final_Answer[i];
        int n=(int)temp.size()-1;
        long long sum=0;
        for(int j=0;j<=n;j++)
        {
            sum=(sum%mod + (power(n-j)%mod*temp[j]%mod)%mod)%mod;
        }
        //cout<<"sum = "<<sum<<endl;
        total=(total%mod + sum%mod)%mod;
    }

    return total;
}

