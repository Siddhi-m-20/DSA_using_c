/*Accept n integers in an array. Copy only the non-zero elements to another array (allocated
using dynamic memory allocation). Calculate the sum and average of non-zero elements*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, sum = 0, count = 0;
    ;
    int *arr, *copy;
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
            count++;
        }
    }

    copy = (int *)malloc(count * sizeof(int));
    if (copy == NULL)
    {
        printf("Memory allocation failed for copy\n");
        free(arr);
        return -1;
    }

    j = 0;
    for (i = 0; i < n; i++)
    {
        if (*(arr + i) != 0)
        {
            *(copy + j) = *(arr + i);
            j++;
        }
    }

    printf("The copy array is: ");
    for (i = 0; i < count; i++)
    {
        printf("%d ", *(copy + i));
    }
    printf("\n");

    for (i = 0; i < count; i++)
    {
        sum += *(copy + i);
    }

    avg = (double)sum / count;

    printf("The sum of non-zero elements is: %d\n", sum);
    printf("The average of non-zero elements is: %.2f\n", avg);

    free(arr);
    free(copy);

    return 0;
}
