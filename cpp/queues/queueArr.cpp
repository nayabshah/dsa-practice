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
        front = -1;
        rear = -1;
        Q = new int[size];
    };
    Queue(int n)
    {
        this->size = n;
        front = -1;
        rear = -1;
        Q = new int[n];
    };
    ~Queue()
    {
        delete[] Q;
    };
    // O(1)
    void enqueue(int x)
    {
        if (rear != size - 1)
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
    q.enqueue(6);
    q.enqueue(8);
    q.enqueue(10);
    q.enqueue(12);
    q.enqueue(14);
    q.enqueue(16);

    q.display();
    q.dequeue();
    q.dequeue();
    q.display();

    return 0;
};
