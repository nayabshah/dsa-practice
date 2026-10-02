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

class CircularDoublyLinkedList
{

public:
    Node *head;

    CircularDoublyLinkedList()
    {
        head = nullptr;
    }
    void create(int A[], int n)
    {
        if (n == 0)
            return;

        head = new Node(A[0]);
        head->next = head;
        head->prev = head;
        Node *l = head;

        for (int i = 1; i < n; i++)
        {
            Node *t = new Node(A[i]);
            t->next = l->next;
            l->next = t;
            t->prev = l;
            l = t;
            head->prev = l;
        }
    };

    void display()
    {
        Node *p = head;
        do
        {
            cout << p->data << " ";
            p = p->next;
        } while (p != head);
    };

    int Length()
    {

        int len = 0;
        if(!head){
            return len;
        }
        Node *p = head;
        do
        {
            len += 1;
            p = p->next;
        } while (p != head);
        return len;
    }

    void insert(int data, int indx)
    {
        if (indx < 0 || indx > Length())
        {
            return;
        }
        Node *t = new Node(data);
        Node *p = head;

        if (indx == 0)
        {
            if (head == NULL)
            {
                head = t;
                head->next = head;
                head->prev = head;
            }
            else
            {
                t->next = head;
                while (p->next != head)
                    p = p->next;
                p->next = t;
                t->prev = p;
                head = t;
            }
        }
        else if (indx > 0)
        {

            for (int i = 1; i <= (indx - 1) && p; i++)
            {
                p = p->next;
            }

            if (p)
            {
                t->next = p->next;
                t->prev = p;
                p->next = t;
            }
        }
        return;
    }

    int deleteNode(int indx)
    {
        Node *p = head;
        int x = -1, i;

        if (indx < 0 || indx > Length())
        {
            return -1;
        }
        if (indx == 1)
        {
            while (p->next != head)
                p = p->next;
            x = head->data;
            if (p == head)
            {
                delete head;
                head = NULL;
            }
            else
            {

                p->next = head->next;
                p->next->prev = head->prev;
                delete head;
                head = p->next;
            }

            return x;
        }
        else
        {
            Node *q = NULL;
            for (i = 0; i <= indx - 1 && p; i++)
            {
                q = p;
                p = p->next;
            }

            if (p)
            {
                q->next = p->next;
                p->next->prev = q;
                x = p->data;
                delete p;
                return x;
            };
        };
    }
};

int main()
{
    int A[] = {10, 20, 30, 40, 60, 75};
    //
    CircularDoublyLinkedList list;

    list.insert(0, 0);
    list.insert(10, 0);
    list.insert(20, 0);
    list.insert(30, 0);

    // list.create(A, 6);
    // list.deleteNode(2);
    // cout << list.isLoop();
    list.display();

    return 0;
}
