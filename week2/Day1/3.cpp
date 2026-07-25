#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> findAnagrams(string s, string p) {

    int m = s.length();
    int n = p.length();

    vector<int> ans;

    if (n > m)
        return ans;

    unordered_map<char, int> count1;
    unordered_map<char, int> count2;

    for (int i = 0; i < n; i++) {
        count1[p[i]]++;
        count2[s[i]]++;
    }

    int i = 0;

    while (i <= m - n) {

        if (count1 == count2)
            ans.push_back(i);

        i++;

        if (i + n - 1 < m) {

            count2[s[i - 1]]--;

            if (count2[s[i - 1]] == 0)
                count2.erase(s[i - 1]);

            count2[s[i + n - 1]]++;
        }
    }

    return ans;
}

int main() {
    string s, p;

    cin >> s >> p;

    vector<int> ans = findAnagrams(s, p);

    for (int x : ans)
        cout << x << " ";

    return 0;
}