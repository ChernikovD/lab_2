#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXIMUM 100

typedef struct {
    char firstName[MAXIMUM];
    char lastName[MAXIMUM];
} Author;

typedef struct {
    char title[MAXIMUM];
    Author author;
    int year;
    int pages;
} Book;

typedef struct {
    char firstName[MAXIMUM];
    char lastName[MAXIMUM];
    int readerID;
} Reader;

typedef struct {
    Book book;
    Reader reader;
    char orderDate[MAXIMUM];
    char returnDate[MAXIMUM];
} Order;

typedef struct {
    char name[MAXIMUM];
    char address[MAXIMUM];
    Book books[MAXIMUM];
    Reader readers[MAXIMUM];
    Order orders[MAXIMUM];
    int bookCount;
    int readerCount;
    int orderCount;
} Library;

int main()
{
    return 0;
}