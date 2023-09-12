/*Accept n integers in an array. Copy only the non-zero elements to another array (allocated
using dynamic memory allocation). Calculate the sum and average of non-zero elements*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, sum = 0, count = 0;
    int *arr;
    double avg;
    printf("Enter size of array: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {

        printf("Memory allocation failed for arr\n");
        return -1;
    }

    printf("Enter %d elements in array: \n", n);
    for (i = 0; i < n; i++)
    {
        // scanf("%d", arr+i);
        *(arr + i) = rand() % 100;
    }
    for (i = 0; i < n; i++)
    {
        printf("%d ", *(arr + i));
    }
    printf("\n");

    for (i = 0; i < n; i++)
    {
        if (*(arr + i) != 0)
        {
            *(arr+count)=*(arr+i);
            count++;
        }
    }

    arr= (int *)realloc(arr,count * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed for copy\n");
        return -1;
    }


    printf("The array is: ");
    for (i = 0; i < count; i++)
    {
        printf("%d ", *(arr + i));
    }
    printf("\n");

    for (i = 0; i < count; i++)
    {
        sum += *(arr + i);
    }

    avg = (double)sum / count;

    printf("The sum of non-zero elements is: %d\n", sum);
    printf("The average of non-zero elements is: %.2f\n", avg);

    free(arr);

    return 0;
}
