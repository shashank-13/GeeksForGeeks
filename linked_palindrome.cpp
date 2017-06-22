#include<bits/stdc++.h>
using namespace std;
/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};

void append(struct Node** head_ref, struct Node **tail_ref, int new_data)
{
    struct Node* new_node = new Node;
    new_node->data  = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL)
       *head_ref = new_node;
    else
       (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}


bool isPalindrome(Node *head)
{
    //Your code here
 if(head==NULL || head->next==NULL)
 return 1;
  else if(head->next->next==NULL)
 {
     if(head->data==head->next->data)
     return 1;
     else
     return 0;
 }
 else
 {
     Node *temp=head;
     int length=0;
     while(temp!=NULL)
     {
         length++;
         temp=temp->next;
     }

     if(length%2==1)
     length++;

     length=length/2;
     Node *prev_node,*next_node;

     next_node=head;

     for(int i=1;i<=length;i++)
     {
         prev_node=next_node;
         next_node=next_node->next;
     }

     prev_node->next=NULL;

     Node *back_head;

     while(next_node!=NULL)
     {
         Node *temp=next_node->next;
         next_node->next=prev_node;
         prev_node=next_node;
         next_node=temp;
     }
     back_head=prev_node;

     while(head!=NULL)
     {
         if(head->data!=back_head->data)
         return 0;
         head=head->next;
         back_head=back_head->next;
     }
     return 1;

 }
}
/* Driver program to test above function*/
int main()
{
  int T,i,n,l;
    cin>>T;
    while(T--){
    struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }
   	cout<<isPalindrome(head)<<endl;
    }
    return 0;
}

