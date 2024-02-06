#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <pthread.h>
#include <stdint.h>
#include <semaphore.h>

void MatrixMultiplication()
{
    printf("Matrix multiplication\n");

    int matrix1R = 4;
    int matrix1C = 4;
    int matrix2R = 4;
    int matrix2C = 4;

    int Matrix1[matrix1R][matrix1C];
    int Matrix2[matrix2R][matrix2C];
    int ResultantMatrix[matrix1C][matrix2R];

    if (matrix1C != matrix2R)
    {
        printf("\nMatrix mutliplication not possible\nMatrix_1 Columns should be equal to Matrix_2 rows\n");
    }

    int value = 1;
    for (int i = 0; i < matrix1R; i++)
    {
        for (int j = 0; j < matrix1C; j++)
        {
            Matrix1[i][j] = value++;  
        }
    }
    
    value = 1;
    for (int i = 0; i < matrix2R; i++)
    {
        for (int j = 0; j < matrix2C; j++)
        {
            Matrix2[i][j] = value++;  
        }
    }

    printf("Matrix_1\n");
    for (int i = 0; i < matrix1R; i++)
    {
        for (int j = 0; j < matrix1C; j++)
        {
            printf("%8d", Matrix1[i][j]);
        }
        printf("\n");
    }

    printf("Matrix_2\n");
    for (int i = 0; i < matrix2R; i++)
    {
        for (int j = 0; j < matrix2C; j++)
        {
            printf("%8d", Matrix2[i][j]);
        }
        printf("\n");
    }

    int sum = 0;
    for (int i = 0; i < matrix1R; i++)
    {
        for (int j = 0; j < matrix2C; j++)
        {
            sum = 0;
            for(int k = 0; k < matrix1C; k++)
            {
                sum = sum + Matrix1[i][k]*Matrix2[k][j];
                ResultantMatrix[i][j] = sum;
            }
        }
    }

    printf("Resultant Matrix\n");
    for (int i = 0; i < matrix1C; i++)
    {
        for (int j = 0; j < matrix2R; j++)
        {
            printf("%8d", ResultantMatrix[i][j]);
        }
        printf("\n");
    }

}

void transposeOfMatrix()
{
    printf("Transpose of Matrix\n");

    int rows = 3;
    int cols = 3;

    int matrix[rows][cols];
    int ResultantMatrix[rows][cols];

    int value = 1;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = value++;  
        }
    }

    printf("Orignal Matrix\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%8d", matrix[i][j]);
        }
        printf("\n");
    }
    
    for (int  i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            ResultantMatrix[i][j] = matrix[j][i];
        }
    }
    printf("After Transpose\n");
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            printf("%8d", ResultantMatrix[i][j]);
        }
        printf("\n");
    }
}


int main(int argc, char **argv)
{ 
    MatrixMultiplication();  
    transposeOfMatrix();
    return 0;
}