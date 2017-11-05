/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*
  reverse alternate nodes and append at the end
  The input list will have at least one element  
  Node is defined as 
  struct node
  {
     int data;
     struct node *next;
  }
*/
void rearrange(struct node *odd)
{
    //add code here
    node *prev1,*prev2,*head;
    prev1=prev2=head=NULL;
    node *current=odd;
    while(current!=NULL)
    {
        if(current->next)
        {
            if(prev2==NULL)
            {
                head=current->next;
                prev2=current->next;
                prev1=current;
                current->next=current->next->next;
                current=current->next;
            }
            else
            {
                prev2->next=current->next;
                prev2=current->next;
                prev1=current;
                current->next=current->next->next;
                current=current->next;
            }
        }
        else
        {
            prev1=current;
            current=current->next;
        }
        
    }
    if(prev1 && prev2)
    {
        prev1->next=NULL;
        prev2->next=NULL;
        node *rev,*cur;
        rev=NULL;
        cur=head;
        while(cur!=NULL)
        {
            node *temp=cur->next;
            cur->next=rev;
            rev=cur;
            cur=temp;
        }
        head=rev;
        while(odd->next)
        {
            odd=odd->next;
        }
        odd->next=head;
    }
}
