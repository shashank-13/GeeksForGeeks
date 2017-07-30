
/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* Link list Node
struct Node {
    int data;
    Node* next;
}; */
Node* SortedMerge(Node* head1,   Node* head2)
{
    // Your Code Here

    Node *prev =NULL;

    Node *unchange_Pointer;

    if(head1->data<=head2->data)
    unchange_Pointer = head1;
    else
    unchange_Pointer = head2;

    while(head1 && head2)
    {
        if(head1->data<=head2->data)
        {
            if(prev==NULL)
            prev=head1;
            else
            {
                prev->next=head1;
                prev=head1;
            }

            head1=head1->next;
        }
        else
        {
            if(prev==NULL)
            prev=head2;
            else
            {
                 prev->next=head2;
                 prev=head2;
            }

            head2=head2->next;
        }

     //   cout<<prev->data<<" ";
    }

    while(head1)
    {
        prev->next = head1;
        prev=head1;
        head1 = head1->next;
       //  cout<<prev->data<<" ";
    }

    while(head2)
    {
        prev->next=head2;
        prev=head2;
        head2=head2->next;
        // cout<<prev->data<<" ";
    }

    prev->next=NULL;

 return unchange_Pointer;
}
