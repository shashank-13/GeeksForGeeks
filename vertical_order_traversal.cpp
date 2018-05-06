/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 void traverse(TreeNode* A,int current,map<int,vector<int>>&myMap)
 {


 }
vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
    vector<vector<int>>final_answer;
    if(A)
    {
        map<int,vector<int>>myMap;
        queue<pair<TreeNode*,int>>myQueue;

        myQueue.push(make_pair(A,0));

        while(!myQueue.empty())
        {
            pair<TreeNode*,int>temp = myQueue.front();
            myQueue.pop();
            if(myMap.find(temp.second)==myMap.end())
             {
                 vector<int>answer;
                 answer.push_back(temp.first->val);
                 myMap.insert(make_pair(temp.second,answer));
             }
             else
             {
                 vector<int>answer = myMap[temp.second];
                 answer.push_back(temp.first->val);
                 myMap[temp.second]=answer;
             }
             if(temp.first->left)
                myQueue.push(make_pair(temp.first->left,temp.second-1));
            if(temp.first->right)
                myQueue.push(make_pair(temp.first->right,temp.second+1));

        }

        for(auto it=myMap.begin();it!=myMap.end();it++)
        {
            final_answer.push_back(it->second);
        }
    }
  return final_answer;
}

