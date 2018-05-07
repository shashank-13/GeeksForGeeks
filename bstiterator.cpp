
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
stack<TreeNode*>first;
TreeNode *start,*constant;
bool flag;

BSTIterator::BSTIterator(TreeNode *root) {

    start=NULL;

    while(!first.empty())
        first.pop();
    start=root;
    while(start && start->left)
    {
        first.push(start);
        start = start->left;
    }
    if(start)
    {
        constant = start;
        first.push(start);
    }
    flag=true;
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {

    if(start==NULL)
        return false;

    if(start->right!=NULL)
        return true;

    if(!first.empty() && (start == constant || first.top()->val > start->val))
        return true;

    return false;

}

/** @return the next smallest number */
int BSTIterator::next() {

    if(flag)
    {
        flag=false;
        first.pop();
        return start->val;
    }
    else if(start->right)
    {
        start=start->right;
        while(start->left)
        {
            first.push(start);
            start=start->left;
        }

        return start->val;
    }
    else
    {
        start=first.top();
        first.pop();
        return start->val;
    }
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
