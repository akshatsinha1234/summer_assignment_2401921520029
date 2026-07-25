// LC 49 - Group Anagrams

#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {

    unordered_map<string, vector<string>> mp;
    vector<vector<string>> ans;

    for (int i = 0; i < strs.size(); i++) {

        int freq[26] = {0};

        for (char ch : strs[i]) {
            freq[ch - 'a']++;
        }

        string key;

        for (int j = 0; j < 26; j++) {
            key += "#";
            key += to_string(freq[j]);
        }

        mp[key].push_back(strs[i]);
    }

    for (auto &it : mp) {
        ans.push_back(it.second);
    }

    return ans;
}

int main() {

    int n;
    cin >> n;

    vector<string> strs(n);

    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }

    vector<vector<string>> ans = groupAnagrams(strs);

    for (auto group : ans) {
        for (string word : group) {
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;
}