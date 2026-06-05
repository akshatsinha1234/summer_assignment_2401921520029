#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string longestCommonPrefix(vector<string>& s) {
    string ans = "";
    int n = s.size();

    sort(s.begin(), s.end());

    int i = 0;
    while (i < s[0].length() && s[0][i] == s[n - 1][i]) {
        ans += s[0][i];
        i++;
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<string> s(n);

    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    cout << longestCommonPrefix(s) << endl;

    return 0;
}