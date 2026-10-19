#include <iostream>
using namespace std;

class PriorityQueue
{
private:
    int *Q;
    int size;
    int front;
    int rear;

public:
    PriorityQueue()
    {
        size = 4;
        front = rear = -1;
        Q = new int[size];
    };
    PriorityQueue(int n)
    {
        this->size = n;
        front = rear = -1;
        Q = new int[n];
    };
    ~PriorityQueue()
    {
        delete[] Q;
    };
    // O(1)
    // void enqueue(int x)
    // {
    //     if (!isFull())
    //     {
    //         rear++;
    //         Q[rear] = x;
    //     }
    // }

    void enqueue(int val)
    {
        if (!isFull())
        {
            if (isEmpty())
            {
                rear++;
                Q[rear] = val;
            }
            else
            {
                int i = rear;
                while(i>=0 && val > Q[i]){
                    Q[i+1] = Q[i];
                    i--;
                }
                Q[i+1] = val;
                rear++;
            }
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

    // O(n)
    // int dequeue()
    // {
    //     int x = -1;
    //     int maxPriority = front + 1;
    //     int i = front + 1;
    //     for (; i < rear; i++)
    //     {
    //         if (Q[i] < Q[maxPriority])
    //         {
    //             maxPriority = i;
    //         }
    //     }
    //     x = Q[maxPriority];
    //     i = maxPriority;
    //     for (; i < rear; i++)
    //     {
    //         Q[i] = Q[i + 1];
    //     }
    //     rear--;
    //     return x;
    // }
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

    PriorityQueue q(20);

    q.enqueue(8);
    q.enqueue(10);
    q.enqueue(12);
    q.enqueue(6);
    q.enqueue(14);
    q.enqueue(3);
    q.enqueue(16);

    // q.dequeue();
    // q.dequeue();

    q.display();
    return 0;
};
