#include <bits/stdc++.h>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temp) {

    stack<int> st;
    vector<int> ans(temp.size(), 0);

    for (int i = temp.size() - 1; i >= 0; i--) {

        while (!st.empty() && temp[st.top()] <= temp[i]) {
            st.pop();
        }

        if (st.empty())
            ans[i] = 0;
        else
            ans[i] = st.top() - i;

        st.push(i);
    }

    return ans;
}

int main() {

    int n;
    cin >> n;

    vector<int> temp(n);

    for (int i = 0; i < n; i++)
        cin >> temp[i];

    vector<int> ans = dailyTemperatures(temp);

    for (int x : ans)
        cout << x << " ";

    return 0;
}