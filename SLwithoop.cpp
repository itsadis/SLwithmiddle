To convert the provided code to use Object-Oriented Programming (OOP) principles, you can create a class for the linked list and a class for the book. Here's an example of how you can structure the code using OOP:

```cpp
#include <iostream>
#include <string>

using namespace std;

// Declaration of Book class
class Book {
public:
    string judul, pengarang;
    int tahunTerbit;
    Book* next;

    // Constructor
    Book(string judul, string pengarang, int tahunTerbit) {
        this->judul = judul;
        this->pengarang = pengarang;
        this->tahunTerbit = tahunTerbit;
        this->next = nullptr;
    }
};

// Declaration of LinkedList class
class LinkedList {
private:
    Book* head;
    Book* tail;

public:
    // Constructor
    LinkedList() : head(nullptr), tail(nullptr) {}

    // Destructor
    ~LinkedList() {
        while (head != nullptr) {
            Book* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }

    // Add a book to the beginning of the list
    void addFirst(string judul, string pengarang, int tahunTerbit) {
        Book* newNode = new Book(judul, pengarang, tahunTerbit);
        newNode->next = head;
        head = newNode;
        if (tail == nullptr) {
            tail = head;
        }
    }

    // Add a book to the end of the list
    void addLast(string judul, string pengarang, int tahunTerbit) {
        Book* newNode = new Book(judul, pengarang, tahunTerbit);
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Add a book to the middle of the list at the specified position
    void addMiddle(string judul, string pengarang, int tahunTerbit, int posisi) {
        if (posisi < 1 || posisi > count()) {
            cout << "Posisi diluar jangkauan" << endl;
        } else if (posisi == 1) {
            cout << "Posisi bukan posisi tengah" << endl;
        } else {
            Book* newNode = new Book(judul, pengarang, tahunTerbit);
            Book* cur = head;
            for (int i = 1; i < posisi - 1; ++i) {
                cur = cur->next;
            }
            newNode->next = cur->next;
            cur->next = newNode;
        }
    }

    // Remove the first book from the list
    void removeFirst() {
        if (head != nullptr) {
            Book* temp = head;
            head = head->next;
            delete temp;
            if (head == nullptr) {
                tail = nullptr;
            }
        } else {
            cout << "List is empty. Cannot remove from an empty list." << endl;
        }
    }

    // Remove the last book from the list
    void removeLast() {
        if (head != nullptr) {
            if (head == tail) {
                delete head;
                head = tail = nullptr;
            } else {
                Book* cur = head;
                while (cur->next != tail) {
                    cur = cur->next;
                }
                delete tail;
                tail = cur;
                tail->next = nullptr;
            }
        } else {
            cout << "List is empty. Cannot remove from an empty list." << endl;
        }
    }

    // Remove a book from the middle of the list at the specified position
    void removeMiddle(int posisi) {
        if (posisi < 1 || posisi > count()) {
            cout << "Posisi diluar jangkauan" << endl;
        } else if (posisi == 1) {
            cout << "Posisi bukan tengah" << endl;
        } else {
            Book* cur = head;
            for (int i = 1; i < posisi; ++i) {
                Book* temp = cur;
                cur = cur->next;
                if (i == posisi - 1) {
                    temp->next = cur->next;
                    delete cur;
                    break;
                }
            }
        }
    }

    // Change the details of the first book in the list
    void changeFirst(string judul, string pengarang, int tahunTerbit) {
        if (head != nullptr) {
            head->judul = judul;
            head->pengarang = pengarang;
            head->tahunTerbit = tahunTerbit;
        } else {
            cout << "List is empty. Cannot change details in an empty list." << endl;
        }
    }

    // Change the details of the last book in the list
    void changeLast(string judul, string pengarang, int tahunTerbit) {
        if (tail != nullptr) {
            tail->judul = judul;
            tail->pengarang = pengarang;
            tail->tahunTerbit = tahunTerbit;
        } else {
            cout << "List is empty. Cannot change details in an empty list." << endl;
        }
    }

    // Change the details of a book in the middle of the list at the specified position
    void changeMiddle(string judul, string pengarang, int