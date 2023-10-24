#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

Node *getMiddle(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    if(head->next->next==NULL){
        return head->next;
    }
    Node* slow = head;
    Node* fast = head->next;
    while(fast!=NULL){
        fast = fast->next;
        if(fast!=NULL){
            fast = fast->next;
        }
        slow = slow->next;
    }
    return slow;
}
Node *findMiddle(Node *head) {
    return getMiddle(head);
}

void insertAtTail(Node* &head, int val){
    Node* new_node = new Node(val);
    Node* temp = head;
    if(head==NULL){
        head = new_node;
        return ;
    }
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = new_node;
}

int main(){
    Node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    Node* mid = findMiddle(head);
    cout<<mid->data<<endl;
    return 0;
}