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

Node* removeNthFromEnd(Node* head, int n) {

    Node *prev = NULL;
    Node *curr = head;
    Node *temp = head;

    int len = 0;

    while (temp != NULL) {
        len++;
        temp = temp->next;
    }

    temp = head;

    int node = len - n;

    if (node == 0) {
        head = head->next;
        delete temp;
        return head;
    }

    int idx = 0;

    while (idx != node) {
        prev = curr;
        curr = curr->next;
        idx++;
    }

    prev->next = curr->next;
    delete curr;

    return head;
}

int main() {

    int n;
    cin >> n;

    Node *head = NULL, *tail = NULL;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        Node* node = new Node(x);

        if (head == NULL)
            head = tail = node;
        else {
            tail->next = node;
            tail = node;
        }
    }

    int k;
    cin >> k;

    head = removeNthFromEnd(head, k);

    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }

    return 0;
}