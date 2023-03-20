/*
Construct an expression tree from the given prefix expression eg. +--a*bc/def
and traverse it using post order traversal (non recursive) and then delete the
entire tree.
*/

#include <iostream>
#include <stack>
#include <map>
// #include <unordered_map>
using namespace std;

class node
{
public:
    char data;
    node *left, *right;
    node()
    {
        left = NULL;
        right = NULL;
    }

    node(char ch)
    {
        data = ch;
        left = NULL;
        right = NULL;
    }
};

class tree
{
private:
    node *root;

    stack<node *> nodestack;

    bool isOperator(char ch)
    {
        switch (ch)
        {
        case '+':
        case '-':
        case '*':
        case '/':
            return 1;
            break;

        default:
            return 0;
            break;
        }
    }

    void insert(char ch)
    {
        if (isOperator(ch))
        {
            node *newnode = new node(ch);
            newnode->left = nodestack.top();
            nodestack.pop();
            newnode->right = nodestack.top();
            nodestack.pop();
            nodestack.push(newnode);
        }
        else
        {
            node *newnode = new node(ch);
            nodestack.push(newnode);
        }
    }

    void postfix(node *temp)
    {
        if (temp != NULL)
        {
            postfix(temp->left);
            postfix(temp->right);
            cout << temp->data;
        }
    }

public:
    void input_prefix(string exp)
    {
        for (int i = exp.length() - 1; i > -1; i--)
        {
            insert(exp[i]);
        }
        root = nodestack.top();
        nodestack.pop();
    }

    void display_postfix()
    {
        cout << "Postfix Expression Is" << endl;
        postfix(root);
        cout << endl;
    }

    void display_postfix_NR()
    {
        node* temp = root;

        stack<node*> stack1, stack2;

        stack1.push(root);

        while (!stack1.empty()) {
            temp = stack1.top();
            stack1.pop();
            stack2.push(temp);
            if (temp->left != NULL) {
                stack1.push(temp->left);
            }
            if (temp->right != NULL) {
                stack1.push(temp->right);
            }
        }
        while (!stack2.empty()) {
            temp = stack2.top();
            stack2.pop();
            cout << temp->data;
        }

        cout<<endl;
    }
};

int main()
{
    tree exp_tree;
    string e = "+--a*bc/def";
    exp_tree.input_prefix(e);
    exp_tree.display_postfix_NR();
    return 0;
}
