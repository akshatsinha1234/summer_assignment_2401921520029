#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        unordered_map<int, int> m;

        for (int i = 0; i < arr.size(); i++) {
            int first = arr[i];
            int sec = target - first;

            if (m.find(sec) != m.end()) {
                return {m[sec], i};
            }

            m[first] = i;
        }

        return {};
    }
};

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    Solution sol;
    vector<int> ans = sol.twoSum(nums, target);

    cout << "Indices: ";
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}