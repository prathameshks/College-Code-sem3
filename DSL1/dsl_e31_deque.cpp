/*
Queues are frequently used in computer programming, and a typical example is the
creation of a job queue by an operating system. If the operating system does not
use priorities, then the jobs are processed in the order they enter the system.
Write C++ program for simulating job queue. Write functions to add job and
delete job from queue.
*/

#include <iostream>
#define ARR_SIZE 5
using namespace std;

class deque {
   private:
    int arr[ARR_SIZE];
    int front, rear;

   public:
    deque();
    bool isEmpty();
    bool isFull_front();
    bool isFull_back();
    void enqueue_front(int elmt);
    int dequeue_front();
    void enqueue_back(int elmt);
    int dequeue_back();
    void display();
};

deque::deque() {
    front = -1;
    rear = -1;
}

bool deque::isEmpty() {
    if (front == -1 && rear == -1) {
        return true;
    }
    return false;
}

bool deque::isFull_front() {
    if (front == 0) {
        return true;
    }
    return false;
}
bool deque::isFull_back() {
    if (rear == ARR_SIZE - 1) {
        return true;
    }
    return false;
}

void deque::enqueue_front(int elmt) {
    if (isEmpty())
    {
        front++;
        rear++;
        arr[front] = elmt;
    }else if (!isFull_front()) {
        front--;
        arr[front] = elmt;
    }
}

int deque::dequeue_front() {
    int elmt = 0;
    if (!isEmpty()) {
        elmt = arr[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front++;
        }
    }
    return elmt;
}
void deque::enqueue_back(int elmt) {
    if (!isFull_back()) {
        rear++;
        arr[rear] = elmt;
    }
}

int deque::dequeue_back() {
    int elmt = 0;
    if (!isEmpty()) {
        elmt = arr[rear];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            rear--;
        }
    }
    return elmt;
}

void deque::display() {
    for (int i = front; i <= rear; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    deque que;
    int ch;
    int elmt;
    do {
        cout << "MENU\n1. Enqueue Front\n2. Elynqueue Back\n3. Dequeue Front "
                "\n4. Dequeue Back\n5. Display Queue\n6. Exit\nEnter Choice:";
        cin >> ch;
        switch (ch) {
            case 1:
                if (que.isFull_front()) {
                    cout << "Queue Overflow" << endl;
                    break;
                }
                cout << "Enter Element:";
                cin >> elmt;
                que.enqueue_front(elmt);
                break;
            case 2:
                if (que.isFull_back()) {
                    cout << "Queue Overflow" << endl;
                    break;
                }
                cout << "Enter Element:";
                cin >> elmt;
                que.enqueue_back(elmt);
                break;

            case 3:
                if (que.isEmpty()) {
                    cout << "Queue Underflow" << endl;
                    break;
                }
                cout << "Deleted element :" << que.dequeue_front() << endl;
                break;
            case 4:
                if (que.isEmpty()) {
                    cout << "Queue Underflow" << endl;
                    break;
                }
                cout << "Deleted element :" << que.dequeue_back() << endl;
                break;

            case 5:
                if (que.isEmpty()) {
                    cout << "Queue Is Empty" << endl;
                    break;
                }
                cout << "Deque is : ";
                que.display();
                break;

            case 6:
                cout << "Thank You" << endl;
                break;

            default:
                cout << "Enter a valid Choice" << endl;
                break;
        }
    } while (ch != 6);

    return 0;
}
