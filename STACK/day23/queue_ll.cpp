#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int d){
        data = d;
        next = NULL;
    }
};
class queue{
    public:
    node* front;
    node* back;
    queue(){
        front = NULL;
        back = NULL;
    }
    void push(int data){
        node* n = new node(data);
        if(front == NULL){
            front = n;
            back = n;
        }
        else{
            back->next = n;
            back = n;
        }
    }
    void pop(){
        if(front == NULL){
            return;
    }}
    int peek(){
        if(front == NULL){
            return -1;
        }
        return front->data; 
    }
    bool empty(){
        if(front == NULL){
            return true;
        }
        return false;
    }
};
        