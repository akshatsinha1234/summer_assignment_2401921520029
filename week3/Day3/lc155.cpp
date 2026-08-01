#include <bits/stdc++.h>
using namespace std;

class MinStack {

    stack<pair<int, int>> s;

public:

    void push(int val) {

        if (s.empty())
            s.push({val, val});
        else
            s.push({val, min(val, s.top().second)});
    }

    void pop() {
        if (!s.empty())
            s.pop();
    }

    int top() {
        return s.top().first;
    }

    int getMin() {
        return s.top().second;
    }
};

int main() {

    MinStack st;

    int q;
    cin >> q;

    while (q--) {

        string op;
        cin >> op;

        if (op == "push") {
            int x;
            cin >> x;
            st.push(x);
        }
        else if (op == "pop") {
            st.pop();
        }
        else if (op == "top") {
            cout << st.top() << endl;
        }
        else if (op == "getMin") {
            cout << st.getMin() << endl;
        }
    }

    return 0;
}