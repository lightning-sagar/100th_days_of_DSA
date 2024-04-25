#include<iostream>
using namespace std;
class Cqueue{
    public:
        int size;
    int* arr;
    int front;
    int rear;

    Cqueue(int n) {
        size = n;
        front = -1;
        rear = -1;
        arr = new int[size]; // Allocate memory for the circular queue
    }

    ~Cqueue() {
        delete[] arr; // Deallocate memory for the circular queue
    }
        void pushc(int data){
            if((rear+1)%size == front){
                cout<<"full"<<endl;
            }
            else if(front == -1){
                front = 0;
                rear = 0;
                arr[rear] = data;
            }
            else if(rear == size-1){
                rear = 0;
                arr[rear] = data;
            }
            else{
                rear++;
                arr[rear] = data;
            }
        }

        void popc(){
            if(front == -1){
                cout<<"empty"<<endl;
            }
            else if(front == rear){
                front = -1;
                rear = -1;
            }
            else{
                front++;
            }
        }

        void display(){
            if(front == -1){
                cout<<"empty"<<endl;
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
    Cqueue q(5);
    q.pushc(10);
    q.pushc(20);
    q.pushc(30);
    q.pushc(40);

    q.display();
    q.popc();
    q.display();
    return 0;
}