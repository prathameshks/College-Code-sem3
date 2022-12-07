#include <iostream>
#define ARR_SIZE 20
using namespace std;

class queue {
   private:
    int arr[ARR_SIZE];
    int front, rear;

   public:
    queue() {
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
        if (rear == ARR_SIZE - 1) {
            return true;
        }
        return false;
    }

    void enqueue(int elmt) {
        if (!isFull()) {
            rear++;
            arr[rear] = elmt;
        }
    }

    void dequeue() {
        if (!isEmpty()) {
            if (front == rear) {
                front = -1;
                rear = -1;
            } else {
                front++;
            }
        }
    }

    void display() {
        for (int i = 0; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    queue que;
    int ch;
    int elmt;
    while (true) {
        cout << "MENU\n1.IS EMPTY\n2. IS FULL\n3.Enqueue\n4.Dequeue\n5.Display\nEnter Choice:";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << que.isEmpty() << endl;
                break;

            case 2:
                cout << que.isFull() << endl;
                break;

            case 3:
                cout << "Enter elmt:";
                cin >> elmt;
                que.enqueue(elmt);
                break;

            case 4:
                que.dequeue();
                break;

            case 5:
                que.display();
                break;

            default:
                break;
        }
    }

end:;
    return 0;
}