#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int>& s,int temp){
    if(s.empty()){
        s.push(temp);
        return;
    }
    int val = s.top();
    s.pop();
    solve(s,temp);
    s.push(val);
}
void reverse(stack<int>& s){
    if(s.empty()){
        return;
    }
    int temp = s.top();
    s.pop();
    reverse(s);
    solve(s,temp);
}
void display(stack<int>s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}
int main(){
    stack<int>s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    display(s);

    reverse(s);
    display(s);
}
// its just a comm