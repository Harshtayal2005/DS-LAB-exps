#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;
    Node(char value) : data(value), left(nullptr), right(nullptr) {}
};

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

Node* buildExpressionTree(string postfix) {
    stack<Node*> st;
    for (char ch : postfix) {
        if (isdigit(ch)) {
            st.push(new Node(ch));
        } else if (isOperator(ch)) {
            Node* rightOperand = st.top();
            st.pop();
            Node* leftOperand = st.top();
            st.pop();
            Node* newNode = new Node(ch);
            newNode->left = leftOperand;
            newNode->right = rightOperand;
            st.push(newNode);
        }
    }
    return st.top();
}

int evaluateExpressionTree(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    if (isdigit(root->data)) {
        return root->data - '0';
    }
    int leftValue = evaluateExpressionTree(root->left);
    int rightValue = evaluateExpressionTree(root->right);
    switch (root->data) {
        case '+':
            return leftValue + rightValue;
        case '-':
            return leftValue - rightValue;
        case '*':
            return leftValue * rightValue;
        case '/':
            return leftValue / rightValue;
        default:
            return 0;
    }
}

void deleteTree(Node* root) {
    if (root == nullptr) {
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    string postfixExpression = "23*5+";
    Node* root = buildExpressionTree(postfixExpression);
    cout << "Postfix Expression: " << postfixExpression << endl;
    int result = evaluateExpressionTree(root);
    cout << "Result: " << result << endl;

    // Cleanup: Delete the tree nodes
    deleteTree(root);

    return 0;
}
