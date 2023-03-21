/*
Imagine a publishing company which does marketing for book and audio cassette
versions. Create a class publication that stores the title (a string) and price
(type float) of publications. From this class derive two classes: book which
adds a page count (type int) and tape which adds a playing time in minutes (type
float). Write a program that instantiates the book and tape class, allows user
to enter data and displays the data members. If an exception is caught, replace
all the data member values with zero values.
*/


/*
+--------------------------------------------------+
| ▀█▀ █▄  █ █▀▀█ █▀▀█ █▀▄▀█ █▀█ █    █▀▀ ▀▀█▀▀ █▀▀ |
|  █  █ █ █ █    █  █ █ █ █ █▄█ █    █▀    █   █▀  |
| ▄█▄ █  ▀█ █▄▄█ █▄▄█ █   █ █   █▄▄█ █▄▄   █   █▄▄ |
+--------------------------------------------------+
*/


#include <iostream>
using namespace std;

class publication {
   protected:
    string title;
    double price;

   public:
    publication() {
        title = "";
        price = 0;
    }
    publication(string t, double p) {
        title = t;
        price = p;
    }
};

class book : private publication {
    int page_cnt;

   public:
    book(string title, double price, int pages) : publication(title, price) {
        page_cnt = pages;
    }

    void display() {
        cout << "Title:" << title << endl;
        cout << "Price:" << price << endl;
        cout << "Page Count:" << page_cnt << endl;
    }
};

class tape : private publication {
    float time;

   public:
    tape(string title, double price, float time) : publication(title, price) {
        this->time = time;
    }

    void display() {
        cout << "Title:" << title << endl;
        cout << "Price:" << price << endl;
        cout << "Time:" << time << endl;
    }
};

void set(string title, double price, float time) {
    tape(title, price, time);
    cout << "New tape Added" << endl;
}

void set(string title, double price, int page) {
    book(title, price, page);
    cout << "New book Added" << endl;
}

int main() {
    book* books[10];
    tape* tapes[10];
    int ch;
    do {
        cout << "MENU" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Add Tape" << endl;
        cout << "3. Display book" << endl;
        cout << "4. Display Tape" << endl;
        cout << "0 to exit" << endl;
        cout << "Enter your choice";
        cin >> ch;
        switch (ch) {
            case 1:
                break;

            case 0:

                cout << "thnk" << endl;
                break;

            default:
                cout << "Enter a valid Choice" << endl;
                break;
        }

    } while (ch != 0);

    return 0;
}
