/*
Second year Computer Engineering class, set A of students like Vanilla Ice-cream and set
B of students like butterscotch ice-cream. Write C++ program to store two sets using
linked list. compute and display
a) Set of students who like both vanilla and butterscotch
b) Set of students who like either vanilla or butterscotch or not both
c) Number of students who like neither vanilla nor butterscotch
*/
#include <iostream>
using namespace std;

// creating node
class node
{
public:
    int data;
    node *next;
    node()
    {
        next = NULL;
        // data = NULL;
    }
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

int find_set(node *head, int elmt)
{
    node *temp = new node;
    temp = head;
    int index = 0;
    while (temp != NULL)
    {
        if (temp->data == elmt)
        {
            return index;
        }
        index++;
        temp = temp->next;
    }
    return -1;
}

void delete_set(node *&head, int elmt)
{
    node *temp = new node();
    temp = head;
    if (temp->data == elmt)
    {
        if (temp->next == NULL)
        {
            delete head;
            return;
        }
        else
        {
            node *tofree = temp;
            head = temp->next;
            delete tofree;
        }
    }
    else
    {
        while (temp->next != NULL)
        {
            if (temp->next->next == NULL)
            {
                node *current = temp->next;
                if (current->data == elmt)
                {
                    temp->next = current->next;
                    delete current;
                }
                return;
            }
            else
            {
                node *current = temp->next;
                if (current->data == elmt)
                {
                    temp->next = current->next;
                    delete current;
                }
                temp = temp->next;
            }
        }
    }
}

void add_set(node *&head, int elmt)
{
    if (find_set(head, elmt) == -1)
    {
        node *temp = new node();
        temp = head;
        node *newnode = new node(elmt);
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void print_set(node *head)
{
    node *temp = new node;
    temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void delete_index(node *&head, int index)
{
    if (index <= -1)
    {
        return;
    }
    else if (index == 0 and head->next != NULL)
    {
        node *tofree = head;
        head = head->next;
        delete tofree;
    }
    else
    {
        node *temp = new node;
        temp = head;
        for (int i = 0; i < index - 1; i++)
        {
            temp = temp->next;
        }
        node *tofree = temp->next;
        temp->next = temp->next->next;
        delete tofree;
    }
}

void get_set(node *&head, string flv)
{
    int n, roll;
    cout << "Enter Number of students who like " << flv << ":";
    cin >> n;
    cout << "Enter roll numbers:" << endl;
    cin >> roll;
    head = new node(roll);
    for (int i = 1; i < n; i++)
    {
        cin >> roll;
        add_set(head, roll);
    }
}
void set_only_one(node *set1, node *set2)
{
    node *temp = new node;
    temp = set1;
    while (temp != NULL)
    {
        if (find_set(set2, temp->data) == -1)
        {
            cout << temp->data << " ";
        }
        temp = temp->next;
    }
    node *temp2 = new node;
    temp2 = set2;
    while (temp2 != NULL)
    {
        if (find_set(set1, temp2->data) == -1)
        {
            cout << temp2->data << " ";
        }
        temp2 = temp2->next;
    }
    cout << endl;
}

void set_intersection(node *set1, node *set2)
{
    node *temp = new node;
    temp = set1;
    while (temp != NULL)
    {
        if (find_set(set2, temp->data) != -1)
        {
            cout << temp->data << " ";
        }
        temp = temp->next;
    }
    cout << endl;
}

int nothing(node *set1, node *set2, int total)
{
    int count = 0;
    for (int i = 1; i <= total; i++)
    {
        if ((find_set(set1, i) == -1) and (find_set(set2, i) == -1))
        {
            count++;
        }
    }
    return count;
}

int main()
{
    node *seta;
    node *setb;
    int choice, total;
    bool while_var = true;
    cout << "Enter Total number of students :";
    cin >> total;
    get_set(seta, "Vanilla");
    get_set(setb, "Butterscotch");
    while (while_var)
    {
        cout << "-- MENU --" << endl;
        cout << "1. Display both Lists" << endl;
        cout << "2. Reset Student who like vanilla" << endl;
        cout << "3. Reset Student who like Butterscotch" << endl;
        cout << "4. Set of Student who like both vanilla and butterscotch" << endl;
        cout << "5. Set of Student who like either vanilla and butterscotch, not both" << endl;
        cout << "6. Number of Student who like neither vanilla nor butterscotch" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your Choice:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Students who like vanilla are ";
            print_set(seta);
            cout << "Students who like Butterscotch are ";
            print_set(setb);
            break;

        case 2:
            get_set(seta, "Vanilla");

            break;

        case 3:
            get_set(setb, "Butterscotch");

            break;

        case 4:
            cout << "Set of Student who like both vanilla and butterscotch are " << endl;
            set_intersection(seta, setb);
            break;

        case 5:
            cout << "Set of Student who like either vanilla and butterscotch, not both" << endl;
            set_only_one(seta, setb);

            break;

        case 6:
            cout << "Number of Student who like neither are " << nothing(seta, setb, total) << endl;
            break;

        case 7:
            while_var = false;
            break;

        default:
            cout << "Enter a valid choice." << endl;
            break;
        }
    }
    return 0;
}

/*
    node *head = new node(1);
    // head->next = new node(2);
    // head->next->next = new node(3);
    // head->next->next->next = new node(4);
    add_set(head,2);

    cout << "Check 1" << endl;
    print_set(head);

    add_set(head,2);
    // delete_set(head, 1);
    // delete_index(head,2);
    // int i = find_set(head,12);
    // delete_index(head,i);

    cout << "Check 2" << endl;
    print_set(head);

*/