
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(){
        this->data = 0;
        this->next = NULL;
    }
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void prints(Node* &head){
    int i = 0;
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
        i++;
    } 
}

void insertathead(Node* &head,Node* &tail,int data){
    //check condition if head or tail is node..... if yes then...
    if(head == NULL){
        Node* newnode = new Node(data);
        head = newnode;
        tail = newnode;
        return;
    }
    Node* newnode = new Node(data);
    newnode->next = head;
    head = newnode;
}

Node* reverse(Node* &head, Node* &tail){
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = head;
    while(curr != NULL){
        forward = curr->next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}
 
bool verify(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL  ){
        fast = fast->next;
        if(fast!= NULL){
            fast = fast->next;
            slow = slow->next;
            if(slow == fast){
                return true;
            }
        }        
    }
    return false;
}

Node* onestep(Node* &fast, Node* &slow){
    while(fast!=NULL){
        fast = fast->next;
            slow = slow->next;
        if(slow == fast){
            return slow;
        }
    }
}


Node* starting(Node* &head){

    Node* slow = head;
    Node* fast = head;
    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        if(slow == fast){
            Node* start = onestep(fast,head);
            return start;
        }
    }
    return slow;
}

Node* remove(Node* &head) {
    Node* slow = head;
    Node* fast = head;
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)  
            break;
    }
    if (slow != fast)
        return NULL;

    slow = head;
    while (slow->next != fast->next) {
        slow = slow->next;
        fast = fast->next;
    }

    fast->next = NULL;

    return slow->next; 
}


int main(){
    Node* head = NULL;
    Node* tail = NULL;
    //insertion in linklist
    Node* one = new Node(1);
    Node* two = new Node(2);
    Node* three = new Node(3);
    Node* four = new Node(4);
    Node* five = new Node(5);
    Node* six = new Node(6);

    head = one;
    tail = six;
    one->next = two;
    two->next = three;
    three->next = four;
    four->next = five;
    five->next = six;
    six->next = three;
    // cout<<verify(head)<<endl;

    //to get starting of loop
    head = starting(head);
    cout<<head->data<<endl;
    // prints(head);

    //to remove loop
    head  = remove(head);
    prints(head);
    return 0;
 }
