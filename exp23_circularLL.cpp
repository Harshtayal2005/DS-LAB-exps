#include<iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* next;

    Node(int data){
        val = data;
        next = NULL;
    }
};

class CircularLinkedList{
    public:
    Node* head;

    CircularLinkedList(){
        head = NULL;
    }

    void insertAtStart(int val){
    Node* new_node = new Node(val);
    if(head==NULL){
        head = new_node;
        head->next = head;
        return ;
    }
    Node* tail = head;
    while(tail->next!=head){
        tail = tail->next;
    }
    new_node->next = head;
    tail->next = new_node;
    head = new_node;
    return;
}

void insertAtEnd(int val){
    Node* new_node = new Node(val);
    if(head==NULL){
        head = new_node;
        head->next = head;
        return;
    }
    Node* tail = head;
    while(tail->next!=head){
        tail = tail->next;
    }
    tail->next = new_node;
    new_node->next = head;
    return;
}

void printCircular(){
    Node* temp = head;
    for(int i=0; i<=15; i++){
        cout<<temp->val<<"->";
        temp = temp->next;
    }
    cout<<endl;
}

void display(){
    if(head==NULL){
        return ;
    }
    Node* temp = head;
    do{
        cout<<temp->val<<"->";
        temp = temp->next;
    } while(temp!=head);
    cout<<"NULL";
    cout<<endl;
    return;
}

void deleteAtStart(){
    if(head==NULL){
        return ;
    }
    Node* temp = head;
    Node* tail = head;
    
        while(tail->next!=head){
            tail = tail->next;
        }
        tail->next = head->next;
        head = head->next;
        delete temp;
        return;
    
    
}

void deleteAtEnd(){
    if(head==NULL){
        return;
    }
    Node* tail = head;
    while(tail->next->next!=head){
        tail = tail->next;
    }
    Node* temp = tail->next;
    tail->next = head;
    delete temp;

}

};

int main(){ 
    CircularLinkedList cll;
    cll.insertAtEnd(4);
    cll.insertAtEnd(5);
    cll.insertAtEnd(6);
    cll.insertAtEnd(7);
    cll.deleteAtEnd();
    cll.display();
    return 0;
}