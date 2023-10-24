#include <iostream>
#include <stack>
using namespace std;

class MinStack {
public:
    stack<int> mainStack;
    int minElement;

    MinStack() {
        minElement = INT_MAX;
    }

    void push(int x) {
        if (x <= minElement) {
            mainStack.push(minElement);
            minElement = x;
        }
        mainStack.push(x);
    }

    void pop() {
        if (mainStack.top() == minElement) {
            mainStack.pop();
            minElement = mainStack.top();
            mainStack.pop();
        } else {
            mainStack.pop();
        }
    }

    int top() {
        return mainStack.top();
    }

    int getMin() {
        return minElement;
    }
};

int main() {
    MinStack minStack;
    minStack.push(3);
    minStack.push(5);
    cout << "Minimum element: " << minStack.getMin() << endl; // Output: 3
    minStack.push(2);
    cout << "Minimum element: " << minStack.getMin() << endl; // Output: 2
    minStack.pop();
    cout << "Top element: " << minStack.top() << endl; // Output: 5
    cout << "Minimum element: " << minStack.getMin() << endl; // Output: 3

    return 0;
}
