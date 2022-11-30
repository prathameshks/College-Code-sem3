#include <iostream>
#define MAX 5
using namespace std;

class CircularQueue {
    int front, rear;
    int orders[MAX];

   public:
    CircularQueue() { front = rear = -1; }
    bool addOrder(int data);
    void serveOrder();
    void display();
};

bool CircularQueue::addOrder(int id) {
    if (rear == -1) {
        front = rear = 0;
        orders[rear] = id;
        return true;
    } else {
        int pos = (rear + 1) % MAX;
        if (pos == front) {
            cout << "Cafe is Full.Please wait." << endl;
            return false;
        } else {
            rear = pos;
            orders[rear] = id;
            return true;
        }
    }
}
void CircularQueue::serveOrder() {
    if (front == -1) {
        cout << "No Orders in Cafe.(Cafe is Empty)" << endl;
        return;
    } else {
        cout << "Order No. " << orders[front] << " is processed." << endl;
        if (front == rear)  // only one order
        {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
    }
}
void CircularQueue::display() {
    int i = 0;
    if (front == -1) {
        cout << "Cafe is Empty.No orders." << endl;
        return;
    } else {
        cout << "Order Id's: ";
        for (i = front; i != rear; i = ((i + 1) % MAX)) {
            cout << orders[i] << "  ";
        }
        cout << orders[rear] << endl;
    }
}

int main() {
    int ch, id = 0;
    CircularQueue q;
    do {
        cout << "Menu" << endl;
        cout << "1. Accept order\n";
        cout << "2. Serve order\n";
        cout << "3. Display orders\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                id++;
                if (q.addOrder(id)) {
                    cout << "Thank you for order.Order id is : " << id << endl;
                } else {
                    id--;
                }
                break;
            case 2:
                q.serveOrder();
                break;
            case 3:
                q.display();
                break;
        }
    } while (ch != 4);
    cout << "Thank You.Keep Visiting." << endl;
}
