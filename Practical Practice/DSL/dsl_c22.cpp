/*
Second year Computer Engineering class, set A of students like Vanilla Ice-cream
and set B of students like butterscotch ice-cream. Write C++ program to store
two sets using linked list. compute and display-
a) Set of students who like both vanilla and butterscotch
b) Set of students who like either vanilla or butterscotch or not both
c) Number of students who like neither vanilla nor butterscotch
*/
#include <iostream>

using namespace std;

class node {
   public:
    int rollno;
    node *next;

    node() { next = NULL; }

    node(int rollno) {
        this->rollno = rollno;
        next = NULL;
    }
};

bool find(node *list, int roll) {
    node *temp = new node();
    temp = list;
    while (temp != NULL) {
        if (temp->rollno == roll) {
            return true;
        }

        temp = temp->next;
    }
    return false;
}

void both(node *list1, node *list2) {
    node *temp = new node();
    temp = list1;
    bool flag = true;
    while (temp != NULL) {
        if (find(list2, temp->rollno)) {
            cout << temp->rollno << " ";
            flag = false;
        }
        temp = temp->next;
    }
    if (flag) {
        cout << "No such student found";
    }
    cout << endl;
}

void notboth(node *list1, node *list2) {
    node *temp = new node();
    temp = list1;
    bool flag = true;
    while (temp != NULL) {
        if (!find(list2, temp->rollno)) {
            cout << temp->rollno << " ";
            flag = false;
        }
        temp = temp->next;
    }
    temp = list2;
    while (temp != NULL) {
        if (!find(list1, temp->rollno)) {
            cout << temp->rollno << " ";
            flag = false;
        }
        temp = temp->next;
    }
    if (flag) {
        cout << "No such student found";
    }
    cout << endl;
}

int count_any(node *list1, node *list2) {
    node *temp = new node();
    temp = list1;
    int count = 0;
    while (temp != NULL) {
        temp = temp->next;
        count++;
    }
    temp = list2;
    while (temp != NULL) {
        if (!find(list1, temp->rollno)) {
            count++;
        }
        temp = temp->next;
    }
    return count;
}

void add_list(node *&head, int roll) {
    if (head == NULL) {
        head = new node(roll);
        return;
    }
    node *temp = new node();
    temp = head;
    while (temp->next != NULL) {
        if (temp->rollno == roll) {
            return;
        }
        temp = temp->next;
    }
    temp->next = new node(roll);
}

node *set_list() {
    node *head = NULL;
    int count, roll;
    cout << "Enter number of students to add:";
    cin >> count;
    for (int i = 0; i < count; i++) {
        cout << "Enter roll no:";
        cin >> roll;
        add_list(head, roll);
    }
    return head;
}

int main() {
    int choice, count;
    int total;
    cout << "Enter total Number of student in the class:";
    cin >> total;

    cout << "Set Vanilla List" << endl;
    node *vanilla = set_list();
    cout << "Set Buttescotch List" << endl;
    node *butterscotch = set_list();

    do {
        cout << "1.Reset Vanilla list" << endl;
        cout << "2.Reset Butterscotch list" << endl;
        cout << "3.Set of students who like both vanilla and butterscotch"
             << endl;
        cout << "4.Set of students who like either vanilla or butterscotch not "
                "both"
             << endl;
        cout << "5.Number of students who like neither vanilla nor butterscotch"
             << endl;
        cout << "0 to Exit" << endl;
        cout << "\nEnter Your Choice:" << endl;
        cin >> choice;
        switch (choice) {
            case 1:
                vanilla = set_list();
                break;

            case 2:
                butterscotch = set_list();
                break;

            case 3:
                both(vanilla, butterscotch);
                break;

            case 4:
                notboth(vanilla, butterscotch);
                break;

            case 5:
                count = count_any(vanilla, butterscotch);
                cout << "Number of students is " << total - count << endl;
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