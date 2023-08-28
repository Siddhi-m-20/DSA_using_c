/*Sort a random array of n integers (accept the value of n from user) in ascending order by
using bubble sort algorithm
*/
#include<stdlib.h>
#include<stdio.h>
    void bubbleSort(int arr[], int n);

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Elements of the array:\n");
    for (int i = 0; i < n; i++) {
        arr[i]=rand()%100;
 printf("%d ", arr[i]);
    }

    bubbleSort(arr, n);

    printf("\nThe sorted array is:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

void bubbleSort(int arr[], int n) {
    int temp;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}