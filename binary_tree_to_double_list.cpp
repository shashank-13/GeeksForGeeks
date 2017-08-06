/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* Structure for tree and linked list
struct Node
{
    int data;
    // left is used as previous and right is used
    // as next in DLL
    Node *left, *right;
}; */
// This function should convert a given Binary tree to Doubly
// Linked List
// root --> Root of Binary Tree
// head_ref --> Pointer to head node of created doubly linked list
void convertUtil(Node *root,Node **list_Head,Node *pre,Node *succ,int key)
{
    if(root->left)
    convertUtil(root->left,list_Head,pre,root,key);
    if(root->right)
    convertUtil(root->right,list_Head,root,succ,key);

    if(root->data == key)
    {
         *list_Head = root;
    }

    if(root->left==NULL)
    {
        //if(pre)
     //  cout<<"Pre -- "<<root->data<<" "<<pre->data<<endl;
        root->left = pre;
    }
    else
    {
        Node *temp=root->left;
        while(temp->right && temp->right->data != root->data)
        temp=temp->right;
        root->left = temp;
    }

    if(root->right == NULL)
    {
        //if(succ)
       // cout<<"Succ --"<<root->data<<" "<<succ->data<<endl;
        root->right = succ;
    }
    else
    {
        Node* temp=root->right;
        while(temp->left  && temp->left->data != root->data)
        temp=temp->left;
        root->right=temp;
    }

}
void BToDLL(Node *root, Node **head_ref)
{
  Node *temp = root;
  while(temp->left)
  temp=temp->left;


  convertUtil(root,head_ref,NULL,NULL,temp->data);
}

