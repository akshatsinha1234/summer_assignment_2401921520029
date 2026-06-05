#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
    if (mat.size() * mat[0].size() != r * c)
        return mat;

    vector<vector<int>> rmat(r, vector<int>(c));

    int m = mat.size();
    int n = mat[0].size();

    vector<int> arr(m * n);

    int c1 = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            arr[c1++] = mat[i][j];
        }
    }

    c1 = 0;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            rmat[i][j] = arr[c1++];
        }
    }

    return rmat;
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> mat(m, vector<int>(n));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    int r, c;
    cin >> r >> c;

    vector<vector<int>> result = matrixReshape(mat, r, c);

    for (auto& row : result) {
        for (int x : row) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}