// LC 5 - Longest Palindromic Substring

#include <bits/stdc++.h>
using namespace std;

string longestPalindrome(string s) {

    int n = s.length();

    int start = 0;
    int maxLen = 1;

    for (int center = 0; center < n; center++) {

        // Odd length palindrome
        int left = center;
        int right = center;

        while (left >= 0 && right < n && s[left] == s[right]) {

            if (right - left + 1 > maxLen) {
                maxLen = right - left + 1;
                start = left;
            }

            left--;
            right++;
        }

        // Even length palindrome
        left = center;
        right = center + 1;

        while (left >= 0 && right < n && s[left] == s[right]) {

            if (right - left + 1 > maxLen) {
                maxLen = right - left + 1;
                start = left;
            }

            left--;
            right++;
        }
    }

    return s.substr(start, maxLen);
}

int main() {

    string s;
    cin >> s;

    cout << longestPalindrome(s);

    return 0;
}