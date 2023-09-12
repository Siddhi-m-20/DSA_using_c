/*Accept the number of rows (m) and columns (n) for a matrix and dynamically allocate
memory for the matrix. Accept and display the matrix using pointers. (Hint: Use an array
of pointers.)*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int m, n;
    int **matrix;
    int i, j;

    printf("Enter the number of rows: ");
    scanf("%d", &m);

    printf("Enter the number of columns: ");
    scanf("%d", &n);

    matrix = (int **)malloc(m * sizeof(int *));
    for (i = 0; i < m; i++)
    {
        matrix[i] = (int *)malloc(n * sizeof(int));
    }

    printf("Enter the matrix elements:\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", *(matrix + i) + j);
        }
    }

    printf("The matrix is:\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", *(*(matrix + i) + j));
        }
        printf("\n");
    }

    for (i = 0; i < m; i++)
    {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
