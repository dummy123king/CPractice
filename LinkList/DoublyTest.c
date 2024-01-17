#include <stdio.h>
#include <stdlib.h>

typedef struct DoublyLinkedList {
    struct DoublyLinkedList *prev;
    int data;
    struct DoublyLinkedList *next;
} Node;

typedef struct {
    Node *head;
    Node *tail;
} LinkedList;

Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("Unable to allocate memory");
        exit(EXIT_FAILURE);
    }
    newNode->prev = NULL;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

LinkedList createLinkedList() {
    LinkedList list;
    list.head = NULL;
    list.tail = NULL;
    return list;
}

void printList(const LinkedList *list) {
    Node *temp = list->head;
    printf("NULL <- ");
    while (temp != NULL) {
        printf("%d <->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void printListReverse(const LinkedList *list) {
    Node *temp = list->tail;
    printf("NULL <- ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

void addAtFirst(LinkedList *list, int data) {
    Node *newNode = createNode(data);
    if (list->head == NULL && list->tail == NULL) {
        list->head = list->tail = newNode;
    } else {
        newNode->next = list->head;
        list->head->prev = newNode;
        list->head = newNode;
    }
}

void addAtLast(LinkedList *list, int data) {
    Node *newNode = createNode(data);
    if (list->head == NULL && list->tail == NULL) {
        list->head = list->tail = newNode;
    } else {
        newNode->prev = list->tail;
        list->tail->next = newNode;
        list->tail = newNode;
    }
}

void addAtMiddle(LinkedList *list, int data) {
    Node *newNode = createNode(data);
    
    if (list->head == NULL && list->tail == NULL) {
        list->head = list->tail = newNode;
        return;
    }
    Node *mid = list->head, *fast = list->head->next;

    while (fast != NULL && fast->next != NULL) {
        mid = mid->next;
        fast = fast->next->next;
    }

    newNode->prev = mid;
    newNode->next = mid->next;
    if (mid->next != NULL) {
        mid->next->prev = newNode;
    }
    mid->next = newNode;

    if (newNode->next == NULL) {
        list->tail = newNode;
    }
}


void deleteAtFirst(LinkedList *list) {
    Node *temp = list->head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    if (temp->next == NULL) {
        free(temp);
        list->head = list->tail = NULL;
        return;
    }
    list->head = list->head->next;
    list->head->prev = NULL;
    free(temp);
}

void deleteAtLast(LinkedList *list) {
    Node *temp = list->tail;
    if (temp == NULL && list->head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (temp->prev == NULL) {
        free(temp);
        list->tail = list->head = NULL;
        return;
    }
    list->tail->prev->next = NULL;
    list->tail = list->tail->prev;
    free(temp);
}

void freeMemory(LinkedList *list) {
    Node *temp = list->head;
    Node *nextNode;

    while (temp != NULL) {
        nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }
}

int main() {
    LinkedList list = createLinkedList();
    addAtMiddle(&list, 5);
    addAtMiddle(&list, 1);
    addAtMiddle(&list, 6);
    addAtMiddle(&list, 55);
    addAtMiddle(&list, 77);

    printList(&list);
    printListReverse(&list);

    freeMemory(&list);

    return 0;
}
