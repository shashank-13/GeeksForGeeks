/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*
Structure of the node of the tree is as
struct Node
{
	int key;
	struct Node* left, *right;
};
*/
// complete this function
// return true/false if the is Symmetric or not
bool isIdentical(Node *r1, Node *r2)
{
    //Your Code here
   bool flag =false;
   if(r1->key!=r2->key)
   return false;
   flag=true;
   if((r1->left!=NULL && r2->right!=NULL) || (r1->left==NULL && r2->right==NULL))
   {
       if(r1->left)
       flag=flag && isIdentical(r1->left,r2->right);
   }
   else
   return false;
   if((r1->right!=NULL && r2->left!=NULL) || (r1->right==NULL && r2->left==NULL))
   {
       if(r1->right)
       flag=flag && isIdentical(r1->right,r2->left);
   }
   else
   return false;
   return flag;

}

bool isSymmetric(struct Node* root)
{
	// Code here
	return isIdentical(root->left,root->right);
}
