#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    char title[20];
    char author[20];
    char genre[20];
    int year;
    char isbn[20];
};

void saveBooks(struct Book* books, int numBooks) {
    FILE* file = fopen("books.txt", "w");
    if (file != NULL) {
        for (int i = 0; i < numBooks; i++) {
            fprintf(file, "%s %s %s %d %s\n", books[i].title, books[i].author, books[i].genre, books[i].year, books[i].isbn);
        }
        fclose(file);
    } else {
        fprintf(stderr, "Unable to save books to file.\n");
    }
}

void addBook(struct Book* books, int* numBooks) {
    struct Book newBook;
    printf("Enter book title: ");
    scanf("%s", newBook.title);
    printf("Enter book author: ");
    scanf("%s", newBook.author);
    printf("Enter book genre: ");
    scanf("%s", newBook.genre);
    printf("Enter publication year: ");
    scanf("%d", &newBook.year);
    printf("Enter ISBN: ");
    scanf("%s", newBook.isbn);

    books[*numBooks] = newBook;
    (*numBooks)++;
}

void displayBooks(struct Book* books, int numBooks) {
    for (int i = 0; i < numBooks; i++) {
        printf("Title: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);
        printf("Genre: %s\n", books[i].genre);
        printf("Year: %d\n", books[i].year);
        printf("ISBN: %s\n\n", books[i].isbn);
    }
}

void deleteBookByISBN(struct Book* books, int* numBooks, const char* isbn) {
    for (int i = 0; i < *numBooks; i++) {
        if (strcmp(books[i].isbn, isbn) == 0) {
            for (int j = i; j < *numBooks - 1; j++) {
                books[j] = books[j + 1];
            }
            (*numBooks)=(*numBooks)-1;
            printf("Book with ISBN %s deleted.\n", isbn);
            return;
        }
    }
    printf("Book with ISBN %s not found.\n", isbn);
}

int main() {
    struct Book books[100];
    int numBooks = 0;

    FILE* file = fopen("books.txt", "r");
    if (file != NULL) {
        while (fscanf(file, "%s %s %s %d %s", books[numBooks].title, books[numBooks].author, books[numBooks].genre, &books[numBooks].year, books[numBooks].isbn) == 5) {
            numBooks++;
        }
        fclose(file);
    } else {
        fprintf(stderr, "Unable to open file with books.\n");
    }

    int choice;
    char isbn[20];

    do {
        printf("1. Add a book\n");
        printf("2. Display all books\n");
        printf("3. Delete a book by ISBN\n");
        printf("4. Save and exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(books, &numBooks);
                break;
            case 2:
                printf(" \nHere is a list of all the books:");
                displayBooks(books, numBooks);
                break;
            case 3:
                printf("Enter ISBN of the book to delete: ");
                scanf("%s", isbn);
                deleteBookByISBN(books, &numBooks, isbn);
                break;
            case 4:
                saveBooks(books, numBooks);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
