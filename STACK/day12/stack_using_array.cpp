#include<iostream>
using namespace std;
class stack{
    public:
        int *arr;
        int size;
        int top;
        stack(int size){
            this->size = size;
            arr = new int[size];
            top = -1;
        }
        void push(int data){
            if(size-top>1){// space h
                top++;
                arr[top] = data;
            }
            else{
                cout<<"Stack overflow"<<endl;
            }
        }
        void pop(){
            if(top>=0){
                top--;
            }
            else{
                cout<<"Stack underflow"<<endl;
            }
        }
        int peek(){
            if(top>=0){
                return arr[top];
            }
            else{
                cout<<"Stack is empty"<<endl;
                return -1;
            }
        }
        bool isEmpty(){
            if(top==-1){
                return true;
            }
            else{
                return false;
            }
        }
        int getsize(){
            return top+1;
        }
};
int main(){
    stack s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    cout<<s.peek()<<endl;
    s.pop();
    cout<<s.peek()<<endl;
    cout<<s.getsize()<<endl;
    cout<<s.isEmpty();
}