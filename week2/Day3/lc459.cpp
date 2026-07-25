#include <bits/stdc++.h>
using namespace std;

bool repeatedSubstringPattern(string s) {
    int n = s.length();

    for (int len = 1; len <= n / 2; len++) {

        if (n % len != 0)
            continue;

        bool ok = true;

        for (int i = len; i < n; i++) {
            if (s[i] != s[i % len]) {
                ok = false;
                break;
            }
        }

        if (ok)
            return true;
    }

    return false;
}

int main() {
    string s;
    cin >> s;

    if (repeatedSubstringPattern(s))
        cout << "true";
    else
        cout << "false";

    return 0;
}