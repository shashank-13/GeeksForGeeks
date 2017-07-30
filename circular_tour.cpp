/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*
The structure of petrolPump is
struct petrolPump
{
    int petrol;
    int distance;
};*/
/*You are required to complete this method*/
int tour(petrolPump p[],int n)
{
   //Your code here


   int current_index,start_index;
   current_index=start_index=0;

   while(true)
   {

       int total_petrol =0;
       int total_dist =0;
       bool flag = false;
       int next_target = start_index;
       while(next_target!=current_index || !flag)
       {
           flag=true;
            total_petrol+=p[current_index].petrol;
            total_dist+=p[current_index].distance;
            if(total_petrol < total_dist )
            {
                current_index=n;
                break;
            }

            current_index=(current_index+1)%n;
       }
       if(current_index == next_target)
       break;
       else if(start_index ==n-1 && current_index ==n)
       {
           start_index = -1;
           break;
       }
       else
       {
           start_index ++;
           current_index =start_index;

       }
   }



  return start_index;
}

