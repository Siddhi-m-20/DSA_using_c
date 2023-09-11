/*Write a program to allocate
 memory dynamically for n integers such
 that the memory is
initialized to 0.
 Accept the data from the user and
 find the range of the data elements.*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, max, min, r;
    printf("Enter value of n: \n");
    scanf("%d", &n);
    int *ptr = (int *)calloc(n, sizeof(int));
    printf("Enter Integers:\n ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", ptr + i);
    }
    max = *ptr;
    min = *ptr;
    for (i = 0; i < n; i++)
    {
        if (*(ptr + i) > max)
        {
            max = *(ptr + i);
        }

        if (*(ptr + i) < min)
        {
            min = *(ptr + i);
        }
    }
    r = max - min;
    printf("Maximum %d\nMinimum %d\n", max, min);
    printf("Range of the data elements is %d", r);
    free(ptr);
    return 0;
}