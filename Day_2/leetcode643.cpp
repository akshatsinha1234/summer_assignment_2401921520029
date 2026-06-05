#include <iostream>
#include <vector>
using namespace std;

double findMaxAverage(vector<int>& nums, int k) {
    int n = nums.size();
    int sum = 0;
    int osum = 0;

    
    for (int i = 0; i < k; i++) {
        osum += nums[i];
    }

    sum = osum;
    int maxi = sum;

    
    for (int j = k; j < n; j++) {
        sum = sum + nums[j] - nums[j - k];
        maxi = max(maxi, sum);
    }

    return (double)maxi / k;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << findMaxAverage(nums, k) << endl;

    return 0;
}