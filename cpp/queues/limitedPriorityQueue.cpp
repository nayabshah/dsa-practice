#include <iostream>
using namespace std;

class Queue
{
private:
    int *Q;
    int size;
    int front;
    int rear;

public:
    Queue()
    {
        size = 6;
        front = rear = -1;
        Q = new int[size];
    };
    Queue(int n)
    {
        this->size = n;
        front = rear = -1;
        Q = new int[n];
    };
    ~Queue()
    {
        delete[] Q;
    };
    // O(1)
    void create(int A[], int n)
    {
        int i = 0;
        for (; i < n; i++)
        {
            Q[i] = A[i];
            rear = i;
        }
    }
    void enqueue(int x)
    {
        if (!isFull())
        {
            rear++;
            Q[rear] = x;
        }
    }
    // O(1)
    int dequeue()
    {
        int x = -1;
        if (!isEmpty())
        {
            x = Q[front + 1];
            front++;
        }

        return x;
    }
    int isEmpty()
    {
        return front == rear;
    }
    int isFull()
    {
        return rear == size - 1;
    }
    int first()
    {
        return Q[front + 1];
    }
    int last()
    {
        return Q[rear];
    }
    void display()
    {
        if (rear > -1)
        {
            for (int i = front + 1; i <= rear; i++)
            {
                cout << Q[i] << " ";
            }
            cout << endl;
        }
    }
};

class PriorityQueue
{
private:
    Queue q1;
    Queue q2;
    Queue q3;
    int size;

public:
    PriorityQueue()
    {
        size = 3;
    };
    int dequeue()
    {
        int x = -1;
        if (!q1.isEmpty())
        {
            x = q1.dequeue();
        }
        else if (!q2.isEmpty())
        {
            x = q2.dequeue();
        }
        else if (!q3.isEmpty())
        {
            x = q3.dequeue();
        }

        return x;
    }
    void enqueue(int x, int priority)
    {
        if (priority < size && priority > -1)
        {
            if (priority == 0)
            {
                q1.enqueue(x);
            }
            else if (priority == 1)
            {
                q2.enqueue(x);
            }
            else
            {
                q3.enqueue(x);
            }
        }
    }
    void display()
    {
        q1.display();
        q2.display();
        q3.display();
    }
};

int main()
{

    PriorityQueue q;
    q.enqueue(20, 0);
    q.enqueue(40, 0);
    q.enqueue(30, 1);
    q.enqueue(10, 2);
    q.enqueue(50, 2);
    q.display();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.display();

    return 0;
};
