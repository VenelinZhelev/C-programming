 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

#define MENU printf("1. Add a new quest \n"); \
    printf("2. Change state by priority \n"); \
    printf("3. Print priority, name, state of all quests from highest to lowest \n"); \
    printf("4. Delete a quest \n"); \
    printf("5. Exit the program \n");

void debug(char text[]){
    printf("%s \n", text);
}

int main() {
    LinkedList arr = init();
    double something;
    int menu = -1;
    int temp_priority;
    char answer[30];
    int want_to_delete;
    while (1) {
        MENU
        scanf("%d", &menu);
        switch(menu) {
            case 1:
                printf("What is the quest's priority? \n");
                scanf("%d", &temp_priority); 
                if (temp_priority > arr.size) {
                    pushBack(&arr, arr.size + 1);
                    temp_priority = arr.size + 1;
                } else {
                    push(&arr, temp_priority, temp_priority);
                }
                printf("What is the quest's description? \n");
                scanf("%s", getElement(&arr, temp_priority - 2)->quest->caption);
                getElement(&arr, temp_priority - 2)->quest->state = NEW;
                break;
            case 2:
                printf("What priority does your quest have? \n");
                scanf("%d", &temp_priority); 
                if(temp_priority > arr.size + 1){
                    printf("No such priority");
                    exit(1);
                }
                printf("What do you wish its state to be? NEW/STARTED/FINISHED \n");
                scanf("%s", answer);
                if (strcmp(answer, "NEW") == 0) {
                    getElement(&arr, temp_priority - 1)->quest->state = NEW; 
                } else if (strcmp(answer, "STARTED") == 0) {
                    getElement(&arr, temp_priority - 1)->quest->state = STARTED; 
                } else if (strcmp(answer, "FINISHED") == 0) {
                    getElement(&arr, temp_priority - 1)->quest->state = FINISHED; 
                } else {
                    printf("Incorrect choice! Please try again \n");
                }
                break;
            case 3:
                printLinkedList(&arr);
                break;
            case 4:
                printf("Enter the quest you want to delete by property:\n ");
                
                scanf("%d", &want_to_delete);                 
                if(want_to_delete > arr.size + 1){
                    printf("No such priority");
                    exit(1);
                }
                something = pop(&arr, want_to_delete - 1);
                printf("The quest with priority %lf was deleted", something);
                break;
            case 5:
                printf("Exiting...");
                release(&arr);
                exit(0);
            default:
                printf("Wrong menu number please try again \n");
        }
    }
    return 0;
}