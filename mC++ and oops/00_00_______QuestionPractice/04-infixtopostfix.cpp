#include <iostream>
#include <stack>
#include <string>
#include <cctype> //it has isaplha()

using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int precedence(char op) {
    switch (op) {
        case '^': return 3;
        //new trick unloked
        case '*': case '/': return 2;
        case '+': case '-': return 1;
        default: return 0; //when other operator
    }
}

string infixToPostFix(string str) {
    stack<char> s;
    string postfix;

    for (int i = 0; i < str.length(); i++) {
        char c = str[i]; //for clean interface

        if (isalnum(c)) {
            postfix.push_back(c); // operand goes directly
        }
        else if (c == '(') {
            s.push(c);
        }
        else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix.push_back(s.top());
                s.pop();
            }
            if (!s.empty()) s.pop(); // pop '(' at last
        }
        else if (isOperator(c)) {
            while (!s.empty() && precedence(s.top()) >= precedence(c)) {
                postfix.push_back(s.top());
                s.pop();
            }
            s.push(c);
        }
    }

    // empty stack
    while (!s.empty()) {
        postfix.push_back(s.top());
        s.pop();
    }

    return postfix;
}

int main() {
    string str = "M+X*(A+B)*(C-D)";
    cout << "Infix: " << str << endl;
    cout << "Postfix: " << infixToPostFix(str) << endl;
    return 0;
}
