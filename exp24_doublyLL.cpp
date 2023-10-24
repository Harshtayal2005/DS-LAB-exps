#include<iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* prev;
    Node* next;

    Node(int data){
        val = data;
        prev = NULL;
        next = NULL;
    }
};

class DoublyLinkedList{
    public:
    Node* head;
    Node* tail;

    DoublyLinkedList(){
        head = NULL;
        tail = NULL;
    }

    void insertAtStart(int val){
        Node* new_node = new Node(val);
        if(head==NULL){
            head = new_node;
            tail = new_node;
            return ;
        }
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
        return;
    }

    void insertAtEnd(int val){
        Node* new_node = new Node(val);
        if(head==NULL){
            head = new_node;
            tail = new_node;
            return ;
        }
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
        return ;
    }

    void insertAtPosition(int pos, int val){
        Node* new_node = new Node(val);
        Node* temp = head;
        int curr_pos = 1;
        while(curr_pos!=pos-1){
            curr_pos++;
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
        new_node->next->prev = new_node;
        new_node->prev = temp;
        return ;
    }

    void deleteAtStart(){
        if(head==NULL){
            return ; 
        }
        Node* temp = head;
        head = head->next;
        if(head!=NULL){
        head->prev = NULL;
        }
        else{
            tail = NULL;
        }
        delete temp;
        return ;
    }

    void deleteAtEnd(){
        if(tail==NULL){
            return ;
        }
        Node* temp = tail;
        tail = tail->prev;
        if(tail!=NULL){
        tail->next = NULL;
        }
        else{
            head = NULL;
        }
    
        delete temp;
        return ;
    }

    void deleteAtPosition(int pos){
        Node* temp = head;
        int curr_pos=1;
        while(curr_pos!=pos){
            curr_pos++;
            temp = temp->next;
        }
        Node* posNode = temp;
        temp->prev->next = temp->next; 
        temp->next->prev = temp->prev;
        temp = temp->next;
        delete posNode;
        return ;
        
    }

    void display(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->val<<"<->";
            temp = temp->next;
        }
        cout<<endl;
        return ;
    }
};

int main(){
    // Node* new_node = new Node(3);
    DoublyLinkedList dll;
    // dll.head = new_node;
    // dll.tail = new_node;
    dll.insertAtStart(1);
    dll.display();
    dll.deleteAtStart();
    dll.display();
    dll.insertAtEnd(2);
    dll.display();
    dll.insertAtEnd(5);
    dll.display();
    dll.insertAtEnd(4);
    dll.display();
    dll.insertAtEnd(9);
    dll.display();
    dll.deleteAtPosition(3);
    dll.display();
    dll.deleteAtStart();
    dll.display();
    dll.deleteAtEnd();
    dll.display();
    dll.insertAtPosition(3, 3);
    dll.display();
    return 0;
}