/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 TreeNode* constructTree(vector<int>&A,vector<int>&B,int &index,int low,int high)
 {
     if(low>high)
        return NULL;
     int ind=-1;
     for(int i=low;i<=high;i++)
     {
         if(B[i]==A[index])
         {
             ind=i;
             break;
         }
     }
     TreeNode *root = new TreeNode(A[index]);
    // cout<<root->val<<" "<<ind<<endl;
     index++;
     root->left =constructTree(A,B,index,low,ind-1);
     root->right = constructTree(A,B,index,ind+1,high);

     return root;
 }
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    int answer=0;
    return constructTree(A,B,answer,0,(int)B.size()-1);
}

