//Exercise 2 
//Set B
//Q.1
#include <stdio.h>

#define MAX_SIZE 100

void acceptMatrix(int matrix[][MAX_SIZE], int rows, int cols);
void displayMatrix(int matrix[][MAX_SIZE], int rows, int cols);
void multiplyMatrix(int mat1[][MAX_SIZE], int mat2[][MAX_SIZE], int res[][MAX_SIZE], int rows1, int cols1, int rows2, int cols2);

int main() 
{
    int mat1[MAX_SIZE][MAX_SIZE], mat2[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int rows1, cols1, rows2, cols2;

    printf("Enter dimensions of matrix 1 (rows, cols): ");
    scanf("%d %d", &rows1, &cols1);

    printf("Enter elements of matrix 1:\n");
    acceptMatrix(mat1, rows1, cols1);

    printf("Enter dimensions of matrix 2 (rows, cols): ");
    scanf("%d %d", &rows2, &cols2);

    if (cols1 != rows2) 
    {
        printf("Error: The number of columns in matrix 1 must be equal to the number of rows in matrix 2.\n");
        return 1;
    }

    printf("Enter elements of matrix 2:\n");
    acceptMatrix(mat2, rows2, cols2);

    multiplyMatrix(mat1, mat2, result, rows1, cols1, rows2, cols2);

    printf("Resultant matrix:\n");
    displayMatrix(result, rows1, cols2);

    return 0;
}

void acceptMatrix(int matrix[][MAX_SIZE], int rows, int cols) 
{
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void displayMatrix(int matrix[][MAX_SIZE], int rows, int cols) 
{
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void multiplyMatrix(int mat1[][MAX_SIZE], int mat2[][MAX_SIZE], int res[][MAX_SIZE], int rows1, int cols1, int rows2, int cols2) 
{
    for (int i = 0; i < rows1; i++) 
    {
        for (int j = 0; j < cols2; j++) 
        {
            res[i][j] = 0;
            for (int k = 0; k < cols1; k++) 
            {
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}
