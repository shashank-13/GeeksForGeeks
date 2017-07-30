/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*The structure of linked list is the following
struct node
{
int data;
Node* next;
};*/
int detectloop(Node *list)
{
   // your code here
   Node *slow_Pointer,*fast_Pointer;

   slow_Pointer=fast_Pointer = list ;

   while(fast_Pointer && slow_Pointer && fast_Pointer->next)
   {
       cout<<fast_Pointer->next<<" "<<slow_Pointer->next<<endl;
        fast_Pointer = fast_Pointer->next->next;

        slow_Pointer=slow_Pointer->next;

        if(fast_Pointer!=NULL && fast_Pointer == slow_Pointer)
         return 1;
   }
   return 0;
}
