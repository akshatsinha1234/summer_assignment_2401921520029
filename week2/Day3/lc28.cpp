#include <bits/stdc++.h>
using namespace std;

int strStr(string haystack, string needle) {
    int s = haystack.length();
    int m = needle.length();

    int i = 0;
    int j = 0;
    int k = 0;

    while (i < s && j < m) {

        if (haystack[i] == needle[j]) {
            i++;
            j++;
        } else {
            k++;
            i = k;
            j = 0;
        }

        if (j == m) {
            return i - m;
        }
    }

    return -1;
}

int main() {
    string haystack, needle;

    cin >> haystack >> needle;

    cout << strStr(haystack, needle);

    return 0;
}