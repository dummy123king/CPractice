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
    while (temp != NULL)
    {
        printf("%d<->", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void printListReverse()
{
    Node *temp = tail;
    if (temp == NULL)
    {
        printf("List is empty\n");
        return;
    }
    while (temp != NULL)
    {
        printf("%d <->", temp->data);
        temp = temp->prev;
    }
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
        head = tail = newNode;
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

        if (mid->next != NULL) {
            mid->next->prev = newNode;
        }
       
        mid->next = newNode;
       
        if (newNode->next == NULL )
        {
            tail = newNode;
        }
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

void deleteAtMiddle(void)
{
    Node *slow = head, *fast = head;
    
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    

    if (head->next == NULL)
    {
        free(head);
        head = tail = NULL;
        return;
    }
    

    while (fast && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    slow->prev->next = slow->next;

    if(slow->next != NULL)
    {
        slow->next->prev = slow->prev;
    }


    if (slow->next == NULL)
    {
        tail = slow->prev;
    }
    
    free(slow);
}

void reverseList(void)
{
    Node *temp = NULL, *curr = head;

    while (curr != NULL)
    {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev; 
    }

    if (temp != NULL)
    {
        head = temp->prev;
        tail = temp;
    }    
}

int main()
{
    addAtLast(5);
    addAtLast(1);
    addAtLast(6);
    addAtLast(55);
    addAtLast(77);
    addAtLast(88);
    addAtLast(99);
    printList();
    reverseList();
    printList();

    return 0;
}  