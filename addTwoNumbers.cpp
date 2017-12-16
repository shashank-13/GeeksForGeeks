/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*struct Node
{
    int data;
   Node* next;
}; */
//write a function returns the resultant linked list
Node *getNode(int x)
{
    Node *temp =new Node();
    temp->data=x;
    temp->next=NULL;
    return temp;
}
Node*  addTwoLists(Node* first, Node* second){
  // Code here
  Node *head=NULL;
  Node *prev=NULL;
  int carry;
  carry=0;
  while(first!=NULL && second!=NULL)
  {
      int sum=(first->data+second->data+carry)%10;
      if(first->data+second->data+carry>9)
        carry=1;
      else
        carry=0;
   //   cout<<sum<<" "<<carry<<endl;
      Node *newnode=getNode(sum);
      if(head==NULL)
      {
          head=newnode;
          prev=head;
      }
      else
      {
          prev->next=newnode;
          prev=newnode;
      }
      first=first->next;
      second=second->next;
  }
  if(first==NULL && second==NULL && carry==1)
  {
       Node *newnode=getNode(1);
        prev->next=newnode;
  }
  while(first!=NULL)
  {
      int sum=(first->data+carry)%10;
      if(first->data+carry>9)
        carry=1;
      else
        carry=0;
      Node *newnode=getNode(sum);
      if(head==NULL)
      {
          head=newnode;
          prev=head;
      }
      else
      {
          prev->next=newnode;
          prev=newnode;
      }
      first=first->next;   
  }
  while(second!=NULL)
  {
      int sum=(second->data+carry)%10;
      if(second->data+carry>9)
        carry=1;
      else
        carry=0;
      Node *newnode=getNode(sum);
      if(head==NULL)
      {
          head=newnode;
          prev=head;
      }
      else
      {
          prev->next=newnode;
          prev=newnode;
      }
      second=second->next;
  }
  return head;
}