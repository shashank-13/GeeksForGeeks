
/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*The structure of a BST Node is as follows:
struct Node {
    int data;
    Node * right, * left;
};*/
/*You are required to complete
this function*/
Node* lcaUtil(Node *root,int n1,int n2,int range_min,int range_max)
{

    Node* temp=NULL;
    if(n1>range_min && n2> range_min && n1<range_max && n2<range_max)
    temp = root;
    else
    return temp;

    // Left Node
    if(root->left)
    {
        Node* left_result=lcaUtil(root->left,n1,n2,range_min,root->data);
        if(left_result != NULL)
        temp=left_result;
    }

    //Right Node

    if(root->right)
    {
        Node* right_result=lcaUtil(root->right,n1,n2,root->data,range_max);
        if(right_result != NULL)
        temp=right_result;
    }

    return temp;
}
Node* LCA(Node *root, int n1, int n2)
{
   //Your code here
   return lcaUtil(root,n1,n2,INT_MIN,INT_MAX);
}
