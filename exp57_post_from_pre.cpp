#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

bool isOperand(char c) {
    return (c >= '0' && c <= '9');
}

void postorderToPreorder(const char* postorder) {
    stack<string> s;
    int length = strlen(postorder);

    for (int i = 0; i < length; ++i) {
        if (isOperand(postorder[i])) {
            string operand(1, postorder[i]);
            s.push(operand);
        } else if (isOperator(postorder[i])) {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            string expression = string(1, postorder[i]) + op2 + op1;
            s.push(expression);
        } else if (postorder[i] != ' ') {
            cerr << "Error: Invalid character in the expression!" << endl;
            exit(1);
        }
    }

    string preorder = s.top();
    cout << "Preorder expression: " << preorder << endl;
}

int main() {
    const char* postorder = "42*3+";
    cout << "Postorder expression: " << postorder << endl; // Output: 42*3+
    postorderToPreorder(postorder); // Output: +*42 3

    return 0;
}
