#include <iostream>
#define max 30
using namespace std;

class stack {
    char list[max];

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
    void push(char elmt) {
        if (not isfull()) {
            top++;
            list[top] = elmt;
        }
    }
    char peek() {
        return (top != -1) ? list[top] : ' ';
    }
    char pop() {
        if (not isempty()) {
            top--;
            return list[top + 1];
        }
    }
};

int priority(char opp) {
    switch (opp) {
        case '+':
        case '-':
            return 1;
            break;

        case '*':
        case '/':
            return 2;
            break;

        case '^':
            return 3;
            break;

        default:
            return 0;
            break;
    }
}

string infixToPostfix(string exp) {
    string postfix;
    char ch;
    stack opps;
    for (int i = 0; i < exp.size(); i++) {
        ch = exp[i];
        // cout << ch << " & " << postfix << endl;
        if (ch == '(') {
            opps.push('(');
        } else if (ch == '+' || ch == '^' || ch == '-' || ch == '*' || ch == '/') {
            if (priority(ch) <= priority(opps.peek())) {
                postfix += opps.pop();
                opps.push(ch);
            } else {
                opps.push(ch);
            }
        } else if (ch == ')') {
            while (opps.peek() != '(') {
                postfix += opps.pop();
            }
            opps.pop();
        } else {
            postfix += ch;
        }
    }
    while (!opps.isempty()) {
        postfix += opps.pop();
    }
    return postfix;
}

int main() {
    string exp, postfix;
    // cin>>exp;
    exp = "A^B*C-D+E/F/(G+H)";
    postfix = infixToPostfix(exp);
    cout << postfix << endl;

    return 0;
}