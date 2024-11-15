#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#define MAX 100

class Author {
private:
    std::string firstName;
    std::string lastName;

public:
    Author(const std::string& firstName, const std::string& lastName)
        : firstName(firstName), lastName(lastName) {}

    void print() const {
        std::cout << "Author: " << firstName << " " << lastName << std::endl;
    }
};

class Book {
private:
    std::string title;
    Author author;
    int year;
    int pages;

public:
    Book(const std::string& title, const Author& author, int year, int pages)
        : author(author), year(year), pages(pages), title(title) {}

    void print() const {
        std::cout << "Book: " << title << ", Year: " << year << ", Pages: " << pages << std::endl;
        author.print();
    }
};

class Reader {
private:
    std::string firstName;
    std::string lastName;
    int readerID;

public:
    Reader(const std::string& firstName, const std::string& lastName, int readerID)
        : firstName(firstName), lastName(lastName), readerID(readerID) {}

    void print() const {
        std::cout << "Reader: " << firstName << " " << lastName << ", ID: " << readerID << std::endl;
    }
};

class Order {
private:
    Book book;
    Reader reader;
    std::string orderDate;
    std::string returnDate;

public:
    Order(const Book& book, const Reader& reader, const std::string& orderDate, const std::string& returnDate)
        : book(book), reader(reader), orderDate(orderDate), returnDate(returnDate) {}

    void print() const {
        std::cout << "Order Date: " << orderDate << ", Return Date: " << returnDate << std::endl;
        book.print();
        reader.print();
    }
};

class Library {
private:
    std::string name;
    std::string address;
    std::vector<Book> books;
    std::vector<Reader> readers;
    std::vector<Order> orders;
    int bookCount;
    int readerCount;
    int orderCount;

public:
    Library(const std::string& name, const std::string& address)
        : name(name), address(address), bookCount(0), readerCount(0), orderCount(0) {}

    void addBook(const Book& book) {
        books.push_back(book);
        bookCount++;
    }

    void addReader(const Reader& reader) {
        readers.push_back(reader);
        readerCount++;
    }

    void addOrder(const Order& order) {
        orders.push_back(order);
        orderCount++;
    }

    void print() const {
        std::cout << "Library: " << name << ", Address: " << address << std::endl;
        std::cout << "Books:" << std::endl;
        for (const auto& book : books) {
            book.print();
        }
        std::cout << "Readers:" << std::endl;
        for (const auto& reader : readers) {
            reader.print();
        }
        std::cout << "Orders:" << std::endl;
        for (const auto& order : orders) {
            order.print();
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

    // Динамический массив объектов класса
    const int size = 3;
    Author* authors = new Author[size]{
        Author("Author1", "LastName1"),
        Author("Author2", "LastName2"),
        Author("Author3", "LastName3")
    };

    for (int i = 0; i < size; ++i) {
        authors[i].print();
    }

    delete[] authors;

    // Массив динамических объектов класса
    Author** dynamicAuthors = new Author * [size];
    for (int i = 0; i < size; ++i) {
        dynamicAuthors[i] = new Author("DynamicAuthor" + std::to_string(i + 1), "DynamicLastName" + std::to_string(i + 1));
        dynamicAuthors[i]->print();
    }

    for (int i = 0; i < size; ++i) {
        delete dynamicAuthors[i];
    }
    delete[] dynamicAuthors;
    
    return 0;
}
