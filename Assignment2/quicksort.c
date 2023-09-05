/*Sort a random array of n integers (accept the value of n from user) in ascending order by
using recursive Quicksort algorithm.*/

#include <stdio.h>
#include <stdlib.h>

void accept(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
}

void display(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}

void swap(int *a, int *b) {
    int temp;
    temp = (*a);
    (*a) = (*b);
    (*b) = temp;
}

int partition(int *arr, int low, int high) {
    int pivot = arr[low];
    int i = high, j;
    for (j = high; j >= low + 1; j--) {
        if (arr[j] > pivot) {
            swap(&arr[i], &arr[j]);
            i--;
        }
    }
    swap(&arr[low], &arr[i]);
    return i;
}

void quicksort(int *arr, int low, int high) {
    if (low < high) {
        int p;
        p = partition(arr, low, high);
        quicksort(arr, low, p - 1);
        quicksort(arr, p + 1, high);
    }
}

int main() {
    int arr[100], n;
    printf("Enter size of an array: \n");
    scanf("%d", &n);
    accept(arr, n);
    printf("Entered Array:\n");
    display(arr, n);
    quicksort(arr, 0, n - 1);
    printf("Sorted array: \n");
    display(arr, n);
}