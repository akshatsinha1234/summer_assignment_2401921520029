#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int sum = 0;
    int maxi = INT_MIN;

    for (int num : nums) {
        sum += num;
        maxi = max(maxi, sum);

        if (sum < 0) {
            sum = 0;
        }
    }

    return maxi;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << maxSubArray(nums) << endl;

    return 0;
}