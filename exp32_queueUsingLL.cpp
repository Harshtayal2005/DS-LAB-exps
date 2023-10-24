#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        this->data = val;
        this->next = NULL;
    }
};
class queue{
    public:
    Node* front;
    Node* rear;

    queue(){
        front = NULL;
        rear = NULL;
    }

    void push(int data){
        Node* temp = new Node(data);
        if(!temp){
            cout<<"queue is full"<<endl;
            return;
        }
        if(rear==NULL){
            front = temp;
            rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }
    void pop(){
        if(front==NULL){
            cout<<"queue is empty"<<endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        if(front == NULL){
            rear = NULL;
        }
        free(temp);
    }
    int peek(){
        if(front==NULL){
            cout<<"queue is empty"<<endl;
            return -1;
        }
        return front->data;
    }
    bool isEmpty(){
        if(front==NULL){
            return true;
        }
        else
        return false;
    }
};
int main(){
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    cout<<q.peek()<<endl;
    if(q.isEmpty()){
        cout<<"empty"<<endl;
    }
    else
    cout<<"not empty"<<endl;
    return 0;
}