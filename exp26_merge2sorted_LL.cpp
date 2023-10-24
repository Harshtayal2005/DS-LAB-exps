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
void mergeLists(Node* &first, Node* &second){
    Node *curr1 = first;
    Node *next1 = curr1->next;
    Node *curr2 = second;
    while(next1!=NULL && curr2!=NULL){
        if(curr2->data<=next1->data && curr2->data>=curr1->data){
            Node *next2 = curr2->next;
            curr2->next = next1;
            curr1->next = curr2;
            curr1 = curr2;
            curr2 = next2;
        }
        else{
            curr1 = next1;
            next1 = next1->next;
        }
    }
    while(curr2!=NULL){
        curr1->next = curr2;
        curr1 = curr2;
        curr2 = curr2->next;
    }
}
Node* sortTwoLists(Node* first, Node* second)
{
    if(first==NULL){
        return second;
    }
    if(second==NULL){
        return first;
    }
    if(first->data<=second->data){
        mergeLists(first, second);
        return first;
        
    }
    else{
        mergeLists(second, first);
        return second;
        
    }
}
void insertAtTail(Node* &head, int val){
    Node* new_node = new Node(val);
    if(head==NULL){
        head = new_node;
        return;
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new_node;
}
void print(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    Node* first = NULL;
    insertAtTail(first, 3);
    insertAtTail(first, 0);
    insertAtTail(first, 1);
    insertAtTail(first, 7);
    insertAtTail(first, 4);
    Node* second = NULL;
    insertAtTail(second, 2);
    insertAtTail(second, 10);
    insertAtTail(second, 9);
    insertAtTail(second, 13);
    insertAtTail(second, 12);
    first = sortTwoLists(first, second);
    print(first);
    return 0;
}