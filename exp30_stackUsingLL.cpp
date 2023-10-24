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
class stack{
    public:
    Node* top;
    stack(){
        top = NULL;
    }

void push(int data){
    Node* temp = new Node(data);
    if(!temp){
        cout<<"stack overflow"<<endl;
        return;
    }
    temp->next = top;
    top = temp;
}
void pop(){
    if(top==NULL){
        cout<<"stack empty"<<endl;
        return;
    }
    top = top->next;
}
bool isEmpty(){
    if(top==NULL){
        return true;
    }
    else
    return false;
}
int peek(){
    if(top==NULL){
        cout<<"stack empty"<<endl;
        return -1;
    }
    return top->data;
}
};
int main(){
    stack s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    cout<<s1.peek()<<endl;
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
    cout<<s1.peek()<<endl;
    if(s1.isEmpty()){
        cout<<"empty"<<endl;
    }
    else{
        cout<<"not empty"<<endl;
    }
    return 0;
}
