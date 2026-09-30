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

class LinkedList
{

public:
    Node *first;
    Node *last;
    LinkedList()
    {
        first = nullptr;
        last = nullptr;
    }
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
            l = t;
        }
    };

    void display()
    {
        Node *p = first;
        while (p != NULL)
        {
            cout << p->data << " -> ";
            p = p->next;
        }
        cout << "NULL" << endl;
    };

    // void recursiveDisplay(Node* p)
    // {
    //     if (p != NULL)
    //     {
    //         cout << p->data << " -> ";
    //         p = p->next;
    //         recursiveDisplay(p);
    //     }
    // }

    int countNodes()
    {
        int count = 0;
        Node *p = first;
        while (p != NULL)
        {
            count++;
            p = p->next;
        }
        return count;
    }

    // int recursiveCount(Node* p)
    // {
    //     if (p != NULL)
    //     {
    //         p = p->next;
    //         return recursiveCount(p) + 1;
    //     }
    //     else
    //     {
    //         return 0;
    //     }
    // }

    int maxNode()
    {
        int max = INT_MIN;
        Node *p = first;
        while (p != NULL)
        {
            if (p->data > max)
            {
                max = p->data;
            }
            p = p->next;
        }
        return max;
    };
    int sum()
    {
        int sum = 0;
        Node *p = first;
        while (p != NULL)
        {
            sum += p->data;
            p = p->next;
        }
        return sum;
    }

    // int recursiveMax(Node* p)
    // {
    //     int x = 0;
    //     Node* p = first;
    //     if (p == NULL)
    //     {
    //         return INT_MIN;
    //     }
    //     else
    //     {
    //         x = recursiveMax(p->next);
    //         if (x > p->data)
    //         {
    //             return x;
    //         }
    //         else
    //         {
    //             return p->data;
    //         }
    //     }
    // }

    Node *search(int key)
    {
        Node *p = first;

        while (p != NULL)
        {
            if (key == p->data)
            {
                return p;
            }
            p = p->next;
        }
        return nullptr;
    };
    Node *improvedSearch(int key)
    {

        Node *p = first;
        Node *q = NULL;
        while (p != NULL)
        {
            if (key == p->data)
            {
                q->next = p->next;
                p->next = first;
                first = p;
            }
            q = p;
            p = p->next;
        }
        return nullptr;
    }

    void insert(int data, int indx)
    {
        Node *t = new Node(data);
        if (indx == 0)
        {
            t->next = first;
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
                p->next = t;
            }
        }
        return;
    }

    void insertLast(int value)
    {
        Node *t = new Node(value);
        if (first == NULL)
        {
            first = last = t;
        }
        else
        {
            last->next = t;
            last = t;
        }
    };
    void insertSorted(int data)
    {
        Node *p = first;
        Node *q = NULL;
        Node *t = new Node(data);

        if (first == NULL)
        {
            first = t;
        }
        else
        {
            if (first->data > data)
            {
                t->next = first;
                first = t;
                return;
            }
            else
            {
                while (p && p->data <= data)
                {
                    q = p;
                    p = p->next;
                }
                if (q)
                {
                    t->next = q->next;
                    q->next = t;
                }
            }
        }
    }

    int deleteNode(int indx)
    {
        Node *p = first;
        int x = -1, i;
        if (indx < 1 || indx > countNodes())
        {
            return x;
        }
        if (indx == 1)
        {
            first = first->next;
            x = p->data;
            delete p;
            return x;
        }
        else
        {
            Node *q = NULL;
            for (i = 0; i < indx - 1 && p; i++)
            {
                q = p;
                p = p->next;
            }

            if (p)
            {
                q->next = p->next;
                x = p->data;
                delete p;
                return x;
            }
        }
    };
    int isSorted()
    {
        Node *p = first;
        int x = -1;
        while (p)
        {
            if (p->data < x)
            {
                return 0;
            }
            x = p->data;
            p = p->next;
        }

        return 1;
    }
    void removeDuplicate()
    {

        Node *p = first;
        Node *q = first->next;

        while (q)
        {
            if (q->data == p->data)
            {
                p->next = q->next;
                delete q;
                q = p->next;
            }
            else
            {
                p = q;
                q = q->next;
            }
        }
    };

    void reverse1()
    {
        Node *p = first;
        int n = countNodes();
        int *A = new int[n];
        int i = 0;
        while (p)
        {
            A[i] = p->data;
            i++;
            p = p->next;
        }

        p = first;
        i = n - 1;

        while (p)
        {
            p->data = A[i];
            i--;
            p = p->next;
        }

        delete[] A;
    }

    void reverse2()
    {

        Node *p = first;
        Node *r = NULL;
        Node *q = NULL;
        while (p)
        {
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }
        first = q;
    }
    void concate2(Node *second)
    {
        Node *p = first;
        while (p->next)
        {
            p = p->next;
        }
        p->next = second;
    }

    void merge(Node *second) // o(m+n)
    {
        Node *l = NULL;
        Node *curFirst = first;
        if (curFirst->data < second->data)
        {
            l = first = curFirst;
            curFirst = curFirst->next;
            l->next = NULL;
        }
        else
        {
            l = first = second;
            second = second->next;
            l->next = NULL;
        }
        while (curFirst->next && second->next)
        {
            if (curFirst->data < second->data)
            {
                l->next = curFirst;
                l = curFirst;
                curFirst = curFirst->next;
                l->next = NULL;
            }
            else
            {
                l->next = second;
                l = second;
                second = second->next;
                l->next = NULL;
            }
        }
        if (curFirst)
        {
            l->next = curFirst;
        }
        else
        {
            l->next = second;
        }
    }
    int isLoop()
    {
        Node *p, *q;
        p = q = first;
        do
        {
            p = p->next;
            q = q->next;
            q = q ? q->next : q;
        } while (p && q && p != q);
        return p == q ? 1 : 0;
    }
};

int main()
{
    int A[] = {10, 20, 30, 40, 60, 75};
    //
    LinkedList list;

    list.create(A, 6);
    list.deleteNode(0);
    list.deleteNode(5);
    // Node *t1, *t2;
    // t1 = list.first->next->next;
    // t2 = list.first->next->next->next->next->next;
    // t2->next = t1;
    // cout << list.isLoop();
    list.display();

    return 0;
}
