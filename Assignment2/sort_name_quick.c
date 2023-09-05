/*Consider a file “employee.txt” file containing at least 10 records of (Name, MobileNo,
Age, Salary). Read the data from the file “employee.txt” and sort on names in
alphabetical order (use strcmp) using Merge / Quick sort and write the sorted data to
another file 'sortedemp.txt'.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    char name[50];
    char mob_no[10];
    int age;
    float salary;
};

void swap(struct Employee *a, struct Employee *b) {
    struct Employee temp;
    temp = (*a);
    (*a) = (*b);
    (*b) = temp;
}

int partition(struct Employee *arr, int low, int high) {
    char pivot[50];
    strcpy(pivot, arr[low].name);
    int i = high, j;
    for (j = high; j >= low + 1; j--) {
        if (strcmp(arr[j].name, pivot) > 0) {
            swap(&arr[i], &arr[j]);
            i--;
        }
    }
    swap(&arr[low], &arr[i]);
    return i;
}

void quicksort(struct Employee arr[], int low, int high) {
    if (low < high) {
        int p;
        p = partition(arr, low, high);
        quicksort(arr, low, p - 1);
        quicksort(arr, p + 1, high);
    }
}

int main() {
    FILE *fp1, *fp2;
    struct Employee employees[100];
    int n = 10, i;
    fp1 = fopen("employee.txt", "r");
    if (fp1 == NULL) {
        printf("Error opening employee.txt");
        return 1;
    }

    for (i = 0; i < n; i++) {
        fscanf(fp1, "%s %s %d %f", employees[i].name, employees[i].mob_no, &employees[i].age, &employees[i].salary);
    }

    fclose(fp1);

    quicksort(employees, 0, 9);

    fp2 = fopen("sortedemp.txt", "w");
    if (fp2 == NULL) {
        printf("Error opening sortedemp.txt");
        return 1;
    }

    for (i = 0; i < n; i++) {
        fprintf(fp2, "%s %s %d %.2f\n", employees[i].name, employees[i].mob_no, employees[i].age, employees[i].salary);
    }

    fclose(fp2);

    printf("Employee data sorted and written to sortedemp.txt\n");

    return 0;
}
