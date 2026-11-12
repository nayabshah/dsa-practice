
#include <iostream>
#include <stack>
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
        Queue q(50);
        printf("Enter root value ");
        scanf("%d", &x);
        root = new Node(x);
        q.enqueue(root);
        while (!q.isEmpty())
        {
            p = q.dequeue();
            printf("enter left child of %d ", p->data);
            scanf("%d", &x);
            if (x != -1)
            {
                t = new Node(x);
                p->left = t;
                q.enqueue(t);
            }
            printf("enter right child of %d ", p->data);
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
    stack<Node *> st;
    while (p != NULL || !st.empty())
    {
        if (p)
        {
            cout << p->data << " ";
            st.push(p);
            p = p->left;
        }
        else
        {
            p = st.top();
            st.pop();
            p = p->right;
        }
    }
}

void Binarytree::Inorder(Node *p)
{
    stack<Node *> st;
    while (p != NULL || !st.empty())
    {
        if (p)
        {
            st.push(p);
            p = p->left;

        }
        else
        {

            p = st.top();
            st.pop();
            cout << p->data << " ";
            p = p->right;
        }
    }
}
void Binarytree::Postorder(Node *p)
{
    stack<long int> st;
    long int temp;
    while (p != NULL || !st.empty())
    {
        if (p)
        {
            st.push((long int)p);
            p = p->left;
        }
        else
        {
            temp = st.top();
            st.pop();
            if(temp > 0){
                st.push(-temp);
                p = ((Node*)temp)->right;

            }else{
                cout << ((Node*)-temp)->data << " ";
                p =NULL;
            }
        }
    }
}
// void Binarytree::Preorder(Node *p)
// {
//     if (p)
//     {
//         printf(" %d ", p->data);
//         Preorder(p->left);
//         Preorder(p->right);
//     }
// }

// void Binarytree::Inorder(Node *p)
// {
//     if (p)
//     {

//         Inorder(p->left);
//         printf(" %d", p->data);
//         Inorder(p->right);
//     }
// }
// void Binarytree::Postorder(Node *p)
// {
//     if (p)
//     {
//         Postorder(p->left);
//         Postorder(p->right);
//         printf(" %d", p->data);

//     }
// }

void Binarytree::Levelorder(Node *root)
{
   Queue q(100);
   cout << root->data <<" ";
   q.enqueue(root);
   while(!q.isEmpty()){

    root = q.dequeue();

    if(root->left){
        cout << root->left->data<<" ";
        q.enqueue(root->left);
    }
    if(root->right){
        cout << root->right->data<<" ";
        q.enqueue(root->right);
    }
   }
}

int main()
{
    Binarytree bt;
    bt.CreateTree();
    // cout << "\nPre Order ";
    // bt.Preorder(root);
    // cout << "\nIn Order ";
    // bt.Inorder(root);
    // cout << "\nPost Order ";
    // bt.Postorder(root);
    cout << "\nLevel Order ";
    bt.Levelorder(root);
    return 0;
}
