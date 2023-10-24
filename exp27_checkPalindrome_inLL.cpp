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
   
Node* getMid(Node* head){
        Node* slow = head;
        Node* fast = head->next;
        while(fast!=NULL){
            fast = fast->next;
            if(fast!=NULL){
                fast = fast->next;
                slow = slow->next;
            }
        }
        return slow;
}
Node* reversed(Node* head){
        Node* prev = NULL;
        Node* curr = head;
        while(curr!=NULL){
            Node* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
}
bool isPalindrome(Node *head){
        if(head==NULL || head->next==NULL){
            return true;
        }
        //find middle
        Node* middle = getMid(head);
        Node* temp = middle->next;
        // 1st half linked with reversed 2nd half
        middle->next = reversed(temp);
        //comare 2 halfs
        Node* head1 = head;
        Node* head2 = middle->next;
        while(head2!=NULL){
            if(head1->data!=head2->data){
                temp = middle->next;
                middle->next = reversed(temp);
                return false;
            }
            else{
                head1 = head1->next;
                head2 = head2->next;
            }
        }
        temp = middle->next;
        middle->next = reversed(temp);
        return true;
        
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

int main(){
    Node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 2);
    insertAtTail(head, 1);
    if(isPalindrome(head)){
        cout<<"yes"<<endl;
    }
    else{
        cout<<"no"<<endl;
    }
    return 0;
}