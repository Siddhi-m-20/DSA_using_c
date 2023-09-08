/*
Create a random array of n integers. Sort the array using bubble sort. Accept a value x
from user and use binary search algorithm to check whether the number is present in array
or not and output the position if the number is present.

*/
#include<stdlib.h>
#include<stdio.h>

void accept (int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        arr[i] = rand () % 100;
    }
}

void display (int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf ("%d ", arr[i]);
    }
    printf ("\n");
}

void bubblesort (int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {

        for (j = 0; j<n-i-1; j++) {
            if (arr[j] > arr[j+1]) {

                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int binarysearch (int arr[], int low, int high, int key) {
    int mid;
    while (low <= high) {
        mid= (low + high) / 2;
        if (arr[mid] == key) {
            return mid;
        }
        
        else if (key < arr[mid]) {
            high =mid-1;
        }
        else
        {
            low = mid + 1;
        }
        
       
    }
     return -1;
}


int

main () {

    int n, key, position;
    printf ("Enter size of an array:\n");
    scanf("%d", &n);

    int arr[n];
    accept (arr, n);
    printf ("\nEntered Array: \n");

    display (arr, n);
    bubblesort(arr,n);
    display(arr,n);

    printf ("Enter the key to be searched: ");
    scanf("%d", &key);
    position = binarysearch (arr, 0, n -1, key);




    if (position == -1)

    {

        printf ("The key was not found in the array.\n");

    }

    else {

        printf ("The key was found at position %d in the array.\n", position+1);

    }

    return 0;
}
