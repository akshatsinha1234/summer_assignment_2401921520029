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

Node* mergeTwoLists(Node* head1, Node* head2) {

    if (head1 == NULL || head2 == NULL)
        return (head1 == NULL) ? head2 : head1;

    if (head1->data <= head2->data) {
        head1->next = mergeTwoLists(head1->next, head2);
        return head1;
    }
    else {
        head2->next = mergeTwoLists(head1, head2->next);
        return head2;
    }
}

int main() {

    int n1;
    cin >> n1;

    Node *head1 = NULL, *tail1 = NULL;

    for (int i = 0; i < n1; i++) {
        int x;
        cin >> x;

        Node* node = new Node(x);

        if (head1 == NULL)
            head1 = tail1 = node;
        else {
            tail1->next = node;
            tail1 = node;
        }
    }

    int n2;
    cin >> n2;

    Node *head2 = NULL, *tail2 = NULL;

    for (int i = 0; i < n2; i++) {
        int x;
        cin >> x;

        Node* node = new Node(x);

        if (head2 == NULL)
            head2 = tail2 = node;
        else {
            tail2->next = node;
            tail2 = node;
        }
    }

    Node* ans = mergeTwoLists(head1, head2);

    while (ans != NULL) {
        cout << ans->data << " ";
        ans = ans->next;
    }

    return 0;
}