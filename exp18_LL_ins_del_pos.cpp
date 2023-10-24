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

void insertAtHead(Node* &head, int val){
    Node* new_node = new Node(val);
    new_node->next = head;
    head = new_node;

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

void insertAtPosition(Node* &head, int val, int pos){
    Node* new_node = new Node(val);
    Node* temp = head;
    int current_pos = 0;
    if(pos==0){
        insertAtHead(head, val);
        return;
    }
    while(current_pos!=pos-1){
        temp = temp->next;
        current_pos++;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

void deleteAtHead(Node* &head){
    Node* temp = head;
    head = head->next;
    temp->next = NULL;
    free(temp); // free() function is used to deallocate the memory which was allocated "dynamically".
   
}

void deleteAtPosition(Node* &head, int pos){
    
    if(pos == 0){
        deleteAtHead(head);
        return ;
    }
    Node* temp = head;
    int curr_pos = 0;
    while(curr_pos!=pos-1){ // check if the position is greater than the number of nodes in the list
        temp = temp->next;
        curr_pos++;
    }
    Node* posNode = temp->next;
    temp->next = temp->next->next;
    free(posNode);
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
    insertAtHead(head, 2);
    display(head);
    insertAtTail(head, 3);
    display(head);
    insertAtTail(head, 4);
    display(head);
    insertAtTail(head, 5);
    display(head);
    deleteAtPosition(head, 0);
    display(head);
    deleteAtHead(head);
    display(head);
    return 0;
}