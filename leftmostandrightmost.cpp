/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* Function to print corner node at each level */
void printCorner(Node *root)
{
    if(root ==NULL)
        return ;
// Your code goes here
bool visited[105];

for(int i=0;i<=104;i++)
visited[i]=false;

queue<pair<Node*,int>>my_Queue;
my_Queue.push(make_pair(root,1));
while(!my_Queue.empty())
{
    pair<Node*,int> top = my_Queue.front();
    my_Queue.pop();
    if(visited[top.second]==false)
    {
        cout<<top.first->key<<" ";
        visited[top.second]=true;
    }
    else if(my_Queue.empty() || top.second+1==my_Queue.front().second)
    cout<<top.first->key<<" ";
    if(top.first->left)
    my_Queue.push(make_pair(top.first->left,top.second+1));
    if(top.first->right)
    my_Queue.push(make_pair(top.first->right,top.second+1));
}

}
