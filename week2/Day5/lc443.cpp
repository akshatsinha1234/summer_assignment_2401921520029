// LC 443 - String Compression

#include <bits/stdc++.h>
using namespace std;

int compress(vector<char>& chars) {

    int idx = 0;
    int n = chars.size();

    for (int i = 0; i < n; i++) {

        char ch = chars[i];
        int count = 0;

        while (i < n && chars[i] == ch) {
            count++;
            i++;
        }

        chars[idx++] = ch;

        if (count > 1) {
            string str = to_string(count);

            for (char digit : str) {
                chars[idx++] = digit;
            }
        }

        i--;
    }

    chars.resize(idx);

    return idx;
}

int main() {

    int n;
    cin >> n;

    vector<char> chars(n);

    for (int i = 0; i < n; i++) {
        cin >> chars[i];
    }

    int len = compress(chars);

    cout << len << endl;

    for (char ch : chars) {
        cout << ch << " ";
    }

    return 0;
}