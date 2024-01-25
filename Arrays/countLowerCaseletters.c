#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <pthread.h>
#include <stdint.h>
#include <semaphore.h>

int countLowerCaseLetters(char *ptr)
{
    int count;
    int len = strlen(ptr);
    for (int i = 0; i < len; i++)
    {
        if(islower(ptr[i]))
        {
            count++;
        }
    }
    return count;
}


int main(int argc, char **argv)
{
    int count = 0;
    char arr[] = "Count Lower Case Letters";
    printf("String = %s\n", arr);

    count = countLowerCaseLetters(arr);
    printf("Min value is : %d\n", count);
    
    return 0;
}