#include <bits/stdc++.h>
using namespace std;

class MyQueue {
    stack<int> s1, s2;

public:
    void push(int x) {

        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        s2.push(x);

        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop() {
        int x = s1.top();
        s1.pop();
        return x;
    }

    int peek() {
        return s1.top();
    }

    bool empty() {
        return s1.empty();
    }
};

int main() {

    MyQueue q;

    int n;
    cin >> n;

    while (n--) {

        string op;
        cin >> op;

        if (op == "push") {
            int x;
            cin >> x;
            q.push(x);
        }
        else if (op == "pop") {
            cout << q.pop() << endl;
        }
        else if (op == "peek") {
            cout << q.peek() << endl;
        }
        else if (op == "empty") {
            cout << (q.empty() ? "true" : "false") << endl;
        }
    }

    return 0;
}