#include <stdio.h>
#include <string.h>

void print_matrix(int arr[][4], int redowe) {
    for (int i = 0; i < redowe; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", ((arr + i) + j));
        }
        printf("\n");
    }
}

int main() {
    int arr[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    print_matrix(arr, 3);
    return 0;
}