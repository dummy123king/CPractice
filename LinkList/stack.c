#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stack
{
    int data;
    struct stack *next;
} Stack;

Stack *root = NULL;

bool isEmpty(void)
{
    if (root == NULL)
    {
        return true;
    }
    return false;
}

void printStack(void)
{
    Stack *temp = root;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

bool push(int data)
{
    Stack *Node = malloc(sizeof(Stack));
    if (Node == NULL)
    {
        printf("No memory left to allocate\n");
        return false;
    }
    Node->data = data;
    Node->next = NULL;

    if (isEmpty() == true)
    {
        root = Node;
    }
    else
    {
        Node->next = root;
        root = Node;
    }
    return true;
}

bool pop(int *data)
{
    Stack *temp = root;
    if (!isEmpty())
    {
        *data = temp->data;
        root = root->next;
        free(temp);
        return data;
    }
    else
    {
        return false;
    }
}

bool peek(int *data)
{
    if (root == NULL)
    {
        printf("List is empty\n");
        return false;
    }
    else
    {
        *data = root->data;
    }
    return true;
}

int main()
{
    int data = 0;

    if (isEmpty() == true)
        printf("List is empty...\n");
    else
        printf("List is Not empty...\n");

    push(5);
    push(4);
    push(3);
    push(2);
    push(1);
    printStack();
    printf("Peek------->>>: %d\n", data);
    pop(&data);
    printStack();
    peek(&data);
    printf("Peek------->>>: %d\n", data);
    if (isEmpty() == true)
        printf("List is empty...\n");
    else
        printf("List is Not empty...\n");

    return 0;
}
