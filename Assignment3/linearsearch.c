/*Create a random array of n integers. Accept a value x from user and use linear search
algorithm to check whether the number is present in the array or not and output the position
if the number is present*/

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

int linearSearch(int arr[], int n, int key);

int main() {
    int n, key, position;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    accept(arr,n);
    display(arr,n);
    printf("Enter the key to be searched: ");
    scanf("%d", &key);

    position = linearSearch(arr, n, key);

    if (position == -1) {
        printf("The key was not found in the array.\n");
    } else {
        printf("The key was found at position %d in the array.\n", position+1);
    }

    return 0;
}

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}
