#include <stdio.h>
#include <string.h>

// Structure definition for Books
struct Books {
    char title[100];
    char author[100];
    int pageNumbers;
};

// Function prototypes
void modifyBookTitle(struct Books *book, const char *newTitle);
void modifyCopyBookTitle(struct Books book, const char *newTitle);

int main() {
    struct Books book1;

    // Initialize the title of book1
    strcpy(book1.title, "Mathematics");
    printf("Original Title: %s\n", book1.title);

    // Attempt to modify the title by passing a copy of the book structure
    modifyCopyBookTitle(book1, "Chemistry");
    printf("After modifyCopyBookTitle: %s\n", book1.title);

    // Modify the title by passing a pointer to the book structure
    modifyBookTitle(&book1, "Physics");
    printf("After modifyBookTitle: %s\n", book1.title);

    return 0;
}

/**
 * Modifies the title of a book.
 * 
 * @param book Pointer to a Books structure.
 * @param newTitle New title for the book.
 */
void modifyBookTitle(struct Books *book, const char *newTitle) {
    strcpy(book->title, newTitle);
}

/**
 * Attempts to modify the title of a copy of the book.
 * This change will not affect the original book structure.
 * 
 * @param book Copy of a Books structure.
 * @param newTitle New title for the book.
 */
void modifyCopyBookTitle(struct Books book, const char *newTitle) {
    strcpy(book.title, newTitle);
}
