#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <pthread.h>
#include <stdint.h>
#include <semaphore.h>


int factorialWithIteration(int number)
{
    int result = 1;

    for (int i = 1; i <= number; i++)
    {
        result = result * i;
    }
    return result;
}

int factorialWithRecursion(int number)
{
    if (number == 0)
    {
        return 1;
    }
    return (number * factorialWithRecursion(number - 1));
}

int main(int argc, char **argv)
{
    printf("------>%d\n\n", factorialWithIteration(5));
    printf("------>%d\n\n", factorialWithRecursion(5));

    return 0;
}