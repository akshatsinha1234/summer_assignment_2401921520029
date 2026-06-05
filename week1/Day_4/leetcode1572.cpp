#include <iostream>
#include <vector>
using namespace std;

int diagonalSum(vector<vector<int>>& a) {
    int n = a.size();
    int s = 0;

    // Primary diagonal
    for (int i = 0; i < n; i++) {
        s += a[i][i];
    }

    // Secondary diagonal
    for (int i = 0, j = n - 1; i < n; i++, j--) {
        s += a[i][j];
    }

    // Remove center element if n is odd
    if (n % 2 != 0) {
        s -= a[(n - 1) / 2][(n - 1) / 2];
    }

    return s;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> a(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    cout << diagonalSum(a) << endl;

    return 0;
}