/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*
  Rotate a linked list after node k
  The input list will have at least one element
  Return pointer to head of rotated linked list
  Node is defined as
  struct node
  {
     int data;
     struct node *next;
  }
*/
void rotate(struct node **head_ref, int k)
{
  // Complete this method

  struct node * head,*prev,*current;

  head=prev=current=*head_ref;

  for(int i=1;i<=k;i++)
  {
      prev=current;
      current=current->next;
  }

  if(current!=NULL)
  {
       head=current;

  while(current->next!=NULL)
  current=current->next;

  current->next=*head_ref;
  prev->next=NULL;
  *head_ref=head;
  }


}

