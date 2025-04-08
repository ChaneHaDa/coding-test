#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        v.push_back({a, b});
    }

    int d;
    cin >> d;

    sort(v.begin(), v.end(), [](pair<int, int>& a, pair<int, int>& b) {
        return a.second < b.second;
    });

    priority_queue<int, vector<int>, greater<int>> pq;
    int ans = 0;
    for (auto [s, e] : v) {
        if (e - s > d) continue;

        pq.push(s);
        while (!pq.empty() && pq.top() < e - d) {
            pq.pop();
        }
        ans = max(ans, (int)pq.size());
    }

    cout << ans << '\n';
    return 0;
}
