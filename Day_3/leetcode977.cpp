#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> sortedSquares(vector<int>& nums) {
    int n = nums.size();
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        arr[i] = nums[i] * nums[i];
    }

    sort(arr.begin(), arr.end());

    return arr;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> result = sortedSquares(nums);

    for (int x : result) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}