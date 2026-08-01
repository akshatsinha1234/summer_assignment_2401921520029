#include <bits/stdc++.h>
using namespace std;

class RecentCounter {

    queue<int> q;

public:

    int ping(int t) {

        q.push(t);

        while (!q.empty() && q.front() < t - 3000) {
            q.pop();
        }

        return q.size();
    }
};

int main() {

    RecentCounter rc;

    int n;
    cin >> n;

    while (n--) {

        int t;
        cin >> t;

        cout << rc.ping(t) << endl;
    }

    return 0;
}