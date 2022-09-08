#include<iostream>
#include<cstdlib>
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

struct Node* insert_start(struct Node * h,int element){
    Node *newnode1 = NULL;
    newnode1 = new Node();
    // newnode1 = (struct Node*) malloc(sizeof(struct Node)); 
    
    newnode1->data = element;
    newnode1->next = h;
    return newnode1;
}

void insert_end(struct Node * h,int value){
    Node *temp = h;
    Node *newnode = new Node();
    newnode->data = value;
    newnode->next = NULL;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newnode;
}

void insert_at(struct Node * h,int index,int value){
    Node *temp = NULL;
    temp = h;
    Node *newnode = new Node();
    newnode->data = value;
    newnode->next = NULL;
    for (int i = 1;i<index;i++){
        temp = temp->next;
    }
    
    newnode->next = temp->next;
    temp->next = newnode;
}



void delete_end(Node *h){
    Node *temp = NULL;
    temp = h;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    Node *tofree = temp->next;
    temp->next = NULL;
    free(tofree);
}

void delete_at(Node *h,int index){
    Node *temp = NULL;
    temp = h;
    for (int i = 1;i<index;i++){
        if(temp->next!=NULL){
            temp = temp->next;
        }
    }
    Node *tofree = temp->next;
    temp->next = temp->next->next;
    free(tofree);
}

int main(){
    Node *head = NULL; // struct is not necesary no issue if written
        
    head = new Node();
    
    head->data = 1;
    insert_end(head,2);
    insert_end(head,3);
    insert_end(head,5);
    cout<<"**initially"<<endl;
    print(head);
    
    head = insert_start(head,0);
    insert_at(head,4,45);
    
    
    cout<<"**after insertion"<<endl;
    print(head);
    
    /*
    //delete_at_beginning
    head = head->next;
      
    print(head);
    
    
    //delete_end(head);
    
    delete_in_between(head,3);
    
    cout<<"**deleted index 3"<<endl;
    print(head);
    */
    return 0;
}



/*
            *
1   6   7   8   9   2   3   4

*/
