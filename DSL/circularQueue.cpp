#include <iostream>
#define MAX_ARR_SIZE 5
using namespace std;

class cqueue {
    int front, rear;
    int arr[MAX_ARR_SIZE];

    public:
    cqueue() {
        front = -1;
        rear = -1;
    }
    bool isEmpty() {
        if (front == -1 && rear == -1) {
            return true;
        }
        return false;
    }
    bool isFull() {
        if ((rear % MAX_ARR_SIZE) +1 == front) {
            return true;
        }
        return false;
    }
    void enqueue(int elmt){
        if (isEmpty())
        {
            front++;
        }
        
        if (!isFull())
        {
            rear++;
            arr[rear]=elmt;
        }
        
    }
    void dequeue(){
        if (!isEmpty())
        {
            if (rear == front)
            {
                front = -1;
                rear = -1;
            }else
            {
                front++;
            }
            
            
        }
        
    }
};

int main() {//incomplete
    cqueue que;
    cout<<que.isEmpty();
    cout<<que.isFull();
    return 0;
}