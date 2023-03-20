/*
Construct an expression tree from the given prefix expression eg. +--a*bc/def
and traverse it using post order traversal (non recursive) and then delete the
entire tree.
*/

/*

=================
|| NOT WORKING ||
=================

*/

#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

class node {
   public:
    char data;
    node* right;
    node* left;
    node() {
        right = NULL;
        left = NULL;
    }
    node(char data) {
        right = NULL;
        left = NULL;
        this->data = data;
    }
};

class stackNode {
   public:
    node* data;
    stackNode* next;
};

class stack {
    stackNode* top;

   public:
    stack() { top = NULL; }
    bool isempty() { return (top == NULL); }
    void push(node* val) {
        if (top == NULL) {
            top = new stackNode();
            top->data = val;
        } else {
            stackNode* newnode = new stackNode();
            newnode->data = val;
            newnode->next = top;
            top = newnode;
        }
    }
    node* pop() {
        if (top == NULL) {
            return NULL;
        } else {
            node* temp = top->data;
            top = top->next;
            return temp;
        }
    }
};

class ExpressionTree {
    node* root;

    stack nodestack;

    bool isOperator(char op) {
        switch (op) {
            case '+':
            case '-':
            case '*':
            case '/':
                return true;
            default:
                return false;
        }
    }

   public:
    ExpressionTree() { root = NULL; }

    void insert(char ch) {
        if (isOperator(ch)) {
            node* temp = new node(ch);
            temp->left = nodestack.pop();
            temp->right = nodestack.pop();
            nodestack.push(temp);
        } else {
            node* temp = new node(ch);
            nodestack.push(temp);
        }
    }

    void input_prefix(string exp) {
        for (int i = exp.length() - 1; i >= -1; i--) {
            insert(exp[i]);
        }
        root = nodestack.pop();
    }

    void postfix_exp() {
        node* temp = root;

        stack stack1, stack2;

        stack1.push(root);

        while (!stack1.isempty()) {
            temp = stack1.pop();
            stack2.push(temp);
            if (temp->left != NULL) {
                stack1.push(temp->left);
            }
            if (temp->right != NULL) {
                stack1.push(temp->right);
            }
        }
        while (!stack2.isempty()) {
            temp = stack2.pop();
            cout << temp->data;
        }

        cout << endl;
    }

    void display_postfix() {
        cout << "Postfix Expression is ";
        postfix(root);
        cout << endl;
    }
    void postfix(node* cur) {
        if (cur != NULL) {
            postfix(cur->left);
            postfix(cur->right);
            cout << cur->data;
        }
    }
};

int main() {
    string st;
    ExpressionTree tree;
    // cout << "Enter prefix expression:";
    // cin >> st;
    st = "+--a*bc/def";

    tree.input_prefix(st);
    tree.display_postfix();
    // tree.postfix_exp();

    return 0;
}
