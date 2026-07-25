#include <bits/stdc++.h>
using namespace std;

bool isSubsequence(string s, string t) {
    int n = s.length();
    int m = t.length();

    string ans;

    int i = 0;
    int j = 0;

    while (i < n && j < m) {

        if (s[i] == t[j]) {
            ans += t[j];
            i++;
        }

        j++;
    }

    return ans == s;
}

int main() {
    string s, t;

    cin >> s >> t;

    if (isSubsequence(s, t))
        cout << "true";
    else
        cout << "false";

    return 0;
}