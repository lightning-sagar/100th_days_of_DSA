#include<iostream>
using namespace std;
class MyQueue{
    public:
        int data;
        int size;
        int* arr;
        int front;
        int rear;

        MyQueue(int size){
            this->size = size;
            arr = new int[size];
            front = -1;
            rear = -1;
        }

        void push(int data){
            if((rear+1)%size == front){
                cout<<"Queue is full"<<endl;
                return;
            }
            else if(front == -1){
                front = 0;
                rear = 0;
            }
            else{
                rear = (rear+1)%size;
            }
            arr[rear] = data;
        }

        void pop(){
            if(front == -1){
                cout<<"Queue is empty"<<endl;
                return;
            }
            else if(front == rear){
                front = -1;
                rear = -1;
            }
            else{
                front = (front+1)%size;
            }
        }
        int getRear(){
            if(front == -1){
                cout<<"Queue is empty"<<endl;
                return -1;
            }
            else{
                return arr[rear];
            }
        }

        int getFront(){
            if(front == -1){
                cout<<"Queue is empty"<<endl;
                return -1;
            }
            else{
                return arr[front];
            }
        }

        bool isEmpty(){
            if(front == -1){
                return true;
            }
            else{
                return false;
            }
        }

};