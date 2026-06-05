#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int n = nums.size();
    int i = 0;

    for (int j = 1; j < n; j++) {
        if (nums[i] == 0 && nums[j] != 0) {
            swap(nums[i], nums[j]);
            i++;
        } else if (nums[i] != 0) {
            i++;
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    moveZeroes(nums);

    for (int num : nums) {
        cout << num << " ";
    }

    cout << endl;

    return 0;
}