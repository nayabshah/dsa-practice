#include <iostream>
#include <cmath>

using namespace std;
class Term{
public:
    int coeff;
    int exp;
};
class Polynomial{
public:
    int n;
    Term *t;
};


int main(){
    Polynomial p;
    cout<< "No of non-zero terms: ";
    cin>>p.n;
    p.t = new Term[p.n];
    for(int i=0;i<p.n;i++){
        cout<<"Enter coeff and exp of term "<<i+1<<": ";
        cin>>p.t[i].coeff>>p.t[i].exp;
    }
    cout<<"Enter the value of x: ";
    double x;
    cin>>x;
    for(int i=0;i<p.n;i++){
        double sum = p.t[i].coeff* std::pow(x, p.t[i].exp);
    };
    return 0;
}
