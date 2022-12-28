/*
Implement a class Complex which represents the Complex Number data type.
Implement the following
1. Constructor (including a default constructor which creates the complex number
0+0i).
2. Overload operator+ to add two complex numbers.
3. Overload operator* to multiply two complex numbers.
4. Overload operators << and >> to print and read Complex Numbers.
*/

#include <iostream>
using namespace std;

class complex {
   private:
    double real, imag;

   public:
    complex();
    complex(double x, double y);

    complex operator+(complex num);
    complex operator*(complex num);

    friend ostream &operator<<(ostream &out, complex &num);
    friend istream &operator>>(istream &in, complex &num);
};

complex::complex() {
    real = 0;
    imag = 0;
}

complex::complex(double x, double y) {
    real = x;
    imag = y;
}

complex complex::operator+(complex num) {
    complex ans;
    ans.real = real + num.real;
    ans.imag = imag + num.imag;
    return ans;
}

complex complex::operator*(complex num) {
    complex ans;
    ans.real = (real * num.real) - (imag * num.imag);
    ans.imag = (real * num.imag) + (imag * num.real);
    return ans;
}

ostream &operator<<(ostream &out, complex &num) {
    if (num.imag < 0) {
        out << num.real << num.imag << "i";
    } else {
        out << num.real << "+" << num.imag << "i";
    }
    return out;
}

istream &operator>>(istream &in, complex &num) {
    in >> num.real >> num.imag;
    return in;
}

int main() {
    complex num1, num2;
    cout<<"Enter number 1:";
    cin >> num1;

    complex ans = num1 + num2;
    cout << ans<<endl;
    cout<<"Enter number 2:";
    cin >> num2;
    ans = num1 * num2;
    cout << ans<<endl;

    return 0;
}


