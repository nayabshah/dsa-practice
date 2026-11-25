// Online C++ compiler (editor)
// Write and run C++ online using this editor.

#include <iostream>
using namespace std;

void pattern1(int n){
    
    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}
void pattern2(int n){
    
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}
void pattern3(int n){
    for(int i=1;i<n;i++){
        for(int j=1;j<=i;j++){
            cout<<j;
        }
        cout<<endl;
    }
}
void pattern4(int n){
    for(int i=1;i<n;i++){
        for(int j=1;j<=i;j++){
            cout<<i;
        }
        cout<<endl;
    }
}

void pattern5(int n){
    for(int i=0;i<n;i++){
        for(int j=1;j<(n-i);j++){
            cout<<"*";
        }
        cout<<endl;
    }
}

void pattern6(int n){
    for(int i=0;i<n;i++){
        for(int j=1;j<(n-i);j++){
            cout<<j;
        }
        cout<<endl;
    }
}

void pattern7(int n){
    for(int i=0;i<n;i++){
        for(int j=1;j<(n-i);j++){
            cout<<" ";
        }
        for(int j =1;j<=i*2+1;j++){
            cout<<"*";
        }
        
        cout<<endl;
    }
}


void pattern8(int n){
    for(int i=0;i<n;i++){
        for(int j=1;j<=i;j++){
            cout<<" ";
        }
        for(int j =(n*2-1)-(i*2);j>0;j--){
            cout<<"*";
        }
        for(int j=1;j<=i;j++){
            cout<<" ";
        }
        cout<<endl;
    }
}

void pattern9(int n){
    for(int i=0;i<n;i++){
        for(int j=1;j<(n-i);j++){
            cout<<" ";
        }
        for(int j =1;j<=i*2+1;j++){
            cout<<"*";
        }
        
        cout<<endl;
    }
    for(int i=0;i<n;i++){
        for(int j=1;j<=i;j++){
            cout<<" ";
        }
        for(int j =(n*2-1)-(i*2);j>0;j--){
            cout<<"*";
        }
        for(int j=1;j<=i;j++){
            cout<<" ";
        }
        cout<<endl;
    }
}

void pattern10(int n){
    
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<"*";
        }
        cout<<endl;
    }

    for(int i=0;i<n-1;i++){
        for(int j=1;j<(n-i);j++){
            cout<<"*";
        }
        cout<<endl;
    }
}
void pattern11(int n){
    for(int i = 0;i<n;i++){
        for(int j=0;j<=i;j++){
            if (j % 2 == 0 ^ i%2==0) {
                cout << 0;
            } else {
                cout << 1;
            }
        }
        cout<< endl;
    }
}

void pattern12(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout << j;
        }
        for(int j=1;j<(n-i)*2+1;j++){
            cout << " ";
        }
      for(int j=i;j>0;j--){
            cout << j;
        }
        cout<< endl;
    }
   
}
int main() {
    pattern12(2);
    
    return 0;
}
