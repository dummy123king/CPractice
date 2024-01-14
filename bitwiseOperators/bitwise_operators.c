#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

void print_binary(int data)
{
    for (int i = 31; i >= 0 ; i--)
    {
        printf("%d ", (data >> i) & 1);
    }
    printf("\n");
}

int set_bit(int data, int pos)
{
    return (data | (1 << pos));
}

int clear_bit(int data, int pos)
{
    return (data & (~(1 << pos)));
}

int toggle_bit(int data, int pos)
{
    return (data ^ (1 << pos));
}

int test_bit(int data, int pos)
{
    return ((data >> pos) & 1);
}

int swap_two_bits(int data, int p1, int p2)
{
    int pos_1, pos_2; 
    int mask = 0;
    pos_1 = 1 & (data >> p1);
    pos_2 = 1 & (data >> p2);
    mask = ~((1 << p1) | (1 << p2));
    data = data & mask;
    data = data | (pos_2 << p1) | (pos_1 << p2);
    return data;
}

int swap_nibble(int data)
{
    return (((data & 0x0f) << 4) | ((data & 0xf0) >> 4));
}

int swap_byte(int data)
{
    return (((data & 0xff00) >> 8) | ((data & 0x00ff) << 8));
}

void swap_two_numbers_without_third_var(int *a, int *b)
{
    if(*a == *b) //Check if both the values are same
        return;

    *a ^= *b ^= *a ^= *b;

    // *a ^= *b;
    // *b ^= *a; 
    // *a ^= *b;
}

int reverse_bits(int data)
{
    int temp_data = 0;

    for (int i = 31; i >= 0; i--)
    {
        if((data >> i) & 1)
        {
            temp_data = temp_data | (1 << (31 - i));
        }
    }
    return temp_data;
}

int reverse_bits_1(int data)
{
    for (int i = 31, j = 0; i > j; i--, j++)
    {
        data =  swap_two_bits(data, i, j);
    }
    return data;
}

int reverse_bits_2(int data)
{
    data = ((data & 0xaaaaaaaa) >> 1) | ((data & 0x55555555) << 1);
    data = ((data & 0xcccccccc) >> 2) | ((data & 0x33333333) << 2);
    data = ((data & 0xf0f0f0f0) >> 4) | ((data & 0x0f0f0f0f) << 4);
    data = ((data & 0xff00ff00) >> 8) | ((data & 0x00ff00ff) << 8);
    data = (data >> 16) | (data << 16);

    return data;
}

int count_set_bits(int data)
{
    int no_of_set_bits = 0;
    for(int i = 0; i <= 31; i++)
    {
        if((data >> i) & 1)
            no_of_set_bits++;
    }
    return no_of_set_bits;
}

int count_set_bits_1(int data)
{
    int no_of_set_bits = 0;
    while (data)
    {
        print_binary(data);
        data = data & (data - 1);
        no_of_set_bits++;
    }
    return no_of_set_bits;
}

int check_sign(int data)
{
    if ((data >> 31))
    {
       return 1;
    }
    return 0;
}

int once_complement(int data)
{
    return (~(data));
}

int multiply_with_two(int data)
{
    return (data << 1);
}

int division_with_two(int data)
{
    return (data >> 1);
}

//Returns true for little endian
//Returns false for big endian
bool isLittleEndian_1(void)
{
    int data =  0x1;
    char lsb = (char) data;
    if (0x1 == lsb)
    {
        return true;
    }
    return false;
}

bool isLittleEndian_2(void)
{
    int data = 0x1;
    union checkEndian
    {
        int data;
        char check[4];
    };
    
    union checkEndian obj;
    obj.data = data;

    if (data == obj.check[0])
    {
        return true;
    }
    return false;   

}

bool isLittleEndian_3(void)
{
    int data =  0x1;
    char *lsb = (char *) &data;
    if (*lsb == 0x1)
    {
        return true;
    }
    return false;
}

int LittleEndianToBigEndianVisVersa(int data)
{
    data = ((data & 0xFF000000) >> 24) | ((data & 0x000000FF) << 24) | 
            ((data & 0x00FF0000) >> 8) | ((data & 0x0000FF00) << 8);

    return data;
}



//Entry
int main()
{
    int a = 0x66775599;

    printf("----->>%X\n", a);
    a = LittleEndianToBigEndianVisVersa(a);
    printf("----->>%X\n", a);
    
    return 0;
}