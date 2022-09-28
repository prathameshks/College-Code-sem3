#include <iostream>
using namespace std;

class node
{
public:
    string prn;
    string name;
    node *next;
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

void display_data(node *head)
{
    node *temp = head;
    if (head != NULL)
    {
        cout << "President\nPRN: " << temp->prn;
        cout << " NAME: " << temp->name << endl;
        temp = temp->next;
        int count = 1;
        cout << "Members " << endl;
        while (temp->next != NULL)
        {
            cout << count << ". PRN: " << temp->prn;
            cout << " NAME: " << temp->name << endl;
            temp = temp->next;
            count++;
        }
        cout << "Secretary\nPRN: " << temp->prn;
        cout << " NAME: " << temp->name << endl;
    }else{
        cout<<"Empty List"<<endl;
    }
}

void add_president(node *&head, string prn, string name)
{
    node *new_president = new node(prn, name);
    new_president->next = head;
    head = new_president;
}

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

int member_count(node *head)
{
    node *temp = head;
    temp = temp->next;
    int count = 1;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

void display_reverse(node *cur)
{
    if (cur != NULL)
    {
        display_reverse(cur->next);
        cout << "PRN : " << cur->prn;
        cout << " NAME : " << cur->name << endl;
    }
}

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

void delete_president(node*&head){
    node * tofree = head;
    head = head->next;
    delete tofree;
}

void delete_secretory(node *head){
    node*temp = new node;
    temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    node *tofree = temp->next;
    temp->next = NULL;
    delete tofree;
}

void delete_member_prn(node *head,string prn){
    node* temp = new node;
    temp = head;
    while(temp->next != NULL){
        if (temp->next->prn == prn){
            node * tofree = temp->next;
            temp->next = temp->next->next;
            delete tofree;
        }
        temp = temp->next;
    }
}

void delete_member_name(node *head,string name){
    node* temp = new node;
    temp = head;
    while(temp->next != NULL){
        if (temp->next->name == name){
            node * tofree = temp->next;
            temp->next = temp->next->next;
            delete tofree;
        }
        temp = temp->next;
    }
}

int main()
{
    int choice;
    bool while_var = true;
    while(while_var){
        cout<<"---PINNACLE CLUB---"<<endl;
        cout<<"1. Add President in Class A"<<endl;
        cout<<"2. Add Secretary in Class A"<<endl;
        cout<<"3. Add Member in Class A"<<endl;
        cout<<"1. Delete President in Class A"<<endl;
        cout<<"2. Delete Secretary in Class A"<<endl;
        cout<<"3. Delete Member in Class A"<<endl;
        cout<<"4. Add President in Class B"<<endl;
        cout<<"5. Add Secretary in Class B"<<endl;
        cout<<"6. Add Member in Class B"<<endl;
        cout<<"1. Delete President in Class B"<<endl;
        cout<<"2. Delete Secretary in Class B"<<endl;
        cout<<"3. Delete Member in Class B"<<endl;
        cout<<"7. Merge two classes"<<endl;
        break;
    }
    return 0;
}


/*

    node *head = new node("AP", "A President");
    add_secretary(head, "AS", "A sece");
    add_member(head, "A 1", "A per1");
    add_member(head, "A 2", "A per2");
    add_member(head, "A 3", "A per23");
    add_member(head, "A 4", "A per2");
    display_data(head);
    delete_member_name(head,"A per2");
    display_data(head);


    node *head = new node("AP", "A President");
    add_secretary(head, "AS", "A sece");
    add_member(head, "A 1", "A per1");
    add_member(head, "A 2", "A per2");
    node *head2 = new node("BP", "B President");
    add_secretary(head2, "BS", "B sece");
    add_member(head2, "B 1", "B per1");
    add_member(head2, "B 2", "B per2");
    cout << "**1 HEAD " << endl;
    display_data(head);
    cout << "**1 HEAD2 " << endl;
    display_data(head2);
    concatinate(head, head2);
    cout << "**2 HEAD " << endl;
    display_data(head);
    cout << "**2 HEAD2 " << endl;
    display_data(head2);
*/