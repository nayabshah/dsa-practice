#include <iostream>
using namespace std;


class Node
{
public:
    int data;
    Node *next;
    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};
class Queue
{
private:

    Node *front;
    Node *rear;

public:
    Queue()
    {
        front = rear = nullptr;
    };
    void create(int A[],int n){
        if (n == 0)
            return;

        front=rear = new Node(A[0]);
        Node *l = front;

        for (int i = 1; i < n; i++)
        {
            Node *t = new Node(A[i]);
            l->next = t;
            l = t;
        }
        rear=l;
    }
    // O(1)
    void enqueue(int x)
    {
        Node *t = new Node(x);
        if (!t)
        {
            printf("Queue if full");
        }else{
            if(front == nullptr){
                front= rear = t;
            }else{
                rear->next=t;
                rear=rear->next;
            }
        }

    }
    // O(1)
    int dequeue()
    {
        Node *p= front;
        int x=-1;
        if (front !=nullptr)
        {
            x = front->data;
            front=front->next;
            delete p;
        }

        return x;
    }

    void display()
    {
        Node *p = front;
        while (p != NULL)
        {
            cout << p->data << " -> ";
            p = p->next;
        }
        cout << "NULL" << endl;
    };

};

int main()
{

    Queue q;
    int A[] = {10, 20, 30, 40, 60, 75};
    q.create(A,6);
    q.display();
    q.dequeue();
    q.dequeue();
    q.display();

    return 0;
};
