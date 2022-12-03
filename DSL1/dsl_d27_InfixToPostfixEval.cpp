#include <iostream>
#define MAX_ARR_SIZE 30
using namespace std;

// global value list
int VAR_VALS[58] = {0};
int VAR_COUNT = 0;
bool IS_VAL_SET = false;

// Stack to store characters
class char_stack {
    char list[MAX_ARR_SIZE];

   public:
    int top;
    char_stack() { top = -1; }
    bool isempty() { return (top <= -1) ? true : false; }
    bool isfull() { return (top == MAX_ARR_SIZE - 1) ? true : false; }
    void push(char elmt) {
        if (not isfull()) {
            top++;
            list[top] = elmt;
        }
    }
    char peek() { return (top != -1) ? list[top] : ' '; }
    char pop() {
        if (not isempty()) {
            top--;
            return list[top + 1];
        }
    }
};

class stack {
    int list[MAX_ARR_SIZE];

   public:
    int top;
    stack() { top = -1; }
    bool isempty() { return (top <= -1) ? true : false; }
    bool isfull() { return (top == MAX_ARR_SIZE - 1) ? true : false; }
    void push(int elmt) {
        if (not isfull()) {
            top++;
            list[top] = elmt;
        }
    }
    int pop() {
        if (not isempty()) {
            top--;
            return list[top + 1];
        }
    }
    void dispaly() {
        for (int i = 0; i < top + 1; i++) {
            cout << list[i] << " ";
        }
        cout << endl;
    }
};

// function which return the proirity of the operation
int priority(char opp) {
    if (opp == '+' || opp == '-')
        return 1;
    else if (opp == '*' || opp == '/')
        return 2;
    else
        return 0;
}

string infixToPostfix(string exp) {
    string postfix;
    char ch;
    char_stack opps;
    for (int i = 0; i < exp.size(); i++) {
        ch = exp[i];
        // if char is parenthesis so highest priority
        if (ch == '(') {
            opps.push('(');
        } else if (ch == '+' || ch == '^' || ch == '-' || ch == '*' ||
                   ch == '/') {
            // all operators in stack with higher ar equal priority are poped
            while (!opps.isempty() && priority(ch) <= priority(opps.peek())) {
                postfix += opps.pop();
            }
            opps.push(ch);
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

// function to set values of variables
void setVariables(int count = 0) {
    int varnum;
    if (count == 0) {
        cout << "Enter Number of Variables in Expression:";
        cin >> varnum;
    } else {
        varnum = count;
    }

    VAR_COUNT = varnum + 64;
    for (int i = 0; i < varnum; i++) {
        cout << "Enter Value for '" << (char)(65 + i) << "':";
        cin >> VAR_VALS[i];
        VAR_VALS[i + 32] = VAR_VALS[i];  // setting value of lowercase variables
                                         // same as uppercase
    }
    IS_VAL_SET = true;
}

// postfix calculator
int evalPostfix(string exp) {
    int max_var = 0;
    for (int i = 0; i < exp.size(); i++) {
        if (exp[i] >= 65 && exp[i] <= 90) {
            if (exp[i] > max_var) {
                max_var = exp[i];
            }
        } else if (exp[i] > 97 && exp[i] <= 122) {
            if ((exp[i] - 32) > max_var) {
                max_var = (exp[i] - 32);
            }
        }
    }
    if (!IS_VAL_SET || max_var > VAR_COUNT) {
        setVariables(max_var - 64);
    }

    int len = exp.size();
    int val1, val2, ans, temp;
    stack values;
    for (int i = 0; i < len; i++) {
        switch (exp[i]) {
            case '+':
                val2 = values.pop();
                val1 = values.pop();
                temp = val1 + val2;
                values.push(temp);
                break;
            case '*':
                val2 = values.pop();
                val1 = values.pop();
                temp = val1 * val2;
                values.push(temp);
                break;
            case '-':
                val2 = values.pop();
                val1 = values.pop();
                temp = val1 - val2;
                values.push(temp);
                break;
            case '/':
                val2 = values.pop();
                val1 = values.pop();
                temp = val1 / val2;
                values.push(temp);
                break;
            case ' ':
                break;

            default:
                values.push(VAR_VALS[int(exp[i] - 65)]);
                break;
        }
    }
    return values.pop();
}

int main() {
    cout << "\n***\nNot Case Sensitive\nMaximum 30 characters\n***\n" << endl;
    int ch;
    bool while_ctrl = true;
    string temp, LastInfixExp;
    int ans;
    while (while_ctrl) {
        cout << "MENU\n1. Infix To Postfix\n2. Set Variable Values\n3. Postfix "
                "Calculator\n4. Exit"
             << endl;
        cout << "Enter Your Choice:";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "Enter a Infix Expression:";
                cin >> temp;
                LastInfixExp = infixToPostfix(temp);
                cout << "Postfix Expression is :" << LastInfixExp << endl;
                break;

            case 2:
                setVariables();
                cout << "Variables set sucessfully" << endl;
                break;

            case 3:
                if (LastInfixExp.size() != 0) {
                    cout << "Enter Postfix Expression(Enter 0 to use last "
                            "converted Expression):";
                    cin >> temp;
                    if (temp == "0") {
                        ans = evalPostfix(LastInfixExp);
                    } else {
                        ans = evalPostfix(temp);
                    }
                    cout << "Value of expression is " << ans << endl;
                } else {
                    cout << "Enter Postfix Expression:";
                    cin >> temp;
                    ans = evalPostfix(temp);
                    cout << "Value of expression is " << ans << endl;
                }
                break;

            case 4:
                cout << "Thank You!" << endl;
                while_ctrl = false;
                break;

            default:
                cout << "Enter a Valid Choice:" << endl;
                break;
        }
    }

    return 0;
}