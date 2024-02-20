#include <stdio.h>

unsigned char lights_state = 0;  

void switch_lights(int room) {
    unsigned char mask = 1 << (room - 1);  
    lights_state ^= mask;  
}

void print_state() {
    printf("The light is on in rooms: ");
    int on_rooms[8];
    int count = 0;

    for (int i = 0; i < 8; i++) {
        if (lights_state & (1 << i)) {
            on_rooms[count++] = i + 1;
        }
    }

    if (count > 0) {
        for (int i = 0; i < count; i++) {
            printf("%d ", on_rooms[i]);
        }
        printf("\n");
    } else {
        printf("No lights are on in any room.\n");
    }
}

int main() {
    char choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Switch lights\n");
        printf("2. Print state\n");
        printf("3. Exit\n");

        printf("Enter your choice (1/2/3): ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                {
                    int room_number;
                    printf("Enter room number (1 to 8): ");
                    scanf("%d", &room_number);

                    if (1 <= room_number && room_number <= 8) {
                        switch_lights(room_number);
                    } else {
                        printf("Invalid room number. Please enter a number between 1 and 8.\n");
                    }
                }
                break;

            case '2':
                print_state();
                break;

            case '3':
                printf("Exiting the program.\n");
                return 0;

            default:
                printf("Invalid choice. Please enter 1, 2, or 3.\n");
        }
    }

    return 0;
}
