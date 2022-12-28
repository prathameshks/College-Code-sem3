/*
Implement C++ program for expression conversion as infix to postfix and its
evaluation using stack based on given conditions:
1. Operands and operator, both must be single character.
2. Input Postfix expression must be in a desired format.
3. only '+', '-', '*' and '/ ' operators are expected.
*/
#include <iostream>
#define MAX_LENGTH 20
using namespace std;

template <class T1>
class stack {
    T1 list[MAX_LENGTH];
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
    void push(T1 val) {
        if (!isfull()) {
            top++;
            list[top] = val;
        }
    }
    T1 pop() {
        if (!isempty()) {
            return list[top--];
        }
        return ' ';
    }
    T1 peek() {
        if (!isempty()) {
            return list[top];
        }
        return ' ';
    }
};

int priority(char ch) {
    if (ch == '*' || ch == '/') {
        return 2;
    } else if (ch == '+' || ch == '-') {
        return 1;
    } else {
        return 0;
    }
}

double postfix_evaluation(string exp) {
    stack<double> temp_val;
    double n1, n2, val;
    for (int i = 0; i < exp.size(); i++) {
        switch (exp[i]) {
            case '+':
                n2 = temp_val.pop();
                n1 = temp_val.pop();
                val = n1 + n2;
                break;
            case '-':
                n2 = temp_val.pop();
                n1 = temp_val.pop();
                val = n1 - n2;
                break;
            case '*':
                n2 = temp_val.pop();
                n1 = temp_val.pop();
                val = n1 * n2;
                break;
            case '/':
                n2 = temp_val.pop();
                n1 = temp_val.pop();
                val = n1 / n2;
                break;
            default:
                cout << "Enter value for " << exp[i] << ":";
                cin >> val;
                break;
        }
        temp_val.push(val);
    }
    return temp_val.pop();
}

string infix_to_postfix(string exp) {
    string ans;
    stack<char> para;
    for (int i = 0; i < exp.size(); i++) {
        switch (exp[i]) {
            case '(':
                para.push('(');
                break;
            case '+':
            case '-':
            case '/':
            case '*':
                while ((priority(exp[i]) <= priority(para.peek())) &&
                       !para.isempty()) {
                    ans += para.pop();
                }
                para.push(exp[i]);
                break;
            case ')':
                while (para.peek() != '(') {
                    ans += para.pop();
                }
                para.pop();
                break;
            default:
                ans += (exp[i]);
                break;
        }
    }
    while (!para.isempty()) {
        ans += para.pop();
    }
    return ans;
}

int main() {
    string exp;
    int flag = 1;
    cout << "Enter Expression:";
    cin >> exp;
    string post = infix_to_postfix(exp);
    cout << "Postfix Expression is " << post << endl;
    double res = postfix_evaluation(post);
    cout << "Evaluation is " << res << endl;
    return 0;
}