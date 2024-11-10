#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct {
    char firstName[MAX];
    char lastName[MAX];
} Author;

typedef struct {
    char title[MAX];
    Author author;
    int year;
    int pages;
} Book;

typedef struct {
    char firstName[MAX];
    char lastName[MAX];
    int readerID;
} Reader;

typedef struct {
    Book book;
    Reader reader;
    char orderDate[MAX];
    char returnDate[MAX];
} Order;

typedef struct {
    char name[MAX];
    char address[MAX];
    Book books[MAX];
    Reader readers[MAX];
    Order orders[MAX];
    int bookCount;
    int readerCount;
    int orderCount;
} Library;

// Функции для работы с Автором
void initAuthor(Author* author, const char* firstName, const char* lastName) {
    strcpy(author->firstName, firstName);
    strcpy(author->lastName, lastName);
}

void printAuthor(const Author* author) {
    printf("Author: %s %s, Birth Year: %d\n", author->firstName, author->lastName);
}

// Функции для работы с Книгой
void initBook(Book* book, const char* title, const Author* author, int year, int pages) {
    strcpy(book->title, title);
    book->author = *author;
    book->year = year;
    book->pages = pages;
}

void printBook(const Book* book) {
    printf("Book: %s, Year: %d, Pages: %d\n", book->title, book->year, book->pages);
    printAuthor(&book->author);
}

// Функции для работы с Читателем
void initReader(Reader* reader, const char* firstName, const char* lastName, int readerID) {
    strcpy(reader->firstName, firstName);
    strcpy(reader->lastName, lastName);
    reader->readerID = readerID;
}

void printReader(const Reader* reader) {
    printf("Reader: %s %s, ID: %d\n", reader->firstName, reader->lastName, reader->readerID);
}

// Функции для работы с Заказом
void initOrder(Order* order, const Book* book, const Reader* reader, const char* orderDate, const char* returnDate) {
    order->book = *book;
    order->reader = *reader;
    strcpy(order->orderDate, orderDate);
    strcpy(order->returnDate, returnDate);
}

void printOrder(const Order* order) {
    printf("Order Date: %s, Return Date: %s\n", order->orderDate, order->returnDate);
    printBook(&order->book);
    printReader(&order->reader);
}

// Функции для работы с Библиотекой
void initLibrary(Library* library, const char* name, const char* address) {
    strcpy(library->name, name);
    strcpy(library->address, address);
    library->bookCount = 0;
    library->readerCount = 0;
    library->orderCount = 0;
}

void addBookToLibrary(Library* library, const Book* book) {
    if (library->bookCount < MAX) {
        library->books[library->bookCount++] = *book;
    }
}

void addReaderToLibrary(Library* library, const Reader* reader) {
    if (library->readerCount < MAX) {
        library->readers[library->readerCount++] = *reader;
    }
}

void addOrderToLibrary(Library* library, const Order* order) {
    if (library->orderCount < MAX) {
        library->orders[library->orderCount++] = *order;
    }
}

void printLibrary(const Library* library) {
    printf("Library: %s, Address: %s\n", library->name, library->address);
    printf("Books:\n");
    for (int i = 0; i < library->bookCount; i++) {
        printBook(&library->books[i]);
    }
    printf("Readers:\n");
    for (int i = 0; i < library->readerCount; i++) {
        printReader(&library->readers[i]);
    }
    printf("Orders:\n");
    for (int i = 0; i < library->orderCount; i++) {
        printOrder(&library->orders[i]);
    }
}

int main() {
    // Статические переменные
    Author author1;
    initAuthor(&author1, "John", "Doe");

    Book book1;
    initBook(&book1, "The Great Book", &author1, 2000, 300);

    Reader reader1;
    initReader(&reader1, "Jane", "Smith", 12345);

    Order order1;
    initOrder(&order1, &book1, &reader1, "2023-10-01", "2023-10-15");

    Library library1;
    initLibrary(&library1, "Central Library", "123 Main Street");
    addBookToLibrary(&library1, &book1);
    addReaderToLibrary(&library1, &reader1);
    addOrderToLibrary(&library1, &order1);

    printLibrary(&library1);

    // Динамические переменные
    Author* author2 = (Author*)malloc(sizeof(Author));
    initAuthor(author2, "Alice", "Johnson");

    Book* book2 = (Book*)malloc(sizeof(Book));
    initBook(book2, "The Amazing Book", author2, 2010, 400);

    Reader* reader2 = (Reader*)malloc(sizeof(Reader));
    initReader(reader2, "Bob", "Brown", 67890);

    Order* order2 = (Order*)malloc(sizeof(Order));
    initOrder(order2, book2, reader2, "2023-10-02", "2023-10-16");

    Library* library2 = (Library*)malloc(sizeof(Library));
    initLibrary(library2, "City Library", "456 Elm St");
    addBookToLibrary(library2, book2);
    addReaderToLibrary(library2, reader2);
    addOrderToLibrary(library2, order2);

    printLibrary(library2);

    // Освобождение памяти
    free(author2);
    free(book2);
    free(reader2);
    free(order2);
    free(library2);

    return 0;
}