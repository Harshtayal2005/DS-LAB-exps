#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int performOperation(char operation, int operand1, int operand2) {
    switch (operation) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            if (operand2 != 0) {
                return operand1 / operand2;
            } else {
                cerr << "Error: Division by zero!" << endl;
                exit(1);
            }
        default:
            cerr << "Error: Invalid operator!" << endl;
            exit(1);
    }
}

int evaluatePostfixExpression(const char* expression) {
    stack<int> operands;

    int length = strlen(expression);

    for (int i = 0; i < length; i++) {
        if (isdigit(expression[i])) {
            operands.push(expression[i] - '0');
        } else if (isOperator(expression[i])) {
            int operand2 = operands.top();
            operands.pop();
            int operand1 = operands.top();
            operands.pop();
            int result = performOperation(expression[i], operand1, operand2);
            operands.push(result);
        } else if (expression[i] != ' ') {
            cerr << "Error: Invalid character in the expression!" << endl;
            exit(1);
        }
    }

    if (!operands.empty()) {
        return operands.top();
    } else {
        cerr << "Error: Invalid expression!" << endl;
        exit(1);
    }
}

int main() {
    const char* postfixExpression = "23*5+";
    int result = evaluatePostfixExpression(postfixExpression);
    cout << "Result: " << result << endl;
    return 0;
}
