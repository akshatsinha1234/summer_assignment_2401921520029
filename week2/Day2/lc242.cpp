#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t) {
    int n = s.length();
    int m = t.length();

    if (n != m) {
        return false;
    }

    int count[26] = {0};

    for (int i = 0; i < n; i++) {
        count[s[i] - 'a']++;
        count[t[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++) {
        if (count[i] != 0) {
            return false;
        }
    }

    return true;
}

int main() {
    string s, t;

    cin >> s >> t;

    if (isAnagram(s, t))
        cout << "true";
    else
        cout << "false";

    return 0;
}