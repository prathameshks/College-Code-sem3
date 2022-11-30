/*
Queues are frequently used in computer programming, and a typical example is the
creation of a job queue by an operating system. If the operating system does not use
priorities, then the jobs are processed in the order they enter the system. Write C++
program for simulating job queue. Write functions to add job and delete job from queue.
*/

#include <iostream>
#define ARR_SIZE 5
using namespace std;

class queue
{
private:
    int arr[ARR_SIZE];
    int front, rear;

public:
    queue();
    bool isEmpty();
    bool isFull();
    void enqueue(int elmt);
    int dequeue();
    void display();
};

queue::queue()
{
    front = -1;
    rear = -1;
}

bool queue::isEmpty()
{
    if (front == -1 && rear == -1)
    {
        return true;
    }
    return false;
}

bool queue::isFull()
{
    if (rear == ARR_SIZE - 1)
    {
        return true;
    }
    return false;
}

void queue::enqueue(int elmt)
{
    if (!isFull())
    {
        rear++;
        arr[rear] = elmt;
    }
}

int queue::dequeue()
{
	int elmt=0;
    if (!isEmpty())
    {
    	elmt = arr[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front++;
        }
    }
    return elmt;
}

void queue::display()
{
    for (int i = front; i <= rear; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    queue que;
    int ch;
    int elmt;
    do
    {
        cout << "MENU\n1. Add Job\n2. Delete Job\n3. Display Queue\n4. Exit\nEnter Choice:";
        cin >> ch;
        switch (ch)
        {
        case 1:
		    if(que.isFull()){
		    	cout<<"Queue Overflow"<<endl;
		    	break;
		    }
            cout << "Enter Job ID:";
            cin >> elmt;
            que.enqueue(elmt);
            break;

        case 2:
		    if(que.isEmpty()){
		    	cout<<"Queue Underflow"<<endl;
		    	break;
		    }
		    cout<<"Deleted Job with ID :"<<que.dequeue()<<endl;
            break;

        case 3:
        	if(que.isEmpty()){
		    	cout<<"Queue Is Empty"<<endl;
		    	break;
		    }
        	cout<<"Job Queue: ";
            que.display();
            break;

        case 4:
            cout<<"Thank You"<<endl;
            break;

        default:
            break;
        }
    }while (ch!=4);

    return 0;
}
