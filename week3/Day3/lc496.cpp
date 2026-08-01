#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

    unordered_map<int, int> mp;
    stack<int> st;

    for (int i = nums2.size() - 1; i >= 0; i--) {

        while (!st.empty() && st.top() <= nums2[i]) {
            st.pop();
        }

        if (st.empty())
            mp[nums2[i]] = -1;
        else
            mp[nums2[i]] = st.top();

        st.push(nums2[i]);
    }

    vector<int> ans;

    for (int x : nums1)
        ans.push_back(mp[x]);

    return ans;
}

int main() {

    int n1;
    cin >> n1;

    vector<int> nums1(n1);
    for (int i = 0; i < n1; i++)
        cin >> nums1[i];

    int n2;
    cin >> n2;

    vector<int> nums2(n2);
    for (int i = 0; i < n2; i++)
        cin >> nums2[i];

    vector<int> ans = nextGreaterElement(nums1, nums2);

    for (int x : ans)
        cout << x << " ";

    return 0;
}