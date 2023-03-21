/*
A double-ended queue (deque) is a linear list in which additions and deletions
may be made at either end. Obtain a data representation mapping a deque into a
one- dimensional array. Write C++ program to simulate deque with functions to
add and delete elements from either end of the deque.
*/

#include <iostream>
#define MAX_SIZE 20
using namespace std;

class circularQueue {
    int list[MAX_SIZE];
    int front, rear;

   public:
    circularQueue() {
        front = -1;
        rear = -1;
    }

    bool isempty() {
        if (rear == -1 && front == -1) {
            return true;
        }
        return false;
    }

    bool isfull() {
        if ((rear + 1) % MAX_SIZE == front) {
            return true;
        }
        return false;
    }

    void enque(int val) {
        if (!isfull()) {
            if (front == -1)
            {
                front = 0;
            }
            
            rear = (rear + 1) % MAX_SIZE;
            list[rear] = val;
        }
    }

    void deque() {
        if (!isempty()) {
            if ((front + 1) % MAX_SIZE == rear) {
                front = -1;
                rear = -1;
            } else {
                front = (front + 1) % MAX_SIZE;
            }
        }
    }

    int peek() {
        if (!isempty()) {
            return list[front];
        }
    }

    void display() {
        int f = front;
        if (!isempty()) {
            cout << "Jobs Pending are:" << endl;
            do
            {
                cout << list[f] << " ";
                // f++;
            } while ((f++) % MAX_SIZE != rear);
            
            // while ((f++) % MAX_SIZE != rear) {
            //     cout << list[f] << ",";
            // }
            // cout << list[f] << "\n";

        } else
            cout << "NO Jobs Pending." << endl;
    }
};

int main() {
    int ch, temp;
    circularQueue que;
    do {
        cout << "1. Add Job" << endl;
        cout << "2. Delete Job" << endl;
        cout << "3. Display Job" << endl;
        cout << "0 to exit" << endl;

        cout << "Enter choice:";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter job ID to add:";
                cin >> temp;
                que.enque(temp);
                break;

            case 2:
                que.deque();
                break;

            case 3:
                que.display();
                break;
            case 0:
                cout << "THank you" << endl;
                break;
            default:
                cout << "Enter valid choice" << endl;
                break;
        }

    } while (ch != 0);

    return 0;
}
