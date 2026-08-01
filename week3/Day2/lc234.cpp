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

bool isPalindrome(Node* head) {

    vector<int> arr;

    Node* temp = head;

    while (temp != NULL) {
        arr.push_back(temp->data);
        temp = temp->next;
    }

    int i = 0;
    int j = arr.size() - 1;

    while (i <= j) {
        if (arr[i] != arr[j])
            return false;

        i++;
        j--;
    }

    return true;
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

    if (isPalindrome(head))
        cout << "true";
    else
        cout << "false";

    return 0;
}