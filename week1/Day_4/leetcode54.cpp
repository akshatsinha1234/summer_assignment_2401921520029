#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& a) {
    int m = a.size();
    int n = a[0].size();

    vector<int> ans;

    int srow = 0, erow = m - 1;
    int scol = 0, ecol = n - 1;

    while (srow <= erow && scol <= ecol) {

        // Top
        for (int j = scol; j <= ecol; j++) {
            ans.push_back(a[srow][j]);
        }

        // Right
        for (int i = srow + 1; i <= erow; i++) {
            ans.push_back(a[i][ecol]);
        }

        // Bottom
        for (int j = ecol - 1; j >= scol; j--) {
            if (erow == srow) {
                break;
            }
            ans.push_back(a[erow][j]);
        }

        // Left
        for (int i = erow - 1; i >= srow + 1; i--) {
            if (scol == ecol) {
                break;
            }
            ans.push_back(a[i][scol]);
        }

        srow++;
        erow--;
        scol++;
        ecol--;
    }

    return ans;
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> a(m, vector<int>(n));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    vector<int> result = spiralOrder(a);

    for (int x : result) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}