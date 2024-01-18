#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct Node
{
    int data;
    char *name;
}student_t;

typedef struct Emp 
{
    int data;
    struct Emp *next;
}Employee_t;

void add_at_first(Employee_t **head, int data)
{
    Employee_t *Node = malloc(sizeof(Employee_t));
    Node->data = data;
    Node->next = NULL;

    if (*head == NULL)
    {
        (*head) = Node;
    }
    else
    {
        Node->next = *head;
        (*head) = Node;
    }
}


void print_list(Employee_t *temp)
{
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    Employee_t *head = NULL;

    add_at_first(&head, 25);   
    add_at_first(&head, 1);
    add_at_first(&head, 3);
    add_at_first(&head, 5);
    print_list(head);
    return 0;
}