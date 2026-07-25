#include <iostream>
using namespace std;

bool isSame(int freq1[], int freq2[]) {
    for (int i = 0; i < 26; i++) {
        if (freq1[i] != freq2[i])
            return false;
    }
    return true;
}

bool checkInclusion(string s1, string s2) {
    int freq[26] = {0};

    int n = s1.length();
    int m = s2.length();

    if (n > m)
        return false;

    for (int i = 0; i < n; i++)
        freq[s1[i] - 'a']++;

    int winSize = n;

    for (int i = 0; i < m; i++) {

        int windowFreq[26] = {0};

        int idx = i;
        int cnt = 0;

        while (cnt < winSize && idx < m) {
            windowFreq[s2[idx] - 'a']++;
            cnt++;
            idx++;
        }

        if (isSame(freq, windowFreq))
            return true;
    }

    return false;
}

int main() {
    string s1, s2;

    cin >> s1 >> s2;

    if (checkInclusion(s1, s2))
        cout << "true";
    else
        cout << "false";

    return 0;
}