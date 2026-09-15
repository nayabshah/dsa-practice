#include <iostream>
using namespace std;

// ToeplitxMatrix matrix
// 5 6 7 8 9
// 4 5 6 7 8
// 3 4 5 6 7
// 2 3 4 5 6
// 1 2 3 4 5
// M[i,j] = M[i-1,j-1]
// Element n+n1

class ToeplitxMatrix
{
private:
    int *A;
    int n;

public:
    ToeplitxMatrix()
    {
        n = 2;
        A = new int[2 + 2 - 1];
    };
    ToeplitxMatrix(int n)
    {
        this->n = n;
        A = new int[n + n - 1];
    };
    ~ToeplitxMatrix()
    {
        delete[] A;
    };
    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();

    int GetDimension() { return n; }
};

void ToeplitxMatrix::Set(int i, int j, int x)
{
    if (i <= j)
    {
        A[j - i] = x;
    }
    else if (i > j)
    {
        A[n + i - j - 1] = x;
    }
};

int ToeplitxMatrix::Get(int i, int j)
{
    if (i <= j)
    {
        // return A[i*(i-1)/2+j-1]
        return A[j - i];
    }
    else if (i > j)
    {
        return A[n + i - j - 1];
    }
    return 0;
};

void ToeplitxMatrix::Display()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i <= j)
            {
                // cout<<A[i*(i-1)/2+j-1];
                cout << A[j - i] << " ";
            }
            else if (i > j)
            {
                cout << A[n + i - j - 1] << " ";
            }
        }
        cout << endl;
    }
};
int main()
{
    int d;
    cout << "Enter Dimensions: ";
    cin >> d;
    ToeplitxMatrix lm(d);
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
