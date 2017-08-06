/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* Tree node class
struct Node
{
    int data;
    Node *left, *right;
}; */
// Method that prints the bottom view.
map<int,int>print_Tree;
void bottomVisit(Node *root,int level)
{
    if(root)
    {
        if(print_Tree.find(level)!=print_Tree.end())
        print_Tree.erase(level);
        print_Tree.insert(make_pair(level,root->data));
        if(root->left)
        bottomVisit(root->left,level-1);
        if(root->right)
        bottomVisit(root->right,level+1);
    }
}
void bottomView(Node *root)
{
   // Your Code Here
   print_Tree.clear();
   bottomVisit(root,0);
   for(auto it=print_Tree.begin();it!=print_Tree.end();it++)
   {
       cout<<it->second<<" ";
   }
}

