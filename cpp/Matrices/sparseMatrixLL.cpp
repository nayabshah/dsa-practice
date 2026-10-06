#include <iostream>
using namespace std;
class Node
{
public:
    int col;
    int val;
    Node *next;
};
class Sparse
{
private:
    int m;
    int n;
    Node **A[];

public:
    Sparse(int m, int n)
    {
        this->m = m;
        this->n = n;
        this->A=new Node*[m];
        for (int i = 0; i < m; i++)
            {
                A[i] = new Node();
            }
    };

};

istream & operator>>(istream &is, Sparse &s)
{
    cout << "Enter non-zero elements (column, value):" << endl;
    for (int i = 0; i < s.m; i++)
    {
        cin >> s.ele[i].i >> s.ele[i].j >> s.ele[i].x;
    }
    return is;
}

int main()
{
    Sparse s1(5, 6, 7);
    // Sparse s2(5, 5, 5);
    cin >> s1;
    // cin >> s2;
    // Sparse sum = s1 + s2;
    cout << "First Matrix" << endl
         << s1;
    // cout << "Second MAtrix" << endl
    //      << s2;
    // cout << "Sum Matrix" << endl
    //      << sum;
    return 0;
}
