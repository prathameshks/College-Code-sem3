#include <iostream>
#include <cstdlib>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};
// class Node{
//     public:
//     int data;
//     struct Node *next;
// };


void print(Node *h)
{
    Node *temp = new Node();
    temp = h;
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

void insert_start(Node **h, int data1)
{
    Node *newnode = new Node();
    newnode->data = data1;
    newnode->next = (*h);
    (*h) = newnode;
}

void insert_at(Node *h, int index, int data1)
{
    if (index == 0)
    {
        cout << "Can Not insert at index 0." << endl;
    }
    else
    {
        Node *temp = new Node();
        Node *newnode = new Node();
        newnode->data = data1;
        temp = h;
        for (int i = 1; i < index; i++)
        {
            if (temp->next != NULL)
            {
                temp = temp->next;
            }
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void insert_end(Node *h, int data1)
{
    Node *temp = new Node();
    Node *newnode = new Node();
    newnode->data = data1;
    newnode->next = NULL;
    temp = h;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}

void delete_end(Node *h)
{
    Node *temp = new Node();
    temp = h;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    Node *tofree = temp->next;
    temp->next = NULL;
    free(tofree);
}
void delete_at(Node *h, int index)
{
    if (index == 0)
    {
        cout << "Can Not delete at index 0." << endl;
    }
    else
    {
        Node *temp = new Node();
        temp = h;
        for (int i = 1; i < index; i++)
        {
            if (temp->next != NULL)
            {
                temp = temp->next;
            }
        }
        Node *tofree = temp->next;
        temp->next = temp->next->next;
        free(tofree);
    }
}


void delete_head(Node* &head)
{
    Node *tofree = head;
    head = head->next;
    delete tofree;
}

// creating head as global variable to access in functions also
Node *head = new Node();

int main()
{
    head->data = 1001;
    head->next = NULL;
    insert_start(&head, 25);
    insert_end(head, 26);
    insert_at(head, 0, 2);
    insert_at(head, 6, 269);
    cout << "**Displaying List\n";
    print(head);
    delete_head(head);
    cout << "**Displaying List\n";
    print(head);
    // delete_end(head);
    // delete_at(head, 0);
    
    return 0;
}