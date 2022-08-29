// day 29/08/2022
#include <iostream>
using namespace std;

class Complex
{
public:
    float real, imag;

    Complex()
    {
        real = 0;
        imag = 0;
    }
    Complex(float a, float b)
    {
        real = a;
        imag = b;
    }
    // Overloading operators
    friend ostream &operator<<(ostream &stream, const Complex &num);
    friend istream &operator>>(ostream &stream, const Complex &num);

    friend Complex operator+(const Complex num2 ,const Complex num1);
    // Complex operator+(const Complex num1)
    // {
    //     Complex ans;
    //     ans.real = float(real + num1.real);
    //     ans.imag = float(imag + num1.imag);
    //     return ans;
    // }

    Complex operator*(Complex num1)
    {
        Complex ans;
        //(r1 + i1) * (r2 + i2)
        //(r1*r2 - i1*i2) + (r1*i2 + r2*i1)i
        ans.real = (real * num1.real) - (imag * num1.imag);
        ans.imag = (real * num1.imag) + (num1.real + imag);
        return ans;
    }
};

Complex operator+(const Complex num2 ,const Complex num1){
Complex ans;
        ans.real = float(num2.real + num1.real);
        ans.imag = float(num2.imag + num1.imag);
        return ans;
}


ostream &operator<<(ostream &stream, const Complex &num)
{
    if (num.imag < 0)
    {
        stream << num.real << "" << num.imag << "i";
    }
    else
    {
        stream << num.real << "+" << num.imag << "i";
    }
    return stream;
}
istream &operator>>(istream &stream, Complex &num)
{
    stream >> num.real >> num.imag;
    return stream;
}

int main()
{
    Complex c1, c2;
    cin >> c1;
    cout << c1 << endl;

    cin >> c2;
    cout << c2 << endl;

    Complex add = c1 + c2;
    Complex multi = c1 * c2;

    cout << "addition " << add << endl;
    cout << "Multiplication " << multi << endl;

    return 0;
}