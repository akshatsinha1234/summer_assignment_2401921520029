#include <iostream>
#include <vector>
using namespace std;

void reverseString(vector<char>& s) {
    int st = 0;
    int e = s.size() - 1;

    while (st < e) {
        swap(s[st], s[e]);
        st++;
        e--;
    }
}

int main() {
    int n;
    cin >> n;

    vector<char> s(n);

    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    reverseString(s);

    for (char ch : s) {
        cout << ch << " ";
    }

    cout << endl;

    return 0;
}