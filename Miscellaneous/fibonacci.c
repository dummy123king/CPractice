#include <stdio.h>

void fibonacciWithIteration(int number)
{
    int n1 = 0, n2 = 1, fib = 0;

    printf("%d, %d, ", n1, n2);

    for (int i = 2; i < number; i++)
    {
        fib = n1 + n2;
        n1 = n2;
        n2 = fib;
        printf("%d, ", fib);
    }
    printf("\n\n");
}

int fibonacciWithRecursion(int number)
{
    if (number == 0)
    {
        return 0;
    }
    if (number == 1)
    {
        return 1;
    }    
    return (fibonacciWithRecursion(number - 1) + fibonacciWithRecursion(number - 2));
}

int main(int argc, char **argv)
{
    fibonacciWithIteration(10);
    for (size_t i = 0; i < 10; i++)
    {
        printf("%d, ", fibonacciWithRecursion(i));
    }
    printf("\n\n");
    return 0;
}