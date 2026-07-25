#include <bits/stdc++.h>
using namespace std;

int firstUniqChar(string s) {
    unordered_map<char, int> mp;
    queue<int> q;

    for (int i = 0; i < s.length(); i++) {

        if (mp.find(s[i]) == mp.end()) {
            q.push(i);
        }

        mp[s[i]]++;

        while (!q.empty() && mp[s[q.front()]] > 1) {
            q.pop();
        }
    }

    if (q.empty())
        return -1;

    return q.front();
}

int main() {
    string s;
    cin >> s;

    cout << firstUniqChar(s);

    return 0;
}