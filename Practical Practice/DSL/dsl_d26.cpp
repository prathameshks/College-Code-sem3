#include <iostream>
#define MAX_LENGTH 20
using namespace std;

class stack {
    char list[MAX_LENGTH];
    int top;

   public:
    stack() { top = -1; }
    bool isfull() {
        if (top == MAX_LENGTH - 1) {
            return true;
        }
        return false;
    }
    bool isempty() {
        if (top == -1) {
            return true;
        }
        return false;
    }
    void push(char val) {
        if (!isfull()) {
            top++;
            list[top] = val;
        }
    }
    char pop() {
        if (!isempty()) {
            return list[top--];
        }
        return ' ';
    }
};

int main() {
    string exp;
    int flag = 1;
    cout << "Enter Expression:";
    cin >> exp;

    stack para;

    for (int i = 0; i < exp.size(); i++) {
        if (exp[i] == '{')
            para.push('}');
        else if (exp[i] == '[')
            para.push(']');
        else if (exp[i] == '(')
            para.push(')');
        else if (exp[i] == '}' || exp[i] == ']' || exp[i] == ')') {
            if (para.pop() != exp[i]) {
                flag = 0;
                break;
            }
        }
    }
    if (flag == 0) {
        cout << "Invalid Expression" << endl;
    } else {
        if (!para.isempty()) {
            cout << "Invalid Expression" << endl;
        } else {
            cout << "Correct Expression" << endl;
        }
    }

    return 0;
}