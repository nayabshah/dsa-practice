#include <iostream>
using namespace std;

// self referential structure
struct Node{
    int data;
    Node *next;
};

void display(Node *p){
    while(p != NULL){
        cout << p->data << " ";
        p = p->next;
        cout << endl;
    }
    cout << endl;
};
int main(){
    Node *head = new Node();
    head->data = 10;

    Node *second = new Node();
    second->data = 20;
    head->next = second;
    Node *third = new Node();
    third->data = 30;
    second->next = third;
    display(head);
    return 0;
}
