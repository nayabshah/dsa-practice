#include <iostream>
using namespace std;

class CircularQueue
{
private:
    int *Q;
    int size;
    int front;
    int rear;

public:
    CircularQueue()
    {
        size = 4;
        front = rear = 0;
        Q = new int[size];
    };
    CircularQueue(int n)
    {
        this->size = n;
        front = rear = 0;
        Q = new int[n];
    };
    ~CircularQueue()
    {
        delete[] Q;
    };
    // O(1)
    void enqueue(int x)
    {
        if (!isFull())
        {
            rear = (rear + 1) % size;
            Q[rear] = x;
        }
    }
    // O(1)
    int dequeue()
    {
        int x = -1;
        if (!isEmpty())
        {
            front = (front + 1) % size;
            x = Q[front + 1];
        }

        return x;
    }
    int isEmpty()
    {
        return front == rear;
    }
    int isFull()
    {
        return (rear + 1) % size == front;
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
        int i = front + 1;
        do
        {
            cout << Q[i] << " ";
            i = (i + 1) % size;
        } while (i != (rear + 1) % size);
        cout << endl;
    }
};
int *A;
class BinaryTreeArr{
    int root;


public:

    BinaryTreeArr(){
        root = -1;
        A=new int[7];
    };
    BinaryTreeArr(int n){
        root =-1;
        A=new int[n];

    };

    void CreateTree(int n)
    {
        int p;
        int x;
        CircularQueue q(n);
        printf("Enter root value ");
        scanf("%d", &x);
        root = x;
        A[0] =root;
        q.enqueue(0);

         while (!q.isEmpty())
        {
            p = q.dequeue();
            printf("enter left child of %d ", A[p]);
            scanf("%d", &x);
            if (x != -1 && 2*p+1 <n)
            {
                A[2*p+1] = x;
                q.enqueue(2*p+1);
            }
            printf("enter right child of %d ", A[p]);
            scanf("%d", &x);
            if (x != -1 && 2*p+2 <n)
            {
                A[2*p+2] = x;
                q.enqueue(2*p+2);
            }
        }

    };

    void Preorder(int i);
    void Inorder(int i);
    void Postorder(int i);
};

void BinaryTreeArr::Inorder(int i)
{
    if (A[i])
    {
        Inorder(2*i+1);
        printf(" %d ", A[i]);
        Inorder(2*i+2);
    }
}
void BinaryTreeArr::Preorder(int i)
{
    if (A[i])
    {
        printf(" %d ", A[i]);
        Preorder(2*i+1);
        Preorder(2*i+2);
    }
}
void BinaryTreeArr::Postorder(int i)
{
    if (A[i])
    {
        Postorder(2*i+1);
        Postorder(2*i+2);
        printf(" %d ", A[i]);

    }
}

int main()
{
    BinaryTreeArr bt;
    bt.CreateTree(8);
    printf("\nPre Order");

    bt.Preorder(0);
    printf("\nPost Order");
    bt.Postorder(0);
    return 0;
}
