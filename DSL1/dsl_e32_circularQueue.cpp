#include <iostream>
#define size 5
using namespace std;

class Queue {
   public:
    int arr[size];
    int f = -1, r = -1;
    bool isempty() { return (f == -1) ? true : false; }

    bool isfull() { return ((r + 1) % size == f) ? true : false; }

    void enqueue(int val) {
        if (isfull()) {
            cout << "Queue is full" << endl;
        } else {
            if (f == -1) {
                f++;
                r++;
                arr[r] = val;
            } else {
                r = (r + 1) % size;
                arr[r] = val;
            }
        }
    }

    void dequeue() {
        if (isempty()) {
            cout << "Queue is empty" << endl;
        } else if (f == r) {
            cout << arr[f] << " has been deleted." << endl;
            f = r = -1;
        } else {
            cout << arr[f] << " has been deleted." << endl;
            f = (f + 1) % size;
        }
    }

    void display() {
        int temp = f;
        if (isempty()) {
            cout << "Order list is empty." << endl;
        } else {
            while (temp != r) {
                cout << arr[temp] << " ";
                temp = (temp + 1) % size;
            }
            cout << arr[temp] << endl;
        }
    }
};

int main() {
    int ch;
    Queue que;
    do {
        cout << "MENU" << endl;
        cout << "1.Add order" << endl;
        cout << "2.Remove order" << endl;
        cout << "3.Display remaining orders" << endl;
        cout << "4.exit" << endl;
        cout << "enter your choice:";
        cin >> ch;
        switch (ch) {
            case 1:
                if (que.isfull()) {
                    cout << "Queue is full" << endl;
                    break;
                }
                int val;
                cout << "Enter element you want to add:";
                cin >> val;
                que.enqueue(val);
                break;
            case 2:
                que.dequeue();
                break;
            case 3:
                que.display();
                break;
            case 4:
                cout << "Thank you" << endl;
                break;
            default:
                cout << "Enter valid choice" << endl;
                break;
        }
    } while (ch != 4);
}