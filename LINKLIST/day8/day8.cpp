#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node() {
        this->data = 0;
        this->next = NULL;
    }
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void prints(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    } 
}

void insertathead(Node* &head, Node* &tail, int data) {
    if(head == NULL) {
        Node* newnode = new Node(data);
        head = newnode;
        tail = newnode;
        return;
    }
    Node* newnode = new Node(data);
    newnode->next = head;
    head = newnode;
}

int findlength(Node* head){
    int i =0;
    Node* temp = head;
    while(temp != NULL){
        temp = temp->next;
        i++;
    }
    return i;
}

Node* swapinpair(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node* curr = head;
    head = curr->next;
    
    curr->next = swapinpair(head->next);
     head->next = curr;
    return head;
}
    Node* reversef(Node* head){
        Node* prev = NULL;
        Node* current = head;
        Node* forward = current->next;
        while(current!=NULL){
            forward = current->next;
            current->next = prev;
            prev = current;
            current = forward;
        }
        return prev;
    }
bool isPalindrome(Node* head) {
        if(head == NULL){
            return false;
        }
        if(head->next ==NULL) return false;
        Node* slow = head;
        Node* fast = head->next;
        while(fast != NULL){
            fast = fast->next;
            if(fast!=NULL){
                fast = fast->next;
                slow = slow->next;
            }
        }
        // now slow is our mid
        Node* reverse = reversef(slow->next);
        //now start comparing
        Node*t1 = head;
        Node*t2 = reverse;
        while(t2 !=NULL){
            if(t1->data == t2->data){
                t1 = t1->next;
                t2 = t2->next;
            }
            else{
                return false;
            }
        }
        return true;
    }
Node* deleteDuplicates(Node* head) {
    if (head == NULL) return head;        
    Node* curr = head;
    Node* forward = curr->next;
    
    while (curr != NULL && forward != NULL) {
        if (curr->data == forward->data) {
            Node* temp = forward;
            forward = forward->next;
            delete temp;
            curr->next = forward; 
        } else {
            curr = curr->next;
            forward = forward->next;
        }
    }
    return head;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    insertathead(head, tail, 10);
    insertathead(head, tail, 10);
    insertathead(head, tail, 20);
    insertathead(head, tail, 20);
    insertathead(head, tail, 20);
    insertathead(head, tail, 30);
    insertathead(head, tail, 40);
    insertathead(head, tail, 40);
    prints(head);
    cout<<"\n";
    cout<<isPalindrome(head);
    cout<<"\n";

    head = deleteDuplicates(head);
    prints(head);

}