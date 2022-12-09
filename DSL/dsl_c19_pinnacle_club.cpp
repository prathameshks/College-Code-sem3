#include <iostream>
using namespace std;

// node defination
class node
{
public:
    string prn;
    string name;
    node *next;
    // constructors
    node()
    {
        prn = "";
        name = "";
        next = NULL;
    }
    node(string prn, string name)
    {
        this->prn = prn;
        this->name = name;
        this->next = NULL;
    }
};

// predeclearation of function count
int member_count(node *);

// function to display data
void display_list(node *head)
{
    node *temp = head;

    if (member_count(head) >= 1)
    {
        int count = 1;
        while (temp != NULL)
        {
            cout << count << ". PRN: " << temp->prn;
            cout << " NAME: " << temp->name << endl;
            temp = temp->next;
            count++;
        }
    }
    else
    {
        cout << "Empty List" << endl;
    }
}

// fucntion to add president to list
void add_president(node *&head, string prn, string name)
{
    node *new_president = new node(prn, name);
    new_president->next = head;
    head = new_president;
}

// fucntion to add secretory to list
void add_secretary(node *head, string prn, string name)
{
    node *new_secretary = new node(prn, name);
    node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_secretary;
}

// fucntion to add member to list
void add_member(node *head, string prn, string name)
{
    node *new_member = new node(prn, name);
    node *temp = head;

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    new_member->next = temp->next;
    temp->next = new_member;
}

// fucntion to count number of members
int member_count(node *head)
{
    node *temp = head;
    // temp = temp->next;
    int count = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

// recursive function to display list in reverse order
void display_reverse(node *cur)
{
    if (cur != NULL)
    {
        display_reverse(cur->next);
        cout << "PRN : " << cur->prn;
        cout << " NAME : " << cur->name << endl;
    }
}

// function to concatinate two lists ie 2 to 1 and 2 will be empty
void concatinate(node *head1, node *&head2)
{
    node *temp = new node;
    temp = head1;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head2;
    head2 = NULL;
}

// function to delete president
void delete_president(node *&head)
{
    node *tofree = head;
    head = head->next;
    delete tofree;
}

// function to delete secretory
void delete_secretory(node *head)
{
    node *temp = new node;
    temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    node *tofree = temp->next;
    temp->next = NULL;
    delete tofree;
}

// function to delete member
void delete_member(node *head, string prn)
{
    node *temp = new node;
    temp = head;
    while (temp->next != NULL)
    {
        if (temp->next->prn == prn)
        {
            node *tofree = temp->next;
            temp->next = temp->next->next;
            delete tofree;
        }
        temp = temp->next;
    }
}

// function to swap current list
void swap(node *&l1, node *&l2)
{
    node *temp = l1;
    l1 = l2;
    l2 = temp;
}

// fucntion to initialize the list with president and secretory
node *start(char cur)
{
    string prn, name;
    cout << "Enter Details for Class " << cur << endl;

    cout << "Enter the PRN of President:";
    cin >> prn;
    cout << "Enter the Name of President:";
    cin.ignore();
    getline(cin, name);
    node *list = new node(prn, name);

    cout << "Enter the PRN of Secretory:";
    cin >> prn;
    cout << "Enter the Name of Secretory:";
    cin.ignore();
    getline(cin, name);
    add_secretary(list, prn, name);

    return list;
}

// main function run
int main()
{
    // variables for run control
    char current = 'A';
    string prn, name;
    int choice, choice2;
    bool while_var = true;

    // creating lists
    node *list1 = start('A');
    node *list2 = start('B');

    // loop
    while (while_var)
    {
        cout << "\n----------------------------------" << endl;
        cout << "\tPINNACLE CLUB" << endl;
        cout << " - Current list is Class " << current << endl;
        cout << "1. Display Current List" << endl;
        cout << "2. Add Member" << endl;
        cout << "3. Delete Member" << endl;
        cout << "4. Count Member" << endl;
        cout << "5. Display list in Reverse Order" << endl;
        cout << "6. Switch List" << endl;
        cout << "7. Merge two Lists" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice :";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "\nThe Members of Class " << current << " are as: " << endl;
            display_list(list1);
            break;
        case 2:
            cout << "\n1. Add President" << endl;
            cout << "2. Add Member" << endl;
            cout << "3. Add Secretory" << endl;
            cout << "Enter your choice:";
            cin >> choice2;

            switch (choice2)
            {
            case 1:
                cout << "Enter the PRN of President:";
                cin >> prn;
                cout << "Enter the Name of President:";
                cin.ignore();
                getline(cin, name);
                add_president(list1, prn, name);
                cout << "President added sucessfully to Class " << current << endl;

                break;
            case 2:
                cout << "Enter the PRN:";
                cin >> prn;
                cout << "Enter the Name :";
                cin.ignore();
                getline(cin, name);
                add_member(list1, prn, name);
                cout << "Member added sucessfully to Class " << current << endl;
                break;
            case 3:
                cout << "Enter the PRN of Secretory:";
                cin >> prn;
                cout << "Enter the Name of Secretory:";
                cin.ignore();
                getline(cin, name);
                add_secretary(list1, prn, name);
                cout << "Secretory added sucessfully to Class " << current << endl;
                break;
            default:
                cout << "Enter a valid choice" << endl;
                break;
            }

            break;
        case 3:
            cout << "\n1. Delete President" << endl;
            cout << "2. Delete Member" << endl;
            cout << "3. Delete Secretory" << endl;
            cout << "Enter your choice:";
            cin >> choice2;
            switch (choice2)
            {
            case 1:
                delete_president(list1);
                cout << "President deleted sucessfully from Class " << current << endl;
                break;
            case 2:
                cout << "Enter PRN to delete:";
                cin >> prn;
                delete_member(list1, prn);
                cout << "Member deleted sucessfully from Class " << current << endl;
                break;
            case 3:
                delete_secretory(list1);
                cout << "Secretory deleted sucessfully from Class " << current << endl;
                break;
            default:
                cout << "Enter a valid choice" << endl;

                break;
            }
            break;

        case 4:
            cout << "\nMembers in list " << current << " are " << member_count(list1) << endl;
            break;

        case 5:
            cout << "\nThe Members of Class " << current << " in reverse order are as: " << endl;
            display_reverse(list1);
            break;

        case 6:
            swap(list1, list2);
            if (current == 'A')
                current = 'B';
            else
                current = 'A';
            cout << "\nThe current list is changed sucessfully to class " << current << endl;
            break;

        case 7:
            concatinate(list1, list2);
            cout << "\nThe Members added to Class " << current << " Sucessfully " << endl;
            delete list2;
            list2 = start('B');
            break;

        case 8:
            cout << "\nThank you. " << endl;
            while_var = false;
            break;
        default:
            cout << "Enter a valid choice..." << endl;
            break;
        }
    }
    cin>>choice2;
    return 0;
}