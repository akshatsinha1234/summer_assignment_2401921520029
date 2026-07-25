#include <bits/stdc++.h>
using namespace std;

bool canConstruct(string ransomNote, string magazine) {
    int count1[26] = {0};
    int count2[26] = {0};

    for (char ch : ransomNote)
        count1[ch - 'a']++;

    for (char ch : magazine)
        count2[ch - 'a']++;

    for (int i = 0; i < 26; i++) {
        if (count1[i] > count2[i])
            return false;
    }

    return true;
}

int main() {
    string ransomNote, magazine;

    cin >> ransomNote >> magazine;

    if (canConstruct(ransomNote, magazine))
        cout << "true";
    else
        cout << "false";

    return 0;
}