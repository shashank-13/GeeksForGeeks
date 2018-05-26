/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 TreeNode* constructTree(ListNode *A)
 {
     if(A==NULL)
        return NULL;
        
     ListNode *slow,*fast;
     slow=fast=(A);
     ListNode *prev=NULL;
     
     while(slow && fast && fast->next)
     {
         prev=slow;
         slow=slow->next;
         fast=fast->next->next;
     }
     
     ListNode * temp = slow->next;
     slow->next = NULL;
     
     if(prev)
        prev->next=NULL;
        
     TreeNode *root = new TreeNode(slow->val);
     root->left=constructTree((prev==NULL)?NULL:A);
     root->right=constructTree(temp);
     
     return root;
     
 }
TreeNode* Solution::sortedListToBST(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    return constructTree(A);
}
