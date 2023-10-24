#include<iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* next;

    Node(int value){
        this->val = value;
        this->next = NULL;
    }

};

void insertAtHead(Node* &head, int val){
    Node* new_node = new Node(val);
    new_node->next = head;
    head = new_node;

}
void deleteAtHead(Node* &head){
    Node* temp = head;
    head = head->next;
    temp->next = NULL;
    free(temp); // free() function is used to deallocate the memory which was allocated "dynamically".
   
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
    deleteAtHead(head);
    display(head);
    return 0;
}