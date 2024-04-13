#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node() {
        data = 0;
        next = NULL;
    }
    node(int d) {
        data = d;
        next = NULL;
    }
};

class stack : public node {
public:
    node* head;
    int size;
    int top_idx; 

    stack(int size) {
        this->size = size;
        head = NULL;
        top_idx = -1;
    }

    void push(int data) {
        if (top_idx < size - 1) {
            top_idx++;
            node* newnode = new node(data);
            newnode->next = head;
            head = newnode;
        }
        else {
            cout << "Stack overflow" << endl;
        }
    }

    void pop() {
        if (top_idx >= 0) {
            top_idx--;
            node* temp = head;
            head = head->next;
            delete temp;
        }
        else {
            cout << "Stack underflow" << endl;
        }
    }

    int top() {  
        if (top_idx >= 0) {
            return head->data;
        }
        else {
            cout << "Stack is empty" << endl;
            return -1;
        }
    }
};

int main() {
    stack s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    cout << s.top() << endl; 
    s.pop();
    cout << s.top() << endl; 
}
