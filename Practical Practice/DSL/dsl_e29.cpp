/*
Queues are frequently used in computer programming, and a typical example is the
creation of a job queue by an operating system. If the operating system does not
use priorities, then the jobs are processed in the order they enter the system.
Write C++ program for simulating job queue. Write functions to add job and
delete job from queue.
*/

#include <iostream>
#define MAX_SIZE 20
using namespace std;

class job_queue {
    int jobs[MAX_SIZE];
    int front, rear;

   public:
    job_queue() {
        front = -1;
        rear = -1;
    }

    bool isempty() {
        if (rear == -1) {
            return true;
        }
        return false;
    }

    bool isfull() {
        if (rear == MAX_SIZE - 1) {
            return true;
        }
        return false;
    }

    void add_job(int val) {
        if (!isfull()) {
            if (front == -1) {
                front = 0;
                rear = 0;
            } else {
                rear++;
            }
            jobs[rear] = val;
        }
    }
    void delete_job() {
        if (!isempty()) {
            cout << "Job processed with ID:";

            if (rear == 0) {
                front = -1;
                rear = -1;
                cout << jobs[0] << endl;
            } else {
                front++;
                cout << jobs[front - 1] << endl;
            }
        } else
            cout << "NO job to process" << endl;
    }
    void display_job() {
        if (!isempty()) {
            cout << "Jobs Pending are:" << endl;
            for (int i = front; i < rear; i++) {
                cout << jobs[i] << ",";
            }
            cout << jobs[rear] << endl;
        }
        cout << "NO Jobs Pending." << endl;
    }
};

int main() {
    int ch, job_id;
    job_queue que;
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
                cin >> job_id;
                que.add_job(job_id);
                break;

            case 2:
                que.delete_job();
                break;

            case 3:
                que.display_job();
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
