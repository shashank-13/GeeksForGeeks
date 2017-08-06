
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
// A wrapper over leftViewUtil()

int global_level = 0;

void final_Print(Node *root,int currentLevel)
{
     if(root)
   {
       if(currentLevel > global_level)
       cout<<root->data<<" ";
       global_level=max(global_level,currentLevel);
       if(root->left)
       {
           //cout<<endl<<root->left->data<<endl;
           final_Print(root->left,currentLevel+1);
       }
       if(root->right)
       {
          // cout<<endl<<root->right->data<<endl;
        final_Print(root->right,currentLevel+1);
       }

   }
}


void leftView(Node *root)
{
   // Your code here
   global_level=0;
   final_Print(root,1);

}
