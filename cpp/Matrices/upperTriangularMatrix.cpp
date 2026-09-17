#include <iostream>
using namespace std;

// UpperTri matrix
// 4 4 4 5
// 0 8 4 8
// 0 0 9 4
// 0 0 0 5
// M[i,j] = 0 if i > j
// M[i,j]=non-zero if i<=j
// stored in Row-major
// n*(i-1)-(i-2)*(i-1)/2+j-i
// stored in Col-major
// j*(j-1)/2+i-1

class UpperTri
{
private:
    int *A;
    int n;
public:
    UpperTri(){
        n=2;
        A=new int[2*(2+1)/2];
    };
    UpperTri(int n){
        this->n=n;
        A=new int[n*(n+1)/2];

    };
    ~UpperTri(){
        delete []A;

    };
    void Set(int i,int j,int x);
    int Get(int i,int j);
    void Display();

    int GetDimension(){return n;}
};

void UpperTri::Set(int i,int j,int x){
    if(i<=j){
        A[j*(j-1)/2+i-1] = x;
        // A[(i-1)*n-(i-2)*(i-1)/2+j-i] = x;
    }
};

int UpperTri::Get(int i,int j){
    if(i<=j){
        return A[j*(j-1)/2+i-1];
        // return A[(i-1)*n-(i-2)*(i-1)/2+j-i];

    }
    return 0;
};

void UpperTri::Display(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i<=j)
                cout<<A[j*(j-1)/2+i-1]<<" ";
                // cout<<A[(i-1)*n-(i-2)*(i-1)/2+j-i]<<" ";
            else
                cout<<"0 ";

        }
        cout<<endl;
    }
};
int main(){
   int d;
   cout<<"Enter Dimensions: ";
   cin>>d;
   UpperTri lm(d);
   int x;
   cout<<"Enter All Elements: ";
   for(int i=1;i<=d;i++){
    for(int j=1;j<=d;j++){
        cin>>x;
        lm.Set(i,j,x);
    };
   };
   lm.Display();
    return 0;
};
