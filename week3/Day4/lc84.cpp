#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int>& arr) {

    int n = arr.size();

    vector<int> pse(n), nse(n);
    stack<int> st;

    // Next Smaller Element
    for (int i = n - 1; i >= 0; i--) {

        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }

        nse[i] = st.empty() ? n : st.top();
        st.push(i);
    }

    while (!st.empty())
        st.pop();

    // Previous Smaller Element
    for (int i = 0; i < n; i++) {

        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }

        pse[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    int maxi = 0;

    for (int i = 0; i < n; i++) {

        int area = arr[i] * (nse[i] - pse[i] - 1);
        maxi = max(maxi, area);
    }

    return maxi;
}

int main() {

    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << largestRectangleArea(arr);

    return 0;
}