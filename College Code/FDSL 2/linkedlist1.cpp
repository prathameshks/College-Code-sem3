#include<iostream>
using namespace std;

struct node{
    int data;
    struct node* next;
};

void print(struct node *n){ // struct is not necesssary
    while (n!=NULL){
        cout<<n->data<<endl;
        n = n-> next;
    }
}

int main(){
    node *head = NULL; // struct is not necesary no issue if written
    node *second = NULL;
    node *third = NULL;
    
    head = new node();
    second = new node();
    third = new node();
    
    head->data = 121;
    head->next = second;
    second->data = 262;
    second->next = third;
    third->data = 343;
    third->next = NULL;
    
    print(head);
    
    return 0;
}