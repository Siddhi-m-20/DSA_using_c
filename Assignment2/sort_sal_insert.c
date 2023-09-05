/*
Read the data from the file “employee.txt” and sort on salary using bubble / insertion
sort. Write the sorted data to another file “newemp.txt”.
*/


#include <stdio.h>
#include <stdlib.h>

struct Employee {
    char name[50];
    int mob_no;
    int age;
    float salary;
};


void insertionSort(struct Employee arr[], int n) {
    int i, j;
    for (i = 1; i < n; i++) {
        struct Employee key = arr[i];
        for (j = i - 1; j >= 0 && arr[j].salary > key.salary; j--) {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = key;
    }
}


int main() {
    FILE *fp1, *fp2;
    struct Employee employees[100]; 
    int n=10,i;
    fp1 = fopen("employee.txt", "r");
    if (fp1== NULL) {
        printf("Error opening employee.txt");
        return 1;
    }

    for(i=0;i<n;i++){
    fscanf(fp1, "%s %d %d  %f", employees[i].name,&employees[i].mob_no,&employees[i].age,&employees[i].salary);
    }

    fclose(fp1);
    
    insertionSort(employees, n);

fp2 = fopen("newemp.txt", "w");
    if (fp2 == NULL) {
        printf("Error opening newemp.txt");
        return 1;
    }

    for (int i = 0; i < 10; i++) {
        fprintf(fp2, "%s %d %d %.2f\n", employees[i].name, employees[i].mob_no,employees[i].age,employees[i].salary);
    }


    fclose(fp2);

    printf("Employee data sorted and written to newemp.txt\n");

    return 0;
}
