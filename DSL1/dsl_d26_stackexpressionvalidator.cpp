/*In any language program mostly syntax error occurs due to unbalancing delimiter such as
(),{},[]. Write C++ program using stack to check whether given expression is well
parenthesized or not*/
#include <iostream>
#define max 15
using namespace std;

template <class T>
class stack {
    T list[max];

   public:
    int top;
    stack() {
        top = -1;
    }
    bool isempty() {
        return (top <= -1) ? true : false;
    }
    bool isfull() {
        return (top == max - 1) ? true : false;
    }
    void push(T elmt) {
        if (not isfull()) {
            top++;
            list[top] = elmt;
        }
    }
    T pop() {
        if (not isempty()) {
            top--;
            return list[top + 1];
        }
    }
    void show() {
        if (isempty())
            cout << "Empty";
        else
            for (int i = 0; i <= top; i++)
                cout << list[i] << " ";

        cout << endl;
    }
};

int main() {
    stack<char> list;

    string exp;
    char lastpara;
    cout << "* Maximun Parinthesis Allowed are 15 *" << endl;
    cout << "Enter the expression:";
    cin >> exp;
    bool flag = false;

    // cout<<exp.size()<<endl;
    for (int i = 0; i < exp.size(); i++) {
        if (exp[i] == '{') {
            list.push('}');
        } else if (exp[i] == '[') {
            list.push(']');
        } else if (exp[i] == '(') {
            list.push(')');
        } else if ((exp[i] == '}') or (exp[i] == ']') or (exp[i] == ')')) {
            lastpara = list.pop();
            if (exp[i] != lastpara) {
                flag = true;
                break;
            }
        }
    }

    if (flag or (not list.isempty())) {
        cout << "Expression is not valid " << endl;
    } else {
        cout << "Expression is valid " << endl;
    }
    return 0;
}


/*
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

*/