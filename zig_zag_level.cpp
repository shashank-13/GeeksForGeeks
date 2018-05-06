
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {

    vector<vector<int>>final_answer;

    int level=0;

    stack<pair<TreeNode*,int>>currentStack,nextStack;

    vector<int>answer;

    currentStack.push(make_pair(A,level));

    while(!currentStack.empty())
    {
        pair<TreeNode*,int>temp=currentStack.top();
        currentStack.pop();

        //cout<<temp.first->val<<" "<<temp.second<<endl;

        if(temp.second==level)
        {
            answer.push_back(temp.first->val);
            if(level%2 ==0)
            {
                if(temp.first->left)
                    nextStack.push(make_pair(temp.first->left,level+1));
                if(temp.first->right)
                    nextStack.push(make_pair(temp.first->right,level+1));
            }
            else
            {
                if(temp.first->right)
                    nextStack.push(make_pair(temp.first->right,level+1));
                if(temp.first->left)
                    nextStack.push(make_pair(temp.first->left,level+1));
            }
        }

        else
        {
            final_answer.push_back(answer);
            answer.erase(answer.begin(),answer.end());
            level=temp.second;
            answer.push_back(temp.first->val);
            if(level%2 ==0)
            {
                if(temp.first->left)
                    nextStack.push(make_pair(temp.first->left,level+1));
                if(temp.first->right)
                    nextStack.push(make_pair(temp.first->right,level+1));
            }
            else
            {
                if(temp.first->right)
                    nextStack.push(make_pair(temp.first->right,level+1));
                if(temp.first->left)
                    nextStack.push(make_pair(temp.first->left,level+1));
            }

        }
        if(currentStack.empty())
        {
            currentStack = nextStack;
            while(!nextStack.empty())
                nextStack.pop();
        }
    }

    if(answer.size()>0)
    {
      final_answer.push_back(answer);
    }

    return final_answer;
}
