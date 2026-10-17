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
        size = 4;
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
    void create(int A[], int n)
    {
        int i = 0;
        for (; i < n; i++)
        {
            Q[i] = A[i];
            rear = i;
        }
    }
    // O(1)
    void enqueueRear(int x)
    {
        if (!isFull())
        {
            rear++;
            Q[rear] = x;
        }
    }
    void enqueueFront(int x)
    {
        if (front != -1 && !isFull())
        {
            Q[front] = x;
            front--;
        }
    }
    // O(1)
    int dequeueFront()
    {
        int x = -1;
        if (!isEmpty())
        {
            x = Q[front + 1];
            front++;
        }

        return x;
    }
    int dequeueRear()
    {
        int x = -1;
        if (!isEmpty())
        {
            x = Q[rear];
            rear--;
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
        for (int i = front + 1; i <= rear; i++)
        {
            cout << Q[i] << " ";
        }
        cout << endl;
    }
};

int main()
{

    Queue q(6);
    int A[] = {1, 2, 3, 4, 5, 6};
    q.create(A, 6);
    q.display();

    q.dequeueRear();
    q.dequeueFront();
    q.enqueueFront(0);
    q.display();
    delete A;
    return 0;
};
