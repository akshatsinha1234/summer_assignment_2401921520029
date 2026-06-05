#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxArea(vector<int>& height) {
    int n = height.size();
    int lp = 0;
    int rp = n - 1;

    int ans = 0;

    while (lp < rp) {
        int w = rp - lp;
        int ht = min(height[lp], height[rp]);
        int curr = w * ht;

        ans = max(ans, curr);

        if (height[lp] < height[rp]) {
            lp++;
        } else if (height[lp] > height[rp]) {
            rp--;
        } else {
            lp++;
        }
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> height(n);

    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }

    cout << maxArea(height) << endl;

    return 0;
}