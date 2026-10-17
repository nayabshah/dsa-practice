#include <iostream>
using namespace std;

class CircularQueue
{
private:
    int *Q;
    int size;
    int front;
    int rear;

public:
    CircularQueue()
    {
        size = 4;
        front = rear = 0;
        Q = new int[size];
    };
    CircularQueue(int n)
    {
        this->size = n;
        front = rear = 0;
        Q = new int[n];
    };
    ~CircularQueue()
    {
        delete[] Q;
    };
    // O(1)
    void enqueue(int x)
    {
        if (!isFull())
        {
            rear = (rear + 1) % size;
            Q[rear] = x;
        }
    }
    // O(1)
    int dequeue()
    {
        int x = -1;
        if (!isEmpty())
        {
            front = (front + 1) % size;
            x = Q[front + 1];
        }

        return x;
    }
    int isEmpty()
    {
        return front == rear;
    }
    int isFull()
    {
        return (rear + 1) % size == front;
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
        int i = front + 1;
        do
        {
            cout << Q[i] << " ";
            i = (i + 1) % size;
        } while (i != (rear + 1) % size);
        cout << endl;
    }
};

int main()
{

    CircularQueue q(6);
    q.enqueue(6);
    q.enqueue(8);
    q.enqueue(10);
    q.enqueue(12);
    q.enqueue(14);
    q.enqueue(16);

    q.display();
    q.dequeue();
    q.dequeue();
    q.enqueue(6);
    q.enqueue(6);
    q.display();

    return 0;
};
