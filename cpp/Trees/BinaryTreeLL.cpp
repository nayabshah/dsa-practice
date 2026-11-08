
#include <iostream>
using namespace std;

// self referential structure
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class Queue
{
private:
    Node **Q;
    int size;
    int front;
    int rear;

public:
    Queue()
    {
        size = 4;
        front = rear = -1;
        Q = new Node *[size];
    };
    Queue(int n)
    {
        this->size = n;
        front = rear = -1;
        Q = new Node *[n];
    };
    ~Queue()
    {
        delete[] Q;
    };
    // O(1)
    void enqueue(Node *x)
    {
        if (!isFull())
        {
            rear++;
            Q[rear] = x;
        }
    }
    // O(1)
    Node *dequeue()
    {
        Node *x = NULL;
        if (!isEmpty())
        {
            x = Q[front + 1];
            front++;
        }

        return x;
    }
    int isEmpty()
    {
        return front == rear;
    }
    int isFull()
    {
        return rear == size - 1;
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

Node *root;
class Binarytree
{
public:
    Binarytree() { root = NULL; }

    void CreateTree()
    {
        Node *p, *t;
        int x;
        Queue q(100);
        printf("Enter root value ");
        scanf("%d", &x);
        root = new Node(x);
        q.enqueue(root);
        while (!q.isEmpty())
        {
            p = q.dequeue();
            printf("enter left child of %d", p->data);
            scanf("%d", &x);
            if (x != -1)
            {
                t = new Node(x);
                p->left = t;
                q.enqueue(t);
            }
            printf("enter right child of %d", p->data);
            scanf("%d", &x);
            if (x != -1)
            {
                t = new Node(x);
                p->right = t;
                q.enqueue(t);
            }
        }
    };

    
    void Preorder(Node *p);
    void Inorder(Node *p);
    void Postorder(Node *p);
    void Levelorder(Node *p);
    void Height(Node *root);
};
void Binarytree::Preorder(Node *p)
{
    if (p)
    {
        printf(" %d ", p->data);
        Preorder(p->left);
        Preorder(p->right);
    }
}

void Binarytree::Inorder(Node *p)
{
    if (p)
    {

        Inorder(p->left);
        printf(" %d", p->data);
        Inorder(p->right);
    }
}
void Binarytree::Postorder(Node *p)
{
    if (p)
    {
        Postorder(p->left);
        Postorder(p->right);
        printf(" %d", p->data);

    }
}

int main()
{
    Binarytree bt;
    bt.CreateTree();
    bt.Preorder(root);
    printf("\nPost Order");
    bt.Postorder(root);
    return 0;
}
