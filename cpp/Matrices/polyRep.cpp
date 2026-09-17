#include <iostream>
#include <cmath>

using namespace std;
class Term
{
public:
    int coeff;
    int exp;
};
class Polynomial
{
public:
    int n;
    Term *t;
    void Set(Polynomial &p);
    void Display(Polynomial &p);

    
};
Polynomial Add(Polynomial &p1, Polynomial &p2)
{
    int i, j, k = 0;

   Polynomial p3;
    p3.n =p1.n + p2.n;
    p3.t = new Term[p3.n];
    while (i < p1.n && j < p2.n)
    {
        if (p1.t[i].exp > p2.t[j].exp)
        {
            p3.t[k++] = p1.t[i++];
        }
        else if (p1.t[i].exp < p2.t[j].exp)
        {
            p3.t[k++] = p2.t[j++];
        }
        else
        {
            p3.t[k] = p1.t[i];
            p3.t[k++].coeff = p1.t[i++].coeff + p2.t[j++].coeff;
        }
    }
    for (; i < p1.n; i++){
        p3.t[k++] = p1.t[i];
    }

    for (; j < p2.n; j++){
        p3.t[k++] = p2.t[j];
    }

    p3.n = k;
    return p3;
};
void Polynomial::Set(Polynomial &p)
{
    cout << "Number of terms: ";
    cin >> p.n;
    p.t = new Term[p.n];
    for (int i = 0; i < p.n; i++)
    {
        cout << "Enter coeff and exp of term " << i + 1 << ": ";
        cin >> p.t[i].coeff >> p.t[i].exp;
    }
    cout << endl;
}

void Display(Polynomial &p)
{
    for (int i = 0; i < p.n; i++)
    {
        cout << p.t[i].coeff << "x^" << p.t[i].exp;
        if (i != p.n - 1)
        {
            cout << " + ";
        }
    }
    cout << endl;
};

int main()
{
    Polynomial p1, p2;
    p1.Set(p1);
    p2.Set(p2);
    Display(p1);
    Display(p2);
    Polynomial p3;
    p3 = Add(p1, p2);
    Display(p3);
    return 0;
}

