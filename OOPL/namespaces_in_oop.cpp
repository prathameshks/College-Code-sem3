#include <iostream>
using namespace std;

namespace first {
int a = 1;
void fun() { cout << "This is in first namespace" << endl; }
}  // namespace first

namespace second {
int a = 2;
void fun() { cout << "This is in second namespace" << endl; }
}  // namespace second

using namespace first;

int main() {
    fun();
    cout << second::a << endl;
    return 0;
}