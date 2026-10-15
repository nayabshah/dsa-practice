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
        size = 7;
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
int isOprand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^' || x == '(' || x == ')')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int outStackPrecedence(char x)
{
    if (x == '+' || x == '-')
    {
        return 1;
    }
    else if (x == '*' || x == '/')
    {
        return 3;
    }
    else if (x == '^')
    {
        return 6;
    }
    else if (x == '(')
    {
        return 7;
    }
    return 0;
}

int inStackPrecedence(char x)
{
    if (x == '+' || x == '-')
    {
        return 2;
    }
    else if (x == '*' || x == '/')
    {
        return 4;
    }
    else if (x == '^')
    {
        return 5;
    }
    return 0;
}

char *convert(char *infix)
{
    Stack st;
    char *postfix = new char[strlen(infix) + 1];
    int i = 0, j = 0;
    while (infix[i])
    {
        if (isOprand(infix[i]))
        {
            postfix[j++] = infix[i++];
        }
        else
        {
            if (st.isEmpty())
            {
                st.push(infix[i++]);
            }
            else if (outStackPrecedence(infix[i]) > inStackPrecedence(st.stackTop()))
            {
                st.push(infix[i++]);
            }
            else if (outStackPrecedence(infix[i]) == inStackPrecedence(st.stackTop()))
            {
                st.pop();
                i++;
            }
            else
            {
                postfix[j++] = st.pop();
            }
        }
    }
    while (!st.isEmpty())
    {
        if (st.stackTop() == '(' )
            st.pop();
        else
            postfix[j++] = st.pop();
    }
    return postfix;
}

int main()
{
    char *infix = "3*5+6/2-4";

    char *postfix;
    postfix = convert(infix);
    cout << postfix << " ";

    return 0;
};
