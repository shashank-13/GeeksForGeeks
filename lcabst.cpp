/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*The structure of a BST Node is as follows:
struct Node {
    int data;
    Node * right, * left;
};*/
/*You are required to complete
this function*/
bool findLCA(int n1,int n2,int l,int r,Node **answer,Node *root)
{
    if(root==NULL)
    {
        *answer=NULL;
        return false;
    }
    cout<<root->data<<endl;
    if(l<n1 || r>n2)
    {
        *answer=NULL;
        return false;
    }
    if(findLCA(n1,root->data,l,r,answer,root->left) && findLCA(root->data,n2,l,r,answer,root->right))
    {
        *answer=root;
        return true;
    }
    else
    {
        *answer=NULL;
        return false;
    }
}
Node* LCA(Node *root, int n1, int n2)
{
   //Your code here
   Node *answer=NULL;
   findLCA(INT_MIN,INT_MAX,n1,n2,&answer,root);
   return answer;
}