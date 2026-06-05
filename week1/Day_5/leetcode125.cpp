#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool ischar(char ch) {
    if ((ch >= '0' && ch <= '9') ||
        (tolower(ch) >= 'a' && tolower(ch) <= 'z')) {
        return true;
    }
    return false;
}

bool isPalindrome(string s) {
    int st = 0;
    int e = s.length() - 1;

    while (st < e) {

        if (!ischar(s[st])) {
            st++;
            continue;
        }

        if (!ischar(s[e])) {
            e--;
            continue;
        }

        if (tolower(s[st]) != tolower(s[e])) {
            return false;
        }

        st++;
        e--;
    }

    return true;
}

int main() {
    string s;
    getline(cin, s);

    if (isPalindrome(s))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}