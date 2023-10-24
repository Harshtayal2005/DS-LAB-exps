#include<iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* next;

    Node(int value){
        val = value;
        this->next = NULL;
    }

};

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
void deleteAtTail(Node* &head){
    Node* temp = head;
    while(temp->next->next!=NULL){
        temp = temp->next;
    }
    Node* tail = temp->next;
    temp->next = NULL;
    free(tail);
    
}
void display(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->val<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    Node* head = NULL;
    insertAtTail(head, 3);
    display(head);
    insertAtTail(head, 4);
    display(head);
    insertAtTail(head, 5);
    display(head);
    deleteAtTail(head);
    display(head);
    return 0;
}