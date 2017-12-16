struct node
{
    int data1,data2;
    struct node *left,*right;
};
node *head=NULL;
node *rear=NULL;
int n;
int current=0;
unordered_map<int,node*>myMap;
LRUCache::LRUCache(int N)
{
     //Your code here
     n=N;
}
node * getNode(int x,int y)
{
    struct node *newnode=new node();
    newnode->data1=x;
    newnode->data2=y;
    newnode->left=newnode->right=NULL;
    return newnode;
}
/*Sets the key x with value y in the LRU cache */
void LRUCache::set(int x, int y)
{
     //Your code here
     if(myMap.find(x)==myMap.end())
     {
      if(current<n)
      {
          struct node* newnode =getNode(x,y);
          if(head==NULL)
          {
              head=rear=newnode;
          }
          else
          {
           newnode->right=head;
         head->left=newnode;
         head=newnode;
          }
         myMap.insert(make_pair(x,newnode));
         current++;
      }
      else
      {
          struct node* newnode =getNode(x,y);
          node *prev=rear->left;
          int val=rear->data1;
          prev->right=NULL;
          rear->left=rear->right=NULL;
          rear=prev;
          newnode->right=head;
         head->left=newnode;
         head=newnode;
         myMap.erase(val);
         myMap.insert(make_pair(x,newnode));
      }
     }
}
/*Returns the value of the key x if
present else returns -1 */
int LRUCache::get(int x)
{
    //Your code here
    if(myMap.find(x)==myMap.end())
        return -1;
    auto it=myMap.find(x);
    int answer=it->second->data2;

        node *prev,*current;
         prev=current=head;
         while(current->data1!=x)
         {
             prev=current;
             current=current->right;
         }
         if(rear==current)
            rear=prev;
         struct node* newnode =getNode(x,answer);
         prev->right=current->right;
         if(current->right)
            current->right->left=prev;
         current->right=current->left=NULL;
         newnode->right=head;
         head->left=newnode;
         head=newnode;
         myMap.erase(x);
         myMap.insert(make_pair(x,newnode));

    return answer;
}
