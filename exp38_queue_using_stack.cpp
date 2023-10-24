#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
public:
    MyQueue() {
        
    }
    
    stack<int> ip, op;
    int peekx = -1;

    void push(int x) {
        if(ip.empty()){
            peekx = x;
        }
        ip.push(x);
    }
    
    int pop() {
        if(!op.empty()){
            int x = op.top();
            op.pop();
            return x;
        }
        else{
            while(!ip.empty()){
                op.push(ip.top());
                ip.pop();
            }
            int x = op.top();
            op.pop();
            return x;
        }
    }
    
    int peek() {
        if(!op.empty()){
            return op.top();
        }
        else{
            return peekx;
        }
    }
    
    bool empty() {
        return ip.empty() && op.empty();
    }
};

int main(){
    MyQueue q;
    
    q.push(1);
    q.push(2);
    
    cout << "Front of the queue: " << q.peek() << endl; // Output: 1
    
    q.push(3);
    
    cout << "Front of the queue: " << q.peek() << endl; // Output: 1
    
    cout << "Dequeue: " << q.pop() << endl; // Output: 1
    
    cout << "Dequeue: " << q.pop() << endl; // Output: 2
    
    cout << "Is the queue empty? " << (q.empty() ? "Yes" : "No") << endl; // Output: No
    
    cout << "Front of the queue: " << q.peek() << endl; // Output: 3
    
    cout << "Dequeue: " << q.pop() << endl; // Output: 3
    
    cout << "Is the queue empty? " << (q.empty() ? "Yes" : "No") << endl; // Output: Yes

    return 0;
}