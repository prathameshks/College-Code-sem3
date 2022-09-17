#include <iostream>
using namespace std;

class Complex
{
public:
	float real, imag;

	// default constructor
	Complex()
	{
		real = 0;
		imag = 0;
	}
	Complex(float real, float imag)
	{
		this->real = real;
		this->imag = imag;
	}

	// to display complex number
	void disp()
	{
		cout << *this;
	}

	// addition operator overloading
	Complex operator+(Complex num2)
	{
		Complex res;
		res.real = (real + num2.real);
		res.imag = (imag + num2.imag);
		return res;
	}

	// multipication operator overloading
	Complex operator*(Complex num2)
	{
		Complex res;
		res.real = ((real * num2.real) - (imag * num2.imag));
		res.imag = ((real * num2.imag) + (imag * num2.real));
		return res;
	}

	// insertion and extraction are not of complex class so overloaded using friend function
	friend ostream &operator<<(ostream &object, Complex &num);
	friend istream &operator>>(istream &object, Complex &num);
};

ostream &operator<<(ostream &object, Complex &num)
{
	// displaying complex number
	if (num.imag < 0)
	{
		object << num.real << " " << num.imag << "i";
	}
	else
	{
		object << num.real << " +" << num.imag << "i";
	}
	return object;
}

istream &operator>>(istream &object, Complex &num)
{
	// real and imag part input
	object >> num.real >> num.imag;
	return object;
}

int main()
{
	// Declearing Variables
	bool loop_control = true;
	int choice;
	Complex num1, num2, res;
	while (loop_control)
	{
		cout << "\n---- MENU ----" << endl;
		cout << "1. Add two Complex numbers\n2. Multiply two Complex Numbers\n3. Exit the Program" << endl;
		cout << "Enter your choice :";
		cin >> choice;
		if (choice == 1)
		{
			cout << "Enter First Complex Number :";
			cin >> num1;
			cout << "Enter Second Complex Number :";
			cin >> num2;
			res = num1 + num2;
			cout << "The Addition of " << num1 << " and " << num2 << " is " << res << endl;
		}
		else if (choice == 2)
		{
			cout << "Enter First Complex Number :";
			cin >> num1;
			cout << "Enter Second Complex Number :";
			cin >> num2;
			res = num1 * num2;
			cout << "The Multiplication of " << num1 << " and " << num2 << " is " << res << endl;
		}
		else if (choice == 3)
		{
			loop_control = false;
			cout << "Exiting, Thank You :)" << endl;
		}
		else
		{
			cout << "Enter a valid choice!" << endl;
		}
	}
	return 0;
}