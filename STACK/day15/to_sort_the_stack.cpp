#include<iostream>
#include<stack>
using namespace std;
void insetsort(stack<int> &s,int target){
    if(s.empty()){
        s.push(target);
        return;
    }
    if(s.top()<=target){
        s.push(target);
        return;
    }
    int topele = s.top();
    s.pop();
    insetsort(s,target);
    s.push(topele);
}

void sort(stack<int> &s){
    if(s.empty()){
        return;
    }
    int target = s.top();
    s.pop();
    sort(s);
    insetsort(s,target);
}
int main(){
    stack<int>s;
    s.push(80);
    s.push(50);
    s.push(30);
    s.push(70);
    s.push(20);
    // insetsort(s,40);
    // while(!s.empty()){
    //     cout<<s.top()<<endl;
    //     s.pop();
    // }

    sort(s);
    cout<<s.empty();

    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
}