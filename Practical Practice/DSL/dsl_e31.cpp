/*
A double-ended queue (deque) is a linear list in which additions and deletions
may be made at either end. Obtain a data representation mapping a deque into a
one- dimensional array. Write C++ program to simulate deque with functions to
add and delete elements from either end of the deque.
*/

#include <iostream>
#define MAX_SIZE 20
using namespace std;

class deque {
    int list[MAX_SIZE];
    int front, rear;

   public:
    deque() {
        front = -1;
        rear = -1;
    }

    bool isempty() {
        if (rear == -1 && front == -1) {
            return true;
        }
        return false;
    }

    bool isfullfront() {
        if (front == 0) {
            return true;
        }
        return false;
    }
    bool isfullback() {
        if (rear == MAX_SIZE - 1) {
            return true;
        }
        return false;
    }

    void enque_front(int val) {
        if (!isfullfront()) {
            if (isempty()) {
                front = 0;
                rear = 0;
            } else {
                front--;
            }
            list[front] = val;
        }
    }

    void enque_back(int val) {
        if (!isfullback()) {
            if (isempty()) {
                front = 0;
                rear = 0;
            } else {
                rear++;
            }
            list[rear] = val;
        }
    }

    void deque_front() {
        if (!isempty()) {
            if (rear == 0) {
                front = -1;
                rear = -1;
            } else {
                front++;
            }
        }
    }

    void deque_back() {
        if (!isempty()) {
            if (rear == 0) {
                front = -1;
                rear = -1;
            } else {
                rear--;
            }
        }
    }

    int peek_front() {
        if (!isempty()) {
            return list[front];
        }
    }

    int peek_back() {
        if (!isempty()) {
            return list[rear];
        }
    }

    void display_queue() {
        if (!isempty()) {
            cout << "Dequeue is :" << endl;
            for (int i = front; i < rear; i++) {
                cout << list[i] << ",";
            }
            cout << list[rear] << endl;
        } else
            cout << "No Elements present." << endl;
    }
};

int main() {
    int ch, temp;
    deque que;
    do {
        cout << "1. Add front" << endl;
        cout << "2. Add back" << endl;
        cout << "3. Delete front" << endl;
        cout << "4. Delete back" << endl;
        cout << "5. Display Queue" << endl;
        cout << "0 to exit" << endl;

        cout << "Enter choice:";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter :";
                cin >> temp;
                que.enque_front(temp);
                break;
            case 2:
                cout << "Enter :";
                cin >> temp;
                que.enque_back(temp);
                break;

            case 3:
                cout << "Element :" << que.peek_front() << endl;
                que.deque_front();
                break;

            case 4:
                cout << "Element :" << que.peek_back() << endl;
                que.deque_back();
                break;

            case 5:
                que.display_queue();
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
