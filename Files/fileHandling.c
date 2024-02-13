#include <stdio.h>
#include <errno.h>


int main()
{
    FILE *fp = fopen("text.log", "r");
    if (fp == NULL)
    {
        perror("Error");
    }
    
    fprintf(fp, "Hello\n");
    return 0;
}