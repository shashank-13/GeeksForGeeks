/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* struct Node
 {
   int data;
   Node* next;
 }; */
/* Should return data of n'th node from the end of linked list */


int getNthFromLast(Node *head, int n)
{
       // Your code here
       Node *prev,*current,*next_point;

       prev=NULL;
       current=next_point=head;

       while(current!=NULL)
       {
           next_point=current->next;
           current->next=prev;
           prev=current;
           current=next_point;
       }

       if(prev==NULL)
       return -1;
       else
       {
           for(int i=1;i<n;i++)
           {
               if(prev==NULL)
               break;
               else
               prev=prev->next;
           }
           if(prev==NULL)
           return -1;
           else
           return prev->data;
       }

}
