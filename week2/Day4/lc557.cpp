#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s) {
    int n = s.length();

    int i = 0;
    int j = 0;
    int k;

    while (j < n) {

        if (s[j] != ' ') {
            j++;
        }

        if (j == n || s[j] == ' ') {

            k = j;
            j--;

            while (i <= j) {
                swap(s[i], s[j]);
                i++;
                j--;
            }

            i = k + 1;
            j = k + 1;
        }
    }

    return s;
}

int main() {
    string s;

    getline(cin, s);

    cout << reverseWords(s);

    return 0;
}