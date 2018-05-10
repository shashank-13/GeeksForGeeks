
double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if((int)A.size()<=(int)B.size())
    {
        int x=(int)A.size();
        int y=(int)B.size();
        int low=0;
        int high=x;

        while(low<=high)
        {
            int partitionX=(low+high)/2;
            int partitionY=(x+y+1)/2-partitionX;

            int maxLeftX = (partitionX==0) ? INT_MIN:A[partitionX-1];
            int minRightX=(partitionX==x)?INT_MAX:A[partitionX];

            int maxLeftY = (partitionY==0) ? INT_MIN:B[partitionY-1];
            int minRightY=(partitionY==y)?INT_MAX:B[partitionY];

            if(maxLeftX<=minRightY && maxLeftY<=minRightX)
            {
                if((x+y)%2==0)
                {
                    double answer = (max(maxLeftX,maxLeftY)+min(minRightX,minRightY))/2.0;
                    return answer;
                }
                else
                {
                    double answer = max(maxLeftX,maxLeftY)*1.0;
                    return answer;
                }
            }
            else if(maxLeftX > minRightY)
                high=partitionX-1;
            else
                low=partitionX+1;
        }
    }
    else
    {
        int x=(int)B.size();
        int y=(int)A.size();
        int low=0;
        int high=x;

        while(low<=high)
        {
            int partitionX=(low+high)/2;
            int partitionY=(x+y+1)/2-partitionX;

            int maxLeftX = (partitionX==0) ? INT_MIN:B[partitionX-1];
            int minRightX=(partitionX==x)?INT_MAX:B[partitionX];

            int maxLeftY = (partitionY==0) ? INT_MIN:A[partitionY-1];
            int minRightY=(partitionY==y)?INT_MAX:A[partitionY];

            if(maxLeftX<=minRightY && maxLeftY<=minRightX)
            {
                if((x+y)%2==0)
                {
                    double answer = (max(maxLeftX,maxLeftY)+min(minRightX,minRightY))/2.0;
                    return answer;
                }
                else
                {
                    double answer = max(maxLeftX,maxLeftY)*1.0;
                    return answer;
                }
            }
            else if(maxLeftX > minRightY)
                high=partitionX-1;
            else
                low=partitionX+1;
        }
    }
}
