/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */
/* Computes the height of binary tree with given root.  */
int height(Node* node)
{
   // Your code here
   if(node == NULL)
   return 0;
   if(node->left ==NULL && node->right ==NULL)
   return 1;

   int max_height;
   max_height=1;
   if(node->left)
   max_height=max(max_height,height(node->left)+1);
   if(node->right)
   max_height=max(max_height,height(node->right)+1);
   return max_height;
}
