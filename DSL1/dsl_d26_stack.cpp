/*In any language program mostly syntax error occurs due to unbalancing delimiter such as
(),{},[]. Write C++ program using stack to check whether given expression is well
parenthesized or not*/
#include <iostream>
#define max 5
using namespace std;

template <class T>
class stack
{
    T list[max];

public:
    int top;
    stack()
    {
        top = -1;
    }
    bool isempty()
    {
        return (top <= -1) ? true : false;
    }
    bool isfull()
    {
        return (top == max - 1) ? true : false;
        // if (top == max - 1)
        //     return true;
        // else
        //     return false;
    }
    void push(T elmt)
    {
        if (not isfull())
        {
            top++;
            list[top] = elmt;
        }
    }
    T pop()
    {
        if (not isempty())
        {
            top--;
            return list[top + 1];
        }
        else
        {
            return NULL;
        }
    }
    void show()
    {
        if (isempty())
        {
            cout << "Empty";
        }
        else
        {
            for (int i = 0; i <= top; i++)
            {
                cout << list[i] << " ";
            }
        }

        cout << endl;
    }
};

int main()
{
    stack<int> mylist;
    bool loopcont = true;
    int ch;
    int elmt;
    while (loopcont)
    {
        cout << "MENU" << endl;
        cout << "1. Add\n2. Remove\n3. Display\n4. Exit" << endl;
        cout << "Enter Choice :";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter Element:";
            cin >> elmt;
            mylist.push(elmt);
            break;
        case 2:
            elmt = mylist.pop();
            if (elmt != NULL)
            {
                cout << "Element poped:" << elmt << endl;
            }
            else
            {
                cout << "Stack is Empty" << endl;
            }

            break;
        case 3:
            cout << "Current Stack is ";
            mylist.show();
            break;
        case 4:
            loopcont = false;
            cout << "THank yOU" << endl;
            break;

        default:
            cout << "Enter a valid choice" << endl;
            break;
        }
    }

    return 0;
}