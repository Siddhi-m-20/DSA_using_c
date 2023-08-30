/*Sort a random array of n integers (accept the value of n from user) in ascending order by
using a recursive Merge sort algorithm.*/

#include <stdlib.h>
#include <stdio.h>

void printArray(int *A, int n)
{
  printf("\nThe sorted array using Merge sort is:\n");
  for (int i = 0; i < n; i++)
  {
    printf("%d ", A[i]);
  }
  printf("\n");
}

void merge(int arr[], int lb, int mid, int ub)
{
  int i, j, k, b[100];
  i = lb;
  j = mid + 1;
  k = lb;

  while (i <= mid && j <= ub)
  {
    if (arr[i] <= arr[j])
    {
      b[k] = arr[i];
      i++;
      k++;
    }
    else
    {
      b[k] = arr[j];
      j++;
      k++;
    }
  }
  while (i <= mid)
  {
    b[k] = arr[i];
    i++;
    k++;
  }
  while (j <= ub)
  {
    b[k] = arr[j];
    j++;
    k++;
  }

  for (int k = lb; k <= ub; k++)
  {
   arr[k]=b[k];
  }
  
}

void mergesort(int arr[], int lb, int ub)
{
  int mid;
  if(lb<ub){
  mid = (lb + ub) / 2;
  mergesort(arr, lb, mid);
  mergesort(arr, mid + 1, ub);
  merge(arr, lb, mid, ub);
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
  mergesort(arr, 0, n - 1);

  printArray(arr, n);
  return 0;
}