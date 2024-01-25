#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <pthread.h>
#include <stdint.h>
#include <semaphore.h>


void printArray(int *ptr, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d, ", ptr[i]);
    }
    printf("\n");
}

int findMaxValue(int *ptr, int len)
{
    int maxValue = ptr[0];
    for (int i = 1; i < len; i++)
    {
        if (ptr[i] > maxValue)
        {
            maxValue = ptr[i];
        }
    }
    return maxValue;
}



int main(int argc, char **argv)
{
    int maxValue = 0;
    int arr[10] = {1, 2, 5, 6, 7, 8, 9, 0, 88, -11};
    
    int len =  sizeof(arr)/sizeof(arr[0]);

    printArray(arr, len);
    maxValue = findMaxValue(arr, len);
    printf("Min value is : %d\n", maxValue);
    
    
    return 0;
}