#include <iostream>
#include <cstring>
using namespace std;

class Stack
{

public:
    char *A;
    int size;
    int top;
    Stack()
    {
        size = 4;
        top = -1;
        A = new char[size];
    };
    Stack(int n)
    {
        this->size = n;
        top = -1;
        A = new char[n];
    };
    ~Stack()
    {
        delete[] A;
    };
    int isEmpty()
    {
        return top == -1;
    }
    int isFull()
    {
        return top == size - 1;
    }

    void push(int val)
    {
        if (isFull())
        {
            return;
        }
        else
        {
            top++;
            A[top] = val;
        }
    }
    int pop()
    {
        int x = -1;
        if (isEmpty())
        {
            return x;
        }
        else
        {
            x = A[top--];
        }
        return x;
    }
    int peak(int idx)
    {
        int x = -1;
        if (top - idx + 1 < 0)
        {
            return -1;
        }
        else
        {
            return A[top - idx + 1];
        }
    }
    int stackTop()
    {
        if (top == -1)
        {
            return -1;
        }
        else
        {
            return A[top];
        }
    }
    void display()
    {
        for (int i = top; i >= 0; i--)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};

int isBalance(char *exp)
{
    Stack st(strlen(exp));

    for (int i = 0; i < st.size; i++)
    {
        if (exp[i] == '(')
            st.push(exp[i]);
        if (exp[i] == ')')
        {
            if (st.isEmpty())
            {
                return 0;
            }

            st.pop();
        }
    }
    if (st.isEmpty())
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{

    cout<<isBalance("((a+b)*(a-b))");

    return 0;
};
