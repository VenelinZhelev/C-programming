#include <stdio.h>
#include <stdlib.h>
#include "1.h"

void printDynamicArray(DynamicArray * arr) {
  for (int i = 0; i < arr->size; i++) {
    printf("Person %d: %.0lf ", i + 1, arr->buffer[i]);
  }
  printf("\n");
}

int main() {
    int choice;
    float curr_egn;
    DynamicArray dynarr = init(1);
    while(1)
    {
        printf("Menu\n");
        printf("1 - Add a person\n");
        printf("2 - Remove a person\n");
        printf("3 - Print all egns\n");
        printf("4 - Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the person's egn: ");
            scanf("%f", &curr_egn);
            pushBack(&dynarr, curr_egn);
            break;
        case 2:
            printf("Enter the person's egn: ");
            scanf("%f", &curr_egn);
            printf("%d", getElementIndex(&dynarr, curr_egn));
            int index = getElementIndex(&dynarr, curr_egn);
            removeElement(&dynarr, index);
            break;
        case 3:
            printf("Engs: \n");
            printDynamicArray(&dynarr);
            break;
        case 4:
            release(&dynarr);
            exit(0);
            break;
        default:
            printf("Invalid option\n");
            break;
        }
    }
    return 0;
}