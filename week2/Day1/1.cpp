#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int n = s.length();

    int hash[256];
    memset(hash, -1, sizeof(hash));

    int l = 0, r = 0;
    int maxLen = 0;

    while (r < n) {
        if (hash[s[r]] != -1 && hash[s[r]] >= l) {
            l = hash[s[r]] + 1;
        }

        maxLen = max(maxLen, r - l + 1);

        hash[s[r]] = r;
        r++;
    }

    return maxLen;
}

int main() {
    string s;
    cin >> s;

    cout << lengthOfLongestSubstring(s);

    return 0;
}