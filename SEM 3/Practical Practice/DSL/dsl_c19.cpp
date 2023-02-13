/*
Department of Computer Engineering has student's club named 'Pinnacle Club'.
Students of second, third and final year of department can be granted membership
on request. Similarly one may cancel the membership of club. First node is
reserved for president of club and last node is reserved for secretary of club.
Write C++ program to maintain club member's information using singly linked
list. Store student PRN and Name. Write functions to:
a)Add and delete the members as well as president or even secretary.
b)Compute total number of members of club
c)Display members
d)Two linked lists exists for two divisions. Concatenate two lists.
*/
#include <iostream>

using namespace std;

class node {
   public:
    int prn;
    string name;
    node *next;

    node() { next = NULL; }

    node(int prn, string name) {
        this->prn = prn;
        this->name = name;
    }
};

void add_president(node *&head) {
    int prn;
    string name;
    cout << "Enter PRN of New President:";
    cin >> prn;

    cout << "Enter Name of New President:";
    cin >> name;

    node *newnode = new node(prn, name);
    newnode->next = head;
    head = newnode;
    cout << "New President added sucessfully" << endl;
}

void add_secretary(node *&head) {
    int prn;
    string name;
    cout << "Enter PRN of New Secretary:";
    cin >> prn;

    cout << "Enter Name of New Secretary:";
    cin >> name;

    node *newnode = new node(prn, name);

    if (head == NULL) {
        head = newnode;
        return;
    }

    node *temp = new node;
    temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
    cout << "New Secretary added sucessfully" << endl;
}

void add_member(node *&head) {
    int prn;
    string name;
    cout << "Enter PRN of New Member:";
    cin >> prn;

    cout << "Enter Name of New Member:";
    cin >> name;

    node *newnode = new node(prn, name);

    if (head == NULL) {
        head = newnode;
        cout << "New Member added sucessfully" << endl;
        return;
    }

    newnode->next = head->next;
    head->next = newnode;
    cout << "New Member added sucessfully" << endl;
}

void delete_president(node *&head) {
    if ((head == NULL) || (head->next == NULL)) {
        head = NULL;
        cout << "No President to Delete" << endl;
        return;
    }
    node *todelete = head;
    head = head->next;
    delete todelete;
    cout << "President Deleted Sucessfully" << endl;
}

void delete_secretary(node *&head) {
    if ((head == NULL) || (head->next == NULL)) {
        head = NULL;
        cout << "No Secretary to Delete" << endl;
        return;
    }

    node *temp = new node();
    node *prev = new node();

    prev = head;
    temp = head->next;

    while (temp->next != NULL) {
        temp = temp->next;
        prev = prev->next;
    }

    prev->next = NULL;

    delete temp;
    cout << "Secretary Deleted Sucessfully" << endl;
}

void delete_member(node *&head) {
    if (head == NULL) {
        cout << "No Member to Delete" << endl;
        return;
    }
    int prn;
    cout << "Enter PRN to Delete:";
    cin >> prn;

    if (head->prn == prn) {
        delete_president(head);
        return;
    }

    node *temp = new node();
    node *prev = new node();

    prev = head;
    temp = head->next;

    while (temp->next != NULL) {
        if (temp->prn == prn) {
            prev->next = temp->next;
            delete temp;
            cout << "Member Deleted Sucessfully" << endl;
            return;
        }
        temp = temp->next;
        prev = prev->next;
    }
    cout << "Member not found" << endl;
}

int count_members(node *&head) {
    if (head == NULL) {
        return 0;
    }
    node *temp = new node();
    temp = head;
    int count = 0;
    while (temp != NULL) {
        temp = temp->next;
        count++;
    }
    if (count <= 2) {
        return 0;
    }

    return count - 2;
}

void display_members(node *&head) {
    if (head == NULL) {
        cout << "No member to display" << endl;
        return;
    }
    node *temp = new node();
    temp = head;
    int count = 1;
    while (temp->next != NULL) {
        cout << count << ". PRN:" << temp->prn << " Name:" << temp->name
             << endl;
        count++;
        temp = temp->next;
    }
    if (count == 1) {
        cout << "No member to display" << endl;
    }
}

void display_heads(node *&head) {
    if (head == NULL) {
        cout << "No President and Secretary to display" << endl;
        return;
    }
    cout << "President :" << endl;
    cout << "PRN : " << head->prn << endl;
    cout << "Name : " << head->name << endl;
    if (head->next == NULL) {
        cout << "No Secretary to display" << endl;
        return;
    }

    node *temp = new node();
    temp = head->next;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    cout << "Secretary :" << endl;
    cout << "PRN : " << temp->prn << endl;
    cout << "Name : " << temp->name << endl;
}

void concatinate(node *&list1, node *&list2) {
    if (list1 == NULL) {
        list1 = list2;
        list2 = NULL;
        return;
    }
    if (list2 == NULL) {
        return;
    }

    node *temp = new node();
    temp = list1;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = list2;
    list2 = NULL;
}

int main() {
    int choice, count;

    node *list1 = NULL;
    node *list2 = NULL;

    do {
        cout << "1.Add President to list1" << endl;
        cout << "2.Add Secretary to list1" << endl;
        cout << "3.Add Member to list1" << endl;
        cout << "4.Delete President of list1" << endl;
        cout << "5.Delete Secretary of list1" << endl;
        cout << "6.Delete Member of list1" << endl;
        cout << "7.Count of Members in list1" << endl;
        cout << "8.Display list1" << endl;
        cout << "9.Add President to list2" << endl;
        cout << "10.Add Secretary to list2" << endl;
        cout << "11.Add Member to list2" << endl;
        cout << "12.Delete President of list2" << endl;
        cout << "13.Delete Secretary of list2" << endl;
        cout << "14.Delete Member of list2" << endl;
        cout << "15.Count of Members in list2" << endl;
        cout << "16.Display list2" << endl;
        cout << "17.Merge Lists" << endl;
        cout << "0 to Exit" << endl;
        cout << "\nEnter Your Choice:" << endl;
        cin >> choice;
        switch (choice) {
            case 1:
                add_president(list1);
                break;

            case 2:
                add_secretary(list1);
                break;

            case 3:
                add_member(list1);
                break;

            case 4:
                delete_president(list1);
                break;

            case 5:
                delete_secretary(list1);
                break;

            case 6:
                delete_member(list1);
                break;

            case 7:
                count = count_members(list1);
                if (count == 0) {
                    cout << "No member present" << endl;
                } else {
                    cout << "Member count is " << count << endl;
                }
                break;

            case 8:
                display_heads(list1);
                display_members(list1);
                break;
                
            case 9:
                add_president(list2);
                break;

            case 10:
                add_secretary(list2);
                break;

            case 11:
                add_member(list2);
                break;

            case 12:
                delete_president(list2);
                break;

            case 13:
                delete_secretary(list2);
                break;

            case 14:
                delete_member(list2);
                break;

            case 15:
                count = count_members(list2);
                if (count == 0) {
                    cout << "No member present" << endl;
                } else {
                    cout << "Member count is " << count << endl;
                }
                break;

            case 16:
                display_heads(list2);
                display_members(list2);
                break;

            case 17:
                concatinate(list1, list2);
                cout << "Lists merged" << endl;
                break;

            case 0:
                cout << "Thank You" << endl;
                break;

            default:
                cout << "Enter a valid Choice" << endl;
                break;
        }

    } while (choice != 0);

    return 0;
}