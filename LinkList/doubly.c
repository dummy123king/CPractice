#include <stdio.h>
#include <stdlib.h>

typedef struct DoublyLinklist
{
    struct DoublyLinklist *prev;
    int data;
    struct DoublyLinklist *next;
}Node;

Node *head = NULL;
Node *tail = NULL;

void printList(void)
{
    Node *temp = head;
    if (temp == NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("NULL->");
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void printListReverse()
{
    
    Node *temp = tail;
    if (temp == NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("NULL->");
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

void addAtFirst(int data)
{
    Node *newNode = malloc(sizeof(Node));

    if (newNode == NULL)
    {
        printf("Unable to allocate memory\n");
        return;
    }
    
    newNode->prev = NULL;
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL && tail == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void addAtLast(int data)
{
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Unable to allocate memory\n");
        return;
    }
    
    newNode->prev = NULL;
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL && tail == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    else
    {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

void addAtMiddle(int data)
{
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Unable to allocate memory");
        return;
    }
    
    newNode->prev = NULL;
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL && tail == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    if (head->next == NULL)
    {
        newNode->prev = head;
        head->next = newNode;
        tail = newNode;
        return;
    }
    else
    {
        Node *mid = head, *fast = head->next;

        while (fast && fast->next)
        {
            mid = mid->next;
            fast = fast->next->next;
        }
        newNode->prev = mid;
        newNode->next = mid->next;
        mid->next = newNode;
        
        
    }
}

void deleteAtFirst(void)
{
    Node* temp = head; 

    if (temp == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if (temp->next == NULL)
    {
        free(temp);
        head = NULL;
        tail = NULL;
        return;
    }
    
    head = head->next;
    head->prev = NULL;
    free(temp);
}

void deleteAtLast(void)
{
    Node *temp = tail;
    if (temp == NULL && head == NULL)
    {
        printf("List is empty");
        return;   
    }
    if (temp->prev == NULL)
    {
        free(temp);
        tail = NULL;
        head = NULL;
        return;
    }
    tail->prev->next = NULL;
    tail = tail->prev;
    free(temp);    
}


int main()
{
    addAtMiddle(5);
    printList();
    printListReverse();

    addAtMiddle(1);
    printList();
    printListReverse();

    addAtMiddle(6);
    printList();
    printListReverse();

    // addAtMiddle(55);
    // printList();

    // addAtMiddle(88);
    // printList();

    // addAtMiddle(877);
    // printList();

    // addAtMiddle(897);
    // printList();

    // addAtMiddle(8988);
    // printList();

    // addAtMiddle(800);
    // printList();
    // printListReverse();

    return 0;
}