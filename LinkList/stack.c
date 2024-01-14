#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stack
{
    int data;
    struct stack *next;
}Stack;

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

void push(int data)
{
    Stack *Node = malloc(sizeof(Stack));
    if (Node == NULL)
    {
        printf("No memory left to allocate\n");
        return;
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
}

int pop(void)
{
    int data ;
    Stack *temp = root;
    if(!isEmpty())
    {
        data = temp->data;
        root = root->next;
        free(temp);
        return data;
    }
    else
    {
        printf("Stack is empty\n");
    }
}

int main()
{
    int data = 0;
    push(5);
    push(4);
    push(3);
    push(2);
    push(1);
    printStack();
    
    data = pop();
    printf("%d\n", data);
    printStack();

    data = pop();
    printf("%d\n", data);
    printStack();
    
    return 0;
}
