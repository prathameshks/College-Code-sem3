#include<iostream>
using namespace std;

template<class T>
class Node{
	public:
		T data;
		Node* next;
		Node(T val){
			data = val;
			next = NULL;
		}
};

template<class T>
void print_list(Node<T>* n){
	while (n != NULL){
		cout<<n->data<<" ";
		n=n->next;
	}
	cout<<endl;
}

int main(){
	Node<int> *node1 = new Node<int>(1);
	Node<int> *node2 = new Node<int>(2);
	Node<int> *node3 = new Node<int>(3);
	Node<int> *node4 = new Node<int>(4);
	
	Node<int> *head=node1;
	
	node1->data = 100;
	node1->next = node2;
	node2->data = 101;
	node2->next = node3;
	node3->data = 102;
	node3->next = node4;
	node4->data = 103;
	node4->next = NULL;
	print_list(head);
	return 0;
}
