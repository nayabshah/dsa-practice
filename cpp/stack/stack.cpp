#include <iostream>
using namespace std;

class Stack
{
private:
    int *A;
    int size;
    int top;

public:
    Stack()
    {
        size = 4;
        top = -1;
        A = new int[size];
    };
    Stack(int n)
    {
        this->size = n;
        top = -1;
        A = new int[n];
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
    int stackTop(){
        if(top==-1){
            return -1;
        }else{
            return A[top];
        }
    }
    void display(){
        for(int i=top;i>=0;i--){
            cout << A[i]<<" ";
        }
        cout <<endl;
    }
};


int main()
{

    Stack s(6);
    s.push(6);
    s.push(7);
    s.push(8);
    s.push(9);
    s.push(10);
    s.push(10);
    s.push(10);
    s.push(10);

    s.display();
    s.pop();
    s.display();
    return 0;
};
