/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* BST Node
struct Node
{
	int key;
	struct Node *left, *right;
};
*/
// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
// Your code goes here
if(root == NULL)
return ;
if(root->key == key)
{
    if(root->left!=NULL)
    {
        Node *temp=root->left;
        while(temp->right)
        {
            temp=temp->right;
        }
        pre=temp;
    }
    if(root->right!=NULL)
    {
        Node *temp = root->right;
        while(temp->left)
        {
            temp=temp->left;
        }
        suc=temp;
    }
    return ;
}
else if(root->key > key)
{
    suc=root;
    findPreSuc(root->left,pre,suc,key);
}
else if(root->key < key)
{
    pre=root;
    findPreSuc(root->right,pre,suc,key);
}
}
