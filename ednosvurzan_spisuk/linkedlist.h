#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef double ListType;
typedef unsigned int uint;
typedef enum {
NEW = 1,
STARTED,
FINISHED
} State;

typedef struct {
State state;
char caption[30];
int priority;
} Quest;

struct ListNode {
  ListType value;
  Quest * quest;
  struct ListNode * next;
};

typedef struct {
  struct ListNode * head;
  uint size;
} LinkedList;

LinkedList init();

void printLinkedList(LinkedList * list);
void pushFront(LinkedList * list, ListType value);
void push(LinkedList * list, uint index, ListType value);
void pushBack(LinkedList * list, ListType value);

struct ListNode * getElement(LinkedList * list, uint index);
void setElement(LinkedList * list, uint index, ListType value);

ListType popFront(LinkedList * list);
ListType pop(LinkedList * list, uint index);
ListType popBack(LinkedList * list);

void release(LinkedList * list);

void forEach(LinkedList * list, void (*callback)(char*, int, State));
#endif