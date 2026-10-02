#include <iostream>
#include <climits>
using namespace std;

// self referential structure
class Node
{
public:
    Node *prev;
    int data;
    Node *next;

    Node(int value)
    {
        prev = nullptr;
        data = value;
        next = nullptr;
    }
};

class DoublyLL
{

public:
    Node *first;
    Node *last;
    DoublyLL()
    {
        first = nullptr;
    };

    void create(int A[], int n)
    {
        if (n == 0)
            return;

        first = new Node(A[0]);
        Node *l = first;

        for (int i = 1; i < n; i++)
        {
            Node *t = new Node(A[i]);
            l->next = t;
            t->prev = l;
            l = t;
        }
    };

    void display()
    {
        Node *p = first;
        while (p != NULL)
        {
            cout << p->data << " <-> ";
            p = p->next;
        }
        cout << "NULL" << endl;
    };

    void insert(int data, int indx)
    {
        Node *t = new Node(data);
        if (indx == 0)
        {
            t->next = first;
            first->prev = t;
            first = t;
        }
        else if (indx > 0)
        {
            Node *p = first;
            for (int i = 0; i < (indx - 1) && p; i++)
            {
                p = p->next;
            }

            if (p)
            {
                t->next = p->next;
                t->prev = p;
                if (p->next)
                {
                    p->next->prev = t;
                }

                p->next = t;
            }
        }
        return;
    }

    void reverse()
    {

        Node *p = first;
        Node *temp;
        while (p)
        {
            temp = p->next;
            p->next = p->prev;
            p->prev = temp;
            p = temp;
            if (p && !p->next)
                first = p;

        }
    }
};

int main()
{
    int A[] = {10, 20, 30, 40, 60, 75};
    DoublyLL list;
    list.create(A, 6);
    // list.insert(5,0);
    list.reverse();
    list.display();
    return 0;
}
