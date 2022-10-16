// C++ program to dynamically
// deallocating the memory
#include <iostream>
using namespace std;

class geeks {
	int* ptr;

public:
	// Default constructor
	geeks()
	{
        cout<<"Constructor called\n";
		ptr = new int;
		*ptr = 10;
	}

	// Function to display the value
	void display()
	{
		cout << "Value: " << *ptr
			<< endl;
	}
};

// Driver Code
int main()
{
	// Dynamically allocating memory
	// using new operator
	int* ptr = new int;
    cout<<*ptr<<endl;
    *ptr = 10;
    cout<<ptr<<endl;
    cout<<*ptr<<endl;
    delete ptr;
    cout<<ptr<<endl;
    cout<<*ptr<<endl;

	return 0;
}
