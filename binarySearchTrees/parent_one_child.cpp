#include <stdio.h>
 
int hasOnlyOneChild(int pre[], int size)
{
    // Initialize min and max using last two elements
    int min, max;
    if (pre[size-1] > pre[size-2])
    {
        max = pre[size-1];
        min = pre[size-2];
    }
    else
    {
        max = pre[size-2];
        min = pre[size-1];
    }
 
 
    // Every element must be either smaller than min or
    // greater than max
    for (int i=size-3; i>=0; i--)
    {
        if (pre[i] < min)
            min = pre[i];
        else if (pre[i] > max)
            max = pre[i];
        else
            return false;
    }
    return true;
}
 
// driver program to test above function
int main()
{
//    int pre[] = {8, 3, 5, 7, 6};
    int pre[] = {20, 10, 11, 13, 12};
    int size = sizeof(pre)/sizeof(pre[0]);
    if (hasOnlyOneChild(pre, size) == true )
        printf("Yes");
    else
        printf("No");
    return 0;
}
