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
    cout << "* Maximun Parinthesis Allowed are 15 *" << endl;
    cout << "Enter the expression:";
    cin >> exp;
    bool flag = false;

    // cout<<exp.size()<<endl;
    for (int i = 0; i < exp.size(); i++) {
        // for opening parenthesis add its closing parenthesis 
        if (exp[i] == '{') {
            list.push('}');
        } else if (exp[i] == '[') {
            list.push(']');
        } else if (exp[i] == '(') {
            list.push(')');
        } else if ((exp[i] == '}') or (exp[i] == ']') or (exp[i] == ')')) {
            // check if closing parenthesis is in stack
            if (exp[i] != list.pop()) {
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
