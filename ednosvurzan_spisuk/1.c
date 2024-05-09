#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

LinkedList init() {
  LinkedList newLinkedList = {
    .head = NULL,
    .size = 0,
  };

  return newLinkedList;
}


void printElement(char * a, int b, State c) {

  printf("The %d priority is with caption %s and state %d \n", b, a, c);
}

void printLinkedList(LinkedList * list) {
  printf("QUESTS: \n");
  forEach(list, printElement);
  printf("\n");
}

static struct ListNode * createNode(ListType value) {
  struct ListNode * newNode = (struct ListNode *)malloc(sizeof(struct ListNode *));
  if (newNode == NULL){
    printf("Error allocating memory \n");
    exit(1);
  }
  newNode->value = value;
  newNode->quest = (Quest *)malloc(sizeof(Quest *));
    if (newNode->quest == NULL){
    printf("Error allocating memory for quest! \n");
    exit(1);
  }
  newNode->quest->priority = value;
  return newNode;
}

void pushFront(LinkedList * list, ListType value) {
  struct ListNode * newNode = createNode(value);
  newNode->next = list->head;
  list->head = newNode;
  list->size++;
}

void push(LinkedList * list, uint index, ListType value) {
  if (index > list->size) {
    printf("Index out of bounds \n");
    exit(1);
  }
  
  if (index == 0) {
    pushFront(list, value);
  } else {
    printf("\n");
    printf("\n");
    struct ListNode * prevElement = getElement(list, index - 1);
        printf("\n");
    printf("\n");
    struct ListNode * newNode = createNode(value);
    
    newNode->next = prevElement->next;
    prevElement->next = newNode;
        printf("\n");
    printf("\n");
    list->size++;
    struct ListNode * currentNode = getElement(list, list->size - 1);
    for(int i = index;i < list->size - 1;i++)
    {printf("Waitttt");
      currentNode = currentNode->next;
      currentNode->quest->priority++;
      currentNode->value++;
    }
  }
}

void pushBack(LinkedList * list, ListType value) {
  push(list, list->size, value);
}

struct ListNode * getElement(LinkedList * list, uint index) {
  if (index >= list->size) {
    return NULL;
  }

  struct ListNode * currentNode = list->head;
  for (uint i = 0; i < index; i++) {
    currentNode = currentNode->next;
  }
  return currentNode;
}

void setElement(LinkedList * list, uint index, ListType value) {
  struct ListNode * node = getElement(list, index);
  node->value = value;
}

ListType popFront(LinkedList * list) {
  struct ListNode * nodeToDelete = list->head;
  list->head = list->head->next;

  ListType result = nodeToDelete->value;
  free(nodeToDelete);
  list->size--;
  return result;
}

ListType pop(LinkedList * list, uint index) {

  if (index == 0) {
    return popFront(list);
  } else {

    struct ListNode * prevElement = getElement(list, index - 1);

    struct ListNode * nodeToDelete = prevElement->next;

    prevElement->next = nodeToDelete->next;
    printf("a");
    ListType result = nodeToDelete->value;
    free(nodeToDelete->quest);
    printf("a");
    free(nodeToDelete);
    printf("a");
    list->size--;
    return result;
  }
}

ListType popBack(LinkedList * list) {
  return pop(list, list->size - 1);
}

void release(LinkedList * list) {
  while (list->size > 0) {
    popFront(list);
  }
}

void forEach(LinkedList * list, void (*callback)(char*, int, State)) {
  struct ListNode * currentNode = list->head;

  while (currentNode != NULL){
    callback(currentNode->quest->caption, currentNode->quest->priority, currentNode->quest->state);
    currentNode = currentNode->next;
  }
}   


