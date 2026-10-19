#include <iostream>
using namespace std;

class Stack
{
private:
    int *A;
    int size;
    int top;

public:
    Stack()
    {
        size = 6;
        top = -1;
        A = new int[size];
    };
    Stack(int n)
    {
        this->size = n;
        top = -1;
        A = new int[n];
    };
    ~Stack()
    {
        delete[] A;
    };
    int isEmpty()
    {
        return top == -1;
    }
    int isFull()
    {
        return top == size - 1;
    }

    void push(int val)
    {
        if (isFull())
        {
            return;
        }
        else
        {
            top++;
            A[top] = val;
        }
    }
    int pop()
    {
        int x = -1;
        if (isEmpty())
        {
            return x;
        }
        else
        {
            x = A[top--];
        }
        return x;
    }
    int peak(int idx)
    {
        int x = -1;
        if (top - idx + 1 < 0)
        {
            return -1;
        }
        else
        {
            return A[top - idx + 1];
        }
    }
    int stackTop()
    {
        if (top == -1)
        {
            return -1;
        }
        else
        {
            return A[top];
        }
    }
    void display()
    {
        for (int i = top; i >= 0; i--)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};

class Queue
{

private:
    Stack s1;
    Stack s2;

public:
    Queue()
    {
        Stack s1(4);
        Stack s2(4);
    };

    void enqueue(int x)
    {
        if (!s1.isFull())
        {
            s1.push(x);
        }
    }
    int dequeue()
    {
        int x = -1;
        if (!s1.isEmpty())
        {

            while (!s1.isEmpty())
            {
                s2.push(s1.pop());
            }
            x = s2.pop();
        }
        return x;
    }

};
int main()
{
    Queue q;

    q.enqueue(6);
    q.enqueue(8);
    q.enqueue(10);
    q.enqueue(12);
    q.enqueue(14);
    q.enqueue(16);


    q.dequeue();
    q.dequeue();
    
    return 0;
};
