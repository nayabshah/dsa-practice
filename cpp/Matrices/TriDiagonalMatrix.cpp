#include <iostream>
using namespace std;

// TridiagonalMatrix matrix
// 5 3 0 0 0
// 4 5 3 0 0
// 0 4 5 3 0
// 0 0 4 5 3
// 0 0 0 4 5

// Main Diagonal"" 5 i-j =0
// Upper ""3         i-j =1
// Lower ""4         i-j =-1
//                   |i-j|<=1
// M[i,j] =non-zero if |i-j|<=1
// M[i.j] =0 if |i-j|>1

class TridiagonalMatrix
{
private:
    int *A;
    int n;

public:
    TridiagonalMatrix()
    {
        n = 2;
        A = new int[2 * (2 + 1) / 2];
    };
    TridiagonalMatrix(int n)
    {
        this->n = n;
        A = new int[3 * n - 2];
    };
    ~TridiagonalMatrix()
    {
        delete[] A;
    };
    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();

    int GetDimension() { return n; }
};

void TridiagonalMatrix::Set(int i, int j, int x)
{
    if ((i - j) == 1)
    {
        A[i - 2] = x;
    }
    else if ((i - j) == 0)
    {
        A[n - 1 + i - 1] = x;
    }
    else if ((i - j) == -1)
    {
        // A[i*(i-1)/2+j-1] = x;
        A[2 * n - 1] = x;
    }
};

int TridiagonalMatrix::Get(int i, int j)
{
    if ((i - j) == 1)
    {
        // cout << A[i - 2] << " ";
        return A[i - 2];
    }
    else if ((i - j) == 0)
    {
        return A[n - 1 + i - 1];
    }
    else if ((i - j) == -1)
    {
        // A[i*(i-1)/2+j-1] = x;
        return A[2 * n - 1];
    }
    else
        return 0;
};

void TridiagonalMatrix::Display()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if ((i - j) == 1)
            {
                cout << A[i - 2] << " ";
            }
            else if ((i - j) == 0)
            {
                cout << A[n - 1 + i - 1] << " ";
            }
            else if ((i - j) == -1)
            {
                // A[i*(i-1)/2+j-1] = x;
                cout << A[2 * n - 1] << " ";
            }
            else
                cout << "0 ";
        }
        cout << endl;
    }
};
int main()
{
    int d;
    cout << "Enter Dimensions: ";
    cin >> d;
    TridiagonalMatrix lm(d);
    int x;
    cout << "Enter All Elements: ";
    for (int i = 1; i <= d; i++)
    {
        for (int j = 1; j <= d; j++)
        {
            cin >> x;
            lm.Set(i, j, x);
        };
    };
    lm.Display();
    return 0;
};
