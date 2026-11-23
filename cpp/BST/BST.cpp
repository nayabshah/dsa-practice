// Online C++ compiler (editor)
// Write and run C++ online using this editor.

#include <iostream>
#include <stdio.h>
using namespace std;

class Node{
public:
    Node *left;
    int data;
    Node *right;
    Node(int value){
        data = value;
        left = nullptr;
        right= nullptr;
    }
    
}*root=nullptr;

void Insert(int key){
    Node *t =root;
    Node *r,*p;
    if(!root){
        p = new Node(key);
        
        root = p;
        return;
    }
    while(t){
        r = t;
        if(key < t->data)
            t = t->left;
        else if(key > t->data)
            t =t->right;
        else
            return;
    }
    p = new Node(key);
    if(key < r->data) r->left =p;
    else r->right=p;
}

void Inorder(Node *p){
    if(p){
        Inorder(p->left);
        cout << p->data<<" ";
        Inorder(p->right);
    }
        
}

Node *Search(int key){
    Node *t = root;
    while(t){
        if(key ==t ->data)
            return t;
        else if(key <t->data)
            t=t->left;
        else
            t = t->right;
    }
    return nullptr;
}

int main() {
    // Write C++ code here
    Insert(10);
    Insert(5);
    Insert(20);
    Insert(8);
    Insert(30);
    Inorder(root);
    cout<< "\n";
    return 0;
}
