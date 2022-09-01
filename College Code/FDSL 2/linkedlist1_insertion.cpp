#include<iostream>
// #include<cstdlib>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};

void print(struct Node *n){ // struct is not necesssary
    while (n!=NULL){
        cout<<n->data<<endl;
        n = n-> next;
    }
}

void insert_initially(struct Node * h){
    int a = 1;
    }

int main(){
    Node *head = NULL; // struct is not necesary no issue if written
    Node *second = NULL;
    Node *third = NULL;
    
    head = new Node();
    second = new Node();
    third = new Node();
    
    head->data = 121;
    head->next = second;
    second->data = 262;
    second->next = third;
    third->data = 343;
    third->next = NULL;
    
    
    Node *newnode1 = NULL;
    newnode1 = new Node();
    // newnode1 = (struct Node*) malloc(sizeof(struct Node)); 
    
    newnode1->data = 4;
    newnode1->next = head;
    
    head = newnode1;
    
    print(head);
    
    return 0;
}
