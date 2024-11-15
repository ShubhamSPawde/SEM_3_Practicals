#include <bits/stdc++.h>
using namespace std;

#define SIZE 7

class process
{
public:
    int pid; 
    int BT;  
    int RT;  
};

class Queue
{
public:
    process arr[SIZE];
    int n;
    int front;
    int rear;

    Queue()
    {
        front = -1;
        rear = -1;
    }

    bool isEmpty();
    bool isFull();
    void enqueue(process x);
    process dequeue();
    void display();
};

bool Queue::isEmpty()
{
    return (front == -1 && rear == -1);
}

bool Queue::isFull()
{
    return ((rear + 1) % SIZE == front);
}

// Insertion at End

void Queue::enqueue(process x)
{
    if (isFull())
    {
        cout << "Queue is Full!" << endl;
        return;
    }
    else if (isEmpty())
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear = (rear + 1) % SIZE;
    }
    arr[rear] = x;
}

// Deletion at front

process Queue::dequeue()
{
    process x;
    if (isEmpty())
    {
        cout << "Queue is Empty!" << endl;
        return x;
    }
    else if (front == rear)
    {
        x = arr[front];
        front = -1;
        rear = -1;
    }
    else
    {
        x = arr[front];
        front = (front + 1) % SIZE;
    }
    return x;
}

void Queue::display() {
    if (isEmpty()) {
        cout << "Queue is Empty!" << endl;
        return;
    }

    cout << "Processes in Queue: ";
    int count = (rear >= front) ? (rear - front + 1) : (SIZE - front + rear + 1);
    
    for (int i = 0; i < count; i++) {
        cout << arr[(front + i) % SIZE].pid << " "; 
    }
    cout << endl;
}

void RoundRobin(Queue pq, int Qt)
{
    process x;
    int TotalTime = 0;

    while (!pq.isEmpty())
    {
        x = pq.dequeue();
        if (x.RT > Qt)
        {
            x.RT -= Qt;
            TotalTime += Qt;
            cout << "Process " << x.pid << " scheduled for " << Qt
                 << " time. Total Time: " << TotalTime << endl;
            pq.enqueue(x);
        }
        else
        {
            TotalTime += x.RT; 
            cout << "Process " << x.pid << " completed at " << TotalTime << endl;
            x.RT = 0; 
        }
    }
    cout << "Total time taken: " << TotalTime << endl;
}

int main()
{
    Queue pq;
    process x;

    cout << "Enter the number of processes: ";
    cin >> pq.n;

    for (int i = 0; i < pq.n; i++)
    {
        cout << "Enter Process ID and Burst Time: ";
        cin >> x.pid >> x.BT;
        x.RT = x.BT; 
        pq.enqueue(x);
    }

    int Qt;
    cout << "Enter the Quantum Time: ";
    cin >> Qt;

    cout<<endl;
    cout<<endl;
    cout<<"Output"<<endl;
    cout<<endl;

    cout << "Initial Queue State: ";

    pq.display();

    RoundRobin(pq, Qt);

    return 0;
}

