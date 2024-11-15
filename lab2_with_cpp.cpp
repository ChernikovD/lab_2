#include <iostream>
#include <cstring>
#include <cstdlib>

#define MAX 100

class Author {
private:
    char firstName[MAX];
    char lastName[MAX];

public:
    Author(const char* firstName, const char* lastName) {
        strcpy(this->firstName, firstName);
        strcpy(this->lastName, lastName);
    }

    void print() const {
        std::cout << "Author: " << firstName << " " << lastName << std::endl;
    }
};

class Book {
private:
    char title[MAX];
    Author author;
    int year;
    int pages;

public:
    Book(const char* title, const Author& author, int year, int pages)
        : author(author), year(year), pages(pages) {
        strcpy(this->title, title);
    }

    void print() const {
        std::cout << "Book: " << title << ", Year: " << year << ", Pages: " << pages << std::endl;
        author.print();
    }
};

class Reader {
private:
    char firstName[MAX];
    char lastName[MAX];
    int readerID;

public:
    Reader(const char* firstName, const char* lastName, int readerID)
        : readerID(readerID) {
        strcpy(this->firstName, firstName);
        strcpy(this->lastName, lastName);
    }

    void print() const {
        std::cout << "Reader: " << firstName << " " << lastName << ", ID: " << readerID << std::endl;
    }
};

class Order {
private:
    Book book;
    Reader reader;
    char orderDate[MAX];
    char returnDate[MAX];

public:
    Order(const Book& book, const Reader& reader, const char* orderDate, const char* returnDate)
        : book(book), reader(reader) {
        strcpy(this->orderDate, orderDate);
        strcpy(this->returnDate, returnDate);
    }

    void print() const {
        std::cout << "Order Date: " << orderDate << ", Return Date: " << returnDate << std::endl;
        book.print();
        reader.print();
    }
};

class Library {
private:
    char name[MAX];
    char address[MAX];
    Book books[MAX];
    Reader readers[MAX];
    Order orders[MAX];
    int bookCount;
    int readerCount;
    int orderCount;

public:
    Library(const char* name, const char* address) {
        strcpy(this->name, name);
        strcpy(this->address, address);
        bookCount = 0;
        readerCount = 0;
        orderCount = 0;
    }

    void addBook(const Book& book) {
        if (bookCount < MAX) {
            books[bookCount++] = book;
        }
    }

    void addReader(const Reader& reader) {
        if (readerCount < MAX) {
            readers[readerCount++] = reader;
        }
    }

    void addOrder(const Order& order) {
        if (orderCount < MAX) {
            orders[orderCount++] = order;
        }
    }

    void print() const {
        std::cout << "Library: " << name << ", Address: " << address << std::endl;
        std::cout << "Books:" << std::endl;
        for (int i = 0; i < bookCount; i++) {
            books[i].print();
        }
        std::cout << "Readers:" << std::endl;
        for (int i = 0; i < readerCount; i++) {
            readers[i].print();
        }
        std::cout << "Orders:" << std::endl;
        for (int i = 0; i < orderCount; i++) {
            orders[i].print();
        }
    }
};

int main() {
    // Статические переменные
    Author author1("John", "Doe");
    Book book1("The Great Book", author1, 2000, 300);
    Reader reader1("Jane", "Smith", 12345);
    Order order1(book1, reader1, "2023-10-01", "2023-10-15");
    Library library1("Central Library", "123 Main Street");
    library1.addBook(book1);
    library1.addReader(reader1);
    library1.addOrder(order1);
    library1.print();

    // Динамические переменные
    Author* author2 = new Author("Alice", "Johnson");
    Book* book2 = new Book("The Amazing Book", *author2, 2010, 400);
    Reader* reader2 = new Reader("Bob", "Brown", 67890);
    Order* order2 = new Order(*book2, *reader2, "2023-10-02", "2023-10-16");
    Library* library2 = new Library("City Library", "456 Elm St");
    library2->addBook(*book2);
    library2->addReader(*reader2);
    library2->addOrder(*order2);
    library2->print();

    // Освобождение памяти
    delete author2;
    delete book2;
    delete reader2;
    delete order2;
    delete library2;

    return 0;
}