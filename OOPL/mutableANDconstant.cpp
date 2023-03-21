#include <iostream>
using namespace std;

class sample {
   public:
    int a = 1;
    mutable int b = 1;
};

class sample2 {
   public:
    int a = 1;
    // sample2(int x) { a = x; }
    explicit sample2(int x) { a = x; }
};

// void display(sample obj) { cout << obj.a << "&" << obj.b << endl; }
void display(sample2 obj) { cout << obj.a << endl; }

int main() {
    /*MUTABLE KEYWORD*/
    /*
    const sample obj;

    // obj.a = 0; //error
    obj.b = 0;
    display(obj);
    */

    /*EXPLICIT KEYWORD*/
    int p = 12;

    // display(p); //error
    display(sample2(p));

    return 0;
}