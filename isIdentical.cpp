/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */
/* Should return true if trees with roots as r1 and
   r2 are identical */
bool isIdentical(Node *r1, Node *r2)
{
    //Your Code here
   bool flag =false;
   if(r1->data!=r2->data)
   return false;
   flag=true;
   if((r1->left!=NULL && r2->left!=NULL) || (r1->left==NULL && r2->left==NULL))
   {
       if(r1->left)
       flag=flag && isIdentical(r1->left,r2->left);
   }
   else
   return false;
   if((r1->right!=NULL && r2->right!=NULL) || (r1->right==NULL && r2->right==NULL))
   {
       if(r1->right)
       flag=flag && isIdentical(r1->right,r2->right);
   }
   else
   return false;
   return flag;

}
