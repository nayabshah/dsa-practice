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

class CircularLinkedList
{

public:
    Node *head;

    CircularLinkedList()
    {
        head = nullptr;
    }
    void create(int A[], int n)
    {
        if (n == 0)
            return;

        head = new Node(A[0]);
        head->next = head;
        Node *l = head;

        for (int i = 1; i < n; i++)
        {
            Node *t = new Node(A[i]);
            t->next = l->next;
            l->next = t;
            l = t;
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
        Node *p = head;
        do
        {
            len+=1;
            p = p->next;
        } while (p != head);
        return len;
    }
    // void recursiveDisplay(Node* p)
    // {
    //      static int flag=0;
    //     if (p != head || flag==0)
    //     {
    //          flag = 1;
    //         cout << p->data << " -> ";
    //         recursiveDisplay(p->next);
    //     }
    //      flag = 0;
    // }

    // int countNodes()
    // {
    //     int count = 0;
    //     Node *p = first;
    //     while (p != NULL)
    //     {
    //         count++;
    //         p = p->next;
    //     }
    //     return count;
    // }

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

    // int maxNode()
    // {
    //     int max = INT_MIN;
    //     Node *p = first;
    //     while (p != NULL)
    //     {
    //         if (p->data > max)
    //         {
    //             max = p->data;
    //         }
    //         p = p->next;
    //     }
    //     return max;
    // };
    // int sum()
    // {
    //     int sum = 0;
    //     Node *p = first;
    //     while (p != NULL)
    //     {
    //         sum += p->data;
    //         p = p->next;
    //     }
    //     return sum;
    // }

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

    // Node *search(int key)
    // {
    //     Node *p = first;

    //     while (p != NULL)
    //     {
    //         if (key == p->data)
    //         {
    //             return p;
    //         }
    //         p = p->next;
    //     }
    //     return nullptr;
    // };
    // Node *improvedSearch(int key)
    // {

    //     Node *p = first;
    //     Node *q = NULL;
    //     while (p != NULL)
    //     {
    //         if (key == p->data)
    //         {
    //             q->next = p->next;
    //             p->next = first;
    //             first = p;
    //         }
    //         q = p;
    //         p = p->next;
    //     }
    //     return nullptr;
    // }

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
            }
            else
            {
                t->next = head;
                while (p->next != head)
                    p = p->next;
                p->next = t;
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
                x = p->data;
                delete p;
                return x;
            }
        }
    };

    // void reverse1()
    // {
    //     Node *p = first;
    //     int n = countNodes();
    //     int *A = new int[n];
    //     int i = 0;
    //     while (p)
    //     {
    //         A[i] = p->data;
    //         i++;
    //         p = p->next;
    //     }

    //     p = first;
    //     i = n - 1;

    //     while (p)
    //     {
    //         p->data = A[i];
    //         i--;
    //         p = p->next;
    //     }

    //     delete[] A;
    // }

    // void reverse2()
    // {

    //     Node *p = first;
    //     Node *r = NULL;
    //     Node *q = NULL;
    //     while (p)
    //     {
    //         r = q;
    //         q = p;
    //         p = p->next;
    //         q->next = r;
    //     }
    //     first = q;
    // }
    // void concate2(Node *second)
    // {
    //     Node *p = first;
    //     while (p->next)
    //     {
    //         p = p->next;
    //     }
    //     p->next = second;
    // }

    // void merge(Node *second) // o(m+n)
    // {
    //     Node *l = NULL;
    //     Node *curFirst = first;
    //     if (curFirst->data < second->data)
    //     {
    //         l = first = curFirst;
    //         curFirst = curFirst->next;
    //         l->next = NULL;
    //     }
    //     else
    //     {
    //         l = first = second;
    //         second = second->next;
    //         l->next = NULL;
    //     }
    //     while (curFirst->next && second->next)
    //     {
    //         if (curFirst->data < second->data)
    //         {
    //             l->next = curFirst;
    //             l = curFirst;
    //             curFirst = curFirst->next;
    //             l->next = NULL;
    //         }
    //         else
    //         {
    //             l->next = second;
    //             l = second;
    //             second = second->next;
    //             l->next = NULL;
    //         }
    //     }
    //     if (curFirst)
    //     {
    //         l->next = curFirst;
    //     }
    //     else
    //     {
    //         l->next = second;
    //     }
    // }
    // int isLoop()
    // {
    //     Node *p, *q;
    //     p = q = first;
    //     do
    //     {
    //         p = p->next;
    //         q = q->next;
    //         q = q ? q->next : q;
    //     } while (p && q && p != q);
    //     return p == q ? 1 : 0;
    // }
};

int main()
{
    int A[] = {10, 20, 30, 40, 60, 75};
    //
    CircularLinkedList list;

    list.create(A, 6);
    list.insert(25, 2);

    list.deleteNode(1);
    // cout << list.isLoop();
    list.display();

    return 0;
}
