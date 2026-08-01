#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

bool hasCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }

    return false;
}

int main() {
    int n;
    cin >> n;

    if (n == 0)
        return 0;

    vector<Node*> nodes;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nodes.push_back(new Node(x));
    }

    for (int i = 0; i < n - 1; i++) {
        nodes[i]->next = nodes[i + 1];
    }

    // Enter cycle position (-1 if no cycle)
    int pos;
    cin >> pos;

    if (pos != -1) {
        nodes[n - 1]->next = nodes[pos];
    }

    if (hasCycle(nodes[0]))
        cout << "true";
    else
        cout << "false";

    return 0;
}