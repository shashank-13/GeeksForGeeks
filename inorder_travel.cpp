vector<int> Solution::inorderTraversal(TreeNode* A) {

    stack<TreeNode*>myStack;
    unordered_map<TreeNode*,bool>myMap;

    TreeNode *current = A;

    vector<int>answer;

    while(current)
    {
        if(current->left && myMap.find(current->left) == myMap.end())
        {
            myStack.push(current);
            current = current->left;
        }
        else if(current->right && myMap.find(current->right) == myMap.end())
        {
            answer.push_back(current->val);
            myMap.insert(make_pair(current,true));
            current = current->right;
        }
        else if(myMap.find(current)==myMap.end())
        {
            answer.push_back(current->val);
            myMap.insert(make_pair(current,true));
            if(!myStack.empty())
            {
                current = myStack.top();
                myStack.pop();
            }
            else
            {
                current =NULL;
            }
        }
        else
        {
             if(!myStack.empty())
            {
                current = myStack.top();
                myStack.pop();
            }
            else
            {
                current =NULL;
            }
        }
    }

    return answer;
}
