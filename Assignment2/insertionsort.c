/* Sort a random array of n integers (accept the value of n from user) in ascending order by
using insertion sort algorithm*/

#include <stdlib.h>
#include <stdio.h>

void printArray(int *A, int n)
{
    printf("\nThe sorted array using inserrtion sort is:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void insertionSort(int *A, int n)
{
    int key, j, i;
    for (i = 1; i < n; i++)
    {
        key = A[i];
        for (j = i - 1; j >= 0 && A[j] > key; j--)
        {
            A[j + 1] = A[j];
        }
        A[j + 1] = key;
    }
}
int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Elements of the array:\n");
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }

    insertionSort(arr, n);
    printArray(arr, n);
    return 0;
}