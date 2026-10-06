#include <iostream>
#include <climits>
using namespace std;

// self referential structure
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

class Stack
{

public:
    Node *Top;

    Stack()
    {
        Top = nullptr;
    }
    int isEmpty()
    {
        return Top == nullptr;
    }
    // int isFull()
    // {
    //     Node *t =new Node();
    //     return t == NULL;
    // }
    void push(int val)
    {
        Node *t = new Node(val);
        if (t == NULL)
        {
            return;
        }
        else
        {
            t->next = Top;
            Top = t;
        }
    }

    int pop()
    {
        int x = -1;
        Node *p;
        if (isEmpty())
        {
            return x;
        }
        else
        {
            p = Top;
            x = Top->data;
            Top = Top->next;
            delete p;
        }
        return x;
    }
    void display()
    {
        Node *p = Top;
        while (p)
        {
            cout << p->data <<" ";
            p = p->next;
        }
        cout<<endl;
    }

     int peak(int idx)
    {

        if (idx-1 < 0)
        {
            return -1;
        }
        else
        {
            Node *p = Top;
            for(int i=0;p != NULL && i < idx - 1;i++){
                p=p->next;
            }
            if(p){
                return p->data;
            }
            return -1;
        }
    }
    int stackTop()
    {

        return Top? Top->data:-1;
    }
};

int main()
{

    Stack s;
    s.push(6);
    s.push(7);
    s.push(8);
    s.push(9);
    s.push(10);

    s.display();
    s.pop();
    s.display();
    return 0;
};
