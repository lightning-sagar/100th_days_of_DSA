#include<iostream>
using namespace std;
class duoly{
    public:
    int data;
    int front;
    int rear;
    int size;
    int* arr;
    duoly(int n){
        size = n;
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
    int peek(){
        if(front == -1){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        else{
            return arr[front];
        }
    }
    void display(){
        if(front == -1){
            cout<<"Queue is empty"<<endl;
            return;
        }
        else{
            for(int i=front;i<=rear;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
    }
};
int main(){
    duoly d(5);
    d.push(10);
    d.push(20);
    d.push(30);
    d.push(40);
    d.push(50);
    d.display();
    d.pop();
    d.display();
    cout<<d.peek();
}