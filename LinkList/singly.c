#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct SingleLinkList
{
  int data;
  struct SingleLinkList *next;
} Node;

Node *head = NULL;

void printLinkList(void)
{
  Node *temp = head;

  if (temp == NULL)
  {
    printf("List is empty\n");
    return;
  }
  while (temp != NULL)
  {
    printf("%d->", temp->data);
    temp = temp->next;
  }
  printf("NULL\n\n");
}

void addAtFirst(int data)
{
  Node *newNode = malloc(sizeof(Node));

  if (newNode == NULL)
  {
    printf("No memory to allocate \n");
    return;
  }
  newNode->data = data;
  newNode->next = NULL;

  if (head == NULL)
  {
    head = newNode;
  }
  else
  {
    newNode->next = head;
    head = newNode;
  }
}

void addAtLast(int data)
{
  Node *newNode = malloc(sizeof(Node));

  if (newNode == NULL)
  {
    printf("No memory to allocate \n");
    return;
  }
  newNode->data = data;
  newNode->next = NULL;

  if (head == NULL)
  {
    head = newNode;
  }
  else
  {
    Node *temp = head;
    while (temp->next != NULL)
    {
      temp = temp->next;
    }
    temp->next = newNode;
  }
}

void deleteAtFirst(void)
{
  if (head == NULL)
  {
    printf("List is empty\n");
    return;
  }
  else
  {
    Node *temp = head;

    if (temp->next == NULL)
    {
      free(temp);
      temp = NULL;
      head = NULL;
    }
    else
    {
      head = head->next;
      free(temp);
      temp = NULL;
    }
  }
}

void deleteAtLast(void)
{
  Node *temp = head, *prev;

  if (head == NULL)
  {
    printf("List is empty\n");
    return;
  }
  else
  {
    if (temp->next == NULL)
    {
      free(temp);
      temp = NULL;
      head = NULL;
    }
    else
    {
      while (temp && temp->next)
      {
        prev = temp;
        temp = temp->next;
      }
      prev->next = NULL;
      free(temp);
      temp = NULL;
    }
  }
}

void addAtMiddle(int data)
{
  Node *newNode = malloc(sizeof(Node));

  if (newNode == NULL)
  {
    printf("No memory to allocate \n");
    return;
  }
  newNode->data = data;
  newNode->next = NULL;

  if (head == NULL)
  {
    head = newNode;
  }
  else
  {
    Node *midPtr = head, *lastPtr = head->next;

    while (lastPtr && lastPtr->next)
    {
      lastPtr = lastPtr->next->next;
      midPtr = midPtr->next;
    }
    newNode->next = midPtr->next;
    midPtr->next = newNode;
  }
}

void deleteAtMiddle_1(void)
{
  if (head == NULL)
  {
    printf("List is empty\n");
    return;
  }
  if (head->next == NULL)
  {
    free(head);
    head = NULL;
    return;
  }
  else
  {
    Node *lastPtr = head->next, *midPtr = head, *prev = NULL;

    while (lastPtr != NULL)
    {
      prev = midPtr;
      midPtr = midPtr->next;

      lastPtr = lastPtr->next;
      if (lastPtr != NULL)
      {
        lastPtr = lastPtr->next;
      }
    }
    prev->next = midPtr->next;
    free(midPtr);
  }
}

void reverseList(void)
{
  if (head == NULL && head->next == NULL)
  {
    return;
  }
  else
  {
    Node *prevNode = NULL, *currNode = head, *nextNode = NULL;
    while (currNode != NULL)
    {
      nextNode = currNode->next;
      currNode->next = prevNode;
      prevNode = currNode;
      currNode = nextNode;
    }
    head = prevNode;
  }
}

void reverseListRecursively(Node *ptr)
{
  if (ptr->next == NULL)
  {
    head = ptr;
    return;
  }
  reverseListRecursively(ptr->next);
  Node *temp = ptr->next;
  temp->next = ptr;
  ptr->next = NULL;
}

bool findLoopInList()
{

  addAtFirst(4);
  addAtFirst(5);
  addAtFirst(7);
  addAtFirst(8);
  addAtFirst(9);
  addAtFirst(55);
  addAtFirst(88);
  addAtFirst(35);
  addAtFirst(66);
  printLinkList();
  // head->next->next->next = head->next->next; // Uncomment to introduce loop in a list

  Node *slow = head, *fast = head;

  while (slow && fast && fast->next)
  {
    slow = slow->next;
    fast = fast->next->next;
    if (fast == slow)
    {
      printf("list has loop\n");
      return true;
    }
  }
  printf("No loop in list\n");
  return false;
}

int main()
{
  addAtFirst(1);
  addAtFirst(5);
  addAtFirst(4);
  addAtFirst(5);
  addAtFirst(2);
  addAtFirst(33);
  printLinkList();

  return 0;
}
