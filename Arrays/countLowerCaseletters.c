#include <stdio.h>       // Include standard input/output library
#include <stdlib.h>      // Include standard library
#include <string.h>      // Include string manipulation functions
#include <unistd.h>      // Include POSIX operating system API
#include <ctype.h>       // Include character classification functions
#include <pthread.h>     // Include POSIX thread library
#include <stdint.h>      // Include standard integer types
#include <semaphore.h>   // Include semaphore synchronization primitive

// Function to count the number of lowercase letters in a string
int countLowerCaseLetters(char *ptr)
{
    int count;             // Variable to store the count of lowercase letters
    int len = strlen(ptr); // Calculate the length of the input string

    // Loop through each character in the string
    for (int i = 0; i < len; i++)
    {
        // Check if the character is lowercase
        if (islower(ptr[i]))
        {
            count++;  // Increment the count if the character is lowercase
        }
    }
    return count;  // Return the total count of lowercase letters
}

// Entry point of the program
int main(int argc, char **argv)
{
    int count = 0;                      // Variable to store the count of lowercase letters
    char arr[] = "Count Lower Case Letters";  // Input string
    printf("String = %s\n", arr);       // Print the input string

    // Call the function to count the number of lowercase letters
    count = countLowerCaseLetters(arr);
    printf("Lower case letter count : %d\n", count);  // Print the count of lowercase letters
    
    return 0;  // Exit the program
}
