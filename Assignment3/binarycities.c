/*Read the data from file „cities.txt‟ containing names of 10 cities and their STD codes.
Accept a name of the city from user and use binary search algorithm to check whether the
name is present in the file and output the STD code, otherwise output “city not in the list”.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Cities
{
    char cityname[50];
    int stdcode;
};

void insertionSort(struct Cities *A, int n)
{
    struct Cities key;
    int j, i;
    for (i = 1; i < n; i++)
    {
        key = A[i];
        j = i - 1;

        while (j >= 0 && strcmp(A[j].cityname, key.cityname) > 0)
        {
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = key;
    }
}

int binarysearch(struct Cities arr[], int low, int high, char key[])
{
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (strcmp(arr[mid].cityname, key) == 0)
        {
            return arr[mid].stdcode;
        }
        else if (strcmp(key, arr[mid].cityname) < 0)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

int main()
{
    char name[50];
    int p;
    FILE *fp;
    struct Cities cities[100];
    int n = 10, i;
    fp = fopen("cities.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening cities.txt");
        return 1;
    }

    for (i = 0; i < n; i++)
    {
        fscanf(fp, "%s %d", cities[i].cityname, &cities[i].stdcode);
    }
    insertionSort(cities, n);
    printf("Enter a city name to search:\n");
    gets(name);
    p = binarysearch(cities, 0, 9, name);

    if (p == -1)
    {
        printf("The city was not found in the list.\n");
    }
    else
    {
        printf("%s %d", name, p);
    }

    fclose(fp);

    return 0;
}
