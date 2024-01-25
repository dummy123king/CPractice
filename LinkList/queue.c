#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct queue
{
    int data;
    struct queue *next;
} Queue;

Queue *head = NULL;
Queue *tail = NULL;

bool isEmpty(void)
{
    if (head == NULL)
    {
        return true;
    }
    return false;
}

bool printQueue(void)
{
    if (isEmpty() == true)
    {
        printf("List is empty\n");
        return false;
    }
    Queue *temp = head;

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    return true;
}

bool enqueue(int data)
{
    Queue *newNode = malloc(sizeof(Queue));
    if (newNode == NULL)
    {
        printf("List is full/Unable to allocate memory\n");
        return false;
    }
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
    return true;
}

bool dequeue(int *data)
{
    if (isEmpty() == true)
    {
        return false;
    }
    else
    {
        Queue *temp = head;
        *data = temp->data; 
        head = head->next;
        free(temp);
    }
    return true;
}

bool deleteQueue(void)
{
    if(isEmpty() == true)
    {
        printf("List is empty\n");
        return false;
    }
    Queue *temp = NULL;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    return true;
}

bool peek(int *data)
{
    if (isEmpty() == true)
    {
        return false;
    }
    *data = head->data;    
}

int main()
{
    int data = 0;

    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    printQueue();

    for (size_t i = 0; i < 2; i++)
    {
        dequeue(&data);
        printf("--------------------------->>>Data: %d\n", data);
        printQueue();
    }
    
    // enqueue(5);
    // enqueue(6);
    // enqueue(7);
    // enqueue(9);
    // printQueue();

    // peek(&data);
    // printf("Peek = %d\n", data);


    return 0;
}