#include <stdio.h>
#include <stdlib.h>


int main()
{
    // int arr[3][3] = {
    //                     {1, 2, 3},
    //                     {4, 5, 6},
    //                     {7, 8, 9}
    //                 };
    
    int **arr; //Declaration
    int rows = 5;
    int cols = 5;
    int number = 1;

    arr = malloc(sizeof(int *) * rows); // allocate the memory for array of pointers


    //Allocate the memory for onedimensional array
    for (int i = 0; i < rows; i++)
    {
        *(arr + i) = malloc(sizeof(int) * cols);
    }

    // Add data to memory
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            *( *(arr + i) + j) = number++;    
        }
    }
    

    // Print the data 
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d, ", *( *(arr + i) + j));
        }
        printf("\n");
    }

    //Free the allocated memory of one dimensional array
    for (int i = 0; i < rows; i++)
    {
        free(*( arr + i ));
    }

    //Free the allocated memory of array of pointers
    free(arr);    

    return 0;
}