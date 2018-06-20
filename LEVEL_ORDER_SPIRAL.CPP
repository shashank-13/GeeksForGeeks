
/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
void printSpiral(Node *root)
{
     //Your code here
    int level,total_val,counter;
    level=1;
    total_val=pow(2,level-1);

    deque<Node *>my_deque;
    my_deque.push_back(root);
    counter = 0;

   while(!my_deque.empty())
    {
        if(level%2)
        {
            Node *temp=my_deque.back();
            my_deque.pop_back();
            cout<<temp->data<<" ";
            counter++;
            if(temp->right)
            my_deque.push_front(temp->right);
            if(temp->left)
            my_deque.push_front(temp->left);
            if(counter==total_val)
            {
                counter=0;
                level++;
                total_val=pow(2,level-1);

            }
        }
        else
        {
            Node *temp=my_deque.front();
            my_deque.pop_front();
            cout<<temp->data<<" ";
            counter++;
            if(temp->left)
            my_deque.push_back(temp->left);
            if(temp->right)
            my_deque.push_back(temp->right);
            if(counter==total_val)
            {
                counter=0;
                level++;
                total_val=pow(2,level-1);

            }
        }

    }

}
