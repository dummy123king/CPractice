#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct doubly
{
    int data;
    struct doubly *next, *prev;

} Node;

Node *head = NULL;

void print_list()
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void print_list_reverse()
{
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

void add_data_at_first(int data)
{
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL)
    {
        printf("Unable to allocate memory\n");
        return;
    }
    else
    {
        new_node->data = data;
        new_node->next = NULL;
        new_node->prev = NULL;
        if (head == NULL)
        {
            head = new_node;
        }
        else
        {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
    }
}

void add_data_at_last(int data)
{
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL)
    {
        printf("Unable to allocate memory\n");
        return;
    }
    else
    {
        new_node->data = data;
        new_node->next = NULL;
        new_node->prev = NULL;
        if (head == NULL)
        {
            head = new_node;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = new_node;
            new_node->prev = temp;
        }
    }
}

void add_data_at_middle(int data)
{
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL)
    {
        printf("Unable to allocate memory\n");
        return;
    }
    else
    {
        new_node->data = data;
        new_node->next = NULL;
        new_node->prev = NULL;
        if (head == NULL)
        {
            head = new_node;
        }
        else if (head->next = NULL)
        {
            head->next = new_node;
            new_node->prev = head;
        }
        else
        {
            Node *mid = head, *last = head->next;

            while (last != NULL && last->next != NULL)
            {
                mid = mid->next;
                last = last->next->next;
            }
            new_node->prev = mid;
            new_node->next = mid->next;
            mid->next = new_node;
        }
    }
}

int main()
{
    uint32_t data = 0xaabbccdd;
    uint32_t data1 = 0xAABBCCDD;
    char str[] = "made07aaes";

    if (data1 == data)
        printf("Equal\n");

    printf("%x\n", data);
    printf("%X\n", data);
    return 0;
}