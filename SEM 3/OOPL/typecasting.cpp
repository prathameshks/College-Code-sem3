#include <iostream>
using namespace std;

class test {
   public:
    operator int() {
        int x = 69;
        return x;
    }
};

int main() {
    test obj;
    cout << int(obj);
    return 0;
}