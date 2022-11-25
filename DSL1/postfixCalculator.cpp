#include <iostream>
#define MAX_ARR_SIZE 30
using namespace std;

class stack {
    int list[MAX_ARR_SIZE];

   public:
    int top;
    stack() {
        top = -1;
    }
    bool isempty() {
        return (top <= -1) ? true : false;
    }
    bool isfull() {
        return (top == MAX_ARR_SIZE - 1) ? true : false;
    }
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
    void dispaly(){
        for (int i = 0; i < top+1; i++)
        {
            cout<<list[i]<<" ";
        }
            cout<<endl;
        
    }
};

void evalPostfix(string exp) {
    int varnum;
    cout << "Enter Number of Variables in Expression:";
    cin >> varnum;
    int varval[26];
    for (int i = 0; i < varnum; i++) {
        cout << "Enter Value for '" << (char)(65 + i) << "':";
        cin >> varval[i];
    }

    int len = exp.size();
    int val1, val2, ans, temp;
    stack values;
    for (int i = 0; i < len; i++) {
        cout<<exp[i]<<endl;
        values.dispaly();
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
            cout<<"Push "<<int(exp[i] - 65);
                values.push(varval[int(exp[i]-65)]);
                break;
        }
    }
    cout << values.pop() << endl;
}

int main() {
    // evalPostfix("AB*CD/-E+"); //wrong A*B-C/D+E
    evalPostfix("AB*CD/E+-");
    return 0;
}
//5 2 3 9 3 5