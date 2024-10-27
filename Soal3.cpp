#include <iostream>
#include <stack>
#include <cmath>
#include <string>
using namespace std;

class Stack {
public:
    void push(int value) { data.push(value); }
    void pop() { if (!data.empty()) data.pop(); }
    bool isEmpty() { return data.empty(); }
    int top() { return data.top(); }
private:
    stack<int> data;
};

int evaluatePostfix(string expression) {
    Stack s;
    for (char ch : expression) {
        if (isdigit(ch)) {
            s.push(ch - '0');
        } else {
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();
            switch (ch) {
                case '+': s.push(a + b); break;
                case '-': s.push(a - b); break;
                case '*': s.push(a * b); break;
                case '/': s.push(a / b); break;
                case '^': s.push(pow(a, b)); break;
            }
        }
    }
    return s.top();
}

int main() {
    string expression = "53+62/*35*+";
    cout << "Hasil evaluasi: " << evaluatePostfix(expression) << endl;
    return 0;
}
