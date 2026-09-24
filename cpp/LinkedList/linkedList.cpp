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
private:
    Node *first;

public:
    LinkedList()
    {
        first = nullptr;
    }
    void create(int A[], int n)
    {
        if (n == 0)
            return;

        first = new Node(A[0]);
        Node *last = first;

        for (int i = 1; i < n; i++)
        {
            Node *t = new Node(A[i]);
            last->next = t;
            last = t;
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
    Node *improvedSearch(int key){

        Node *p = first;
        Node *q =NULL;
        while (p != NULL)
        {
            if (key == p->data)
            {
                q->next = p->next;
                p->next = first;
                first=p;
            }
            q = p;
            p = p->next;
        }
        return nullptr;
    }
};

int main()
{
    int A[] = {10, 20, 30, 90, 50, 70, 15};

    LinkedList list;
    list.create(A, 7);

    list.display();


    Node *result = list.improvedSearch(30);
    list.display();


    return 0;
}
