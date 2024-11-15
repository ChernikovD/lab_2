#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#define MAX 100

// Класс Author представляет автора книги
class Author {
private:
    std::string firstName; // Имя автора
    std::string lastName;  // Фамилия автора

public:
    // Конструктор для инициализации автора
    Author(const std::string& firstName, const std::string& lastName)
        : firstName(firstName), lastName(lastName) {}

    // Метод для вывода информации об авторе
    void print() const {
        std::cout << "Author: " << firstName << " " << lastName << std::endl;
    }
};

// Класс Book представляет книгу
class Book {
private:
    std::string title; // Название книги
    Author author;   // Автор книги
    int year;        // Год издания
    int pages;       // Количество страниц

public:
    // Конструктор для инициализации книги
    Book(const std::string& title, const Author& author, int year, int pages)
        : author(author), year(year), pages(pages), title(title) {}

    // Метод для вывода информации о книге
    void print() const {
        std::cout << "Book: " << title << ", Year: " << year << ", Pages: " << pages << std::endl;
        author.print(); // Вывод информации об авторе
    }
};

// Класс Reader представляет читателя
class Reader {
private:
    std::string firstName; // Имя читателя
    std::string lastName;  // Фамилия читателя
    int readerID;        // ID читателя

public:
    // Конструктор для инициализации читателя
    Reader(const std::string& firstName, const std::string& lastName, int readerID)
        : firstName(firstName), lastName(lastName), readerID(readerID) {}

    // Метод для вывода информации о читателе
    void print() const {
        std::cout << "Reader: " << firstName << " " << lastName << ", ID: " << readerID << std::endl;
    }
};

// Класс Order представляет заказ книги
class Order {
private:
    Book book;         // Книга
    Reader reader;     // Читатель
    std::string orderDate; // Дата заказа
    std::string returnDate; // Дата возврата

public:
    // Конструктор для инициализации заказа
    Order(const Book& book, const Reader& reader, const std::string& orderDate, const std::string& returnDate)
        : book(book), reader(reader), orderDate(orderDate), returnDate(returnDate) {}

    // Метод для вывода информации о заказе
    void print() const {
        std::cout << "Order Date: " << orderDate << ", Return Date: " << returnDate << std::endl;
        book.print(); // Вывод информации о книге
        reader.print(); // Вывод информации о читателе
    }
};

// Класс Library представляет библиотеку
class Library {
private:
    std::string name; // Название библиотеки
    std::string address; // Адрес библиотеки
    std::vector<Book> books; // Массив книг
    std::vector<Reader> readers; // Массив читателей
    std::vector<Order> orders; // Массив заказов
    int bookCount; // Количество книг
    int readerCount; // Количество читателей
    int orderCount; // Количество заказов

public:
    // Конструктор для инициализации библиотеки
    Library(const std::string& name, const std::string& address)
        : name(name), address(address), bookCount(0), readerCount(0), orderCount(0) {}

    // Метод для добавления книги в библиотеку
    void addBook(const Book& book) {
        books.push_back(book); // Добавление книги
        bookCount++;
    }

    // Метод для добавления читателя в библиотеку
    void addReader(const Reader& reader) {
        readers.push_back(reader); // Добавление читателя
        readerCount++;
    }

    // Метод для добавления заказа в библиотеку
    void addOrder(const Order& order) {
        orders.push_back(order); // Добавление заказа
        orderCount++;
    }

    // Метод для вывода информации о библиотеке
    void print() const {
        std::cout << "Library: " << name << ", Address: " << address << std::endl;
        std::cout << "Books:" << std::endl;
        for (const auto& book : books) {
            book.print(); // Вывод информации о книге
        }
        std::cout << "Readers:" << std::endl;
        for (const auto& reader : readers) {
            reader.print(); // Вывод информации о читателе
        }
        std::cout << "Orders:" << std::endl;
        for (const auto& order : orders) {
            order.print(); // Вывод информации о заказе
        }
    }
};

int main() {
    // Статические переменные
    Author author1("John", "Doe"); // Создание автора
    Book book1("The Great Book", author1, 2000, 300); // Создание книги
    Reader reader1("Jane", "Smith", 12345); // Создание читателя
    Order order1(book1, reader1, "2023-10-01", "2023-10-15"); // Создание заказа
    Library library1("Central Library", "123 Main Street"); // Создание библиотеки
    library1.addBook(book1); // Добавление книги в библиотеку
    library1.addReader(reader1); // Добавление читателя в библиотеку
    library1.addOrder(order1); // Добавление заказа в библиотеку
    library1.print(); // Вывод информации о библиотеке

    // Динамические переменные
    Author* author2 = new Author("Alice", "Johnson"); // Создание автора
    Book* book2 = new Book("The Amazing Book", *author2, 2010, 400); // Создание книги
    Reader* reader2 = new Reader("Bob", "Brown", 67890); // Создание читателя
    Order* order2 = new Order(*book2, *reader2, "2023-10-02", "2023-10-16"); // Создание заказа
    Library* library2 = new Library("City Library", "456 Elm St"); // Создание библиотеки
    library2->addBook(*book2); // Добавление книги в библиотеку
    library2->addReader(*reader2); // Добавление читателя в библиотеку
    library2->addOrder(*order2); // Добавление заказа в библиотеку
    library2->print(); // Вывод информации о библиотеке

    // Освобождение памяти
    delete author2; // Освобождение памяти автора
    delete book2; // Освобождение памяти книги
    delete reader2; // Освобождение памяти читателя
    delete order2; // Освобождение памяти заказа
    delete library2; // Освобождение памяти библиотеки

    return 0;
}