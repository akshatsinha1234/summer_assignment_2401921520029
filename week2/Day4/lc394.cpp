#include <bits/stdc++.h>
using namespace std;

string decodeString(string s) {

    stack<int> nums;
    stack<string> st;

    string curr = "";
    int num = 0;

    for (char ch : s) {

        if (isdigit(ch)) {
            num = num * 10 + (ch - '0');
        }
        else if (ch == '[') {

            nums.push(num);
            st.push(curr);

            num = 0;
            curr = "";
        }
        else if (ch == ']') {

            int k = nums.top();
            nums.pop();

            string prev = st.top();
            st.pop();

            while (k--) {
                prev += curr;
            }

            curr = prev;
        }
        else {
            curr += ch;
        }
    }

    return curr;
}

int main() {
    string s;
    cin >> s;

    cout << decodeString(s);

    return 0;
}