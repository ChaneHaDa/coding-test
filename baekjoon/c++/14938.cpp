#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, r;
    cin >> n >> m >> r;

    vector<int> items(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> items[i];
    }

    vector<vector<pair<int, int>>> graph(n + 1);
    for (int i = 0; i < r; ++i) {
        int a, b, l;
        cin >> a >> b >> l;
        graph[a].push_back({b, l});
        graph[b].push_back({a, l});
    }

    int answer = 0;

    for (int start = 1; start <= n; ++start) {
        vector<int> dist(n + 1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        dist[start] = 0;
        pq.push({0, start});

        while (!pq.empty()) {
            auto [d, now] = pq.top(); pq.pop();

            if (d > dist[now]) continue;

            for (auto [next, cost] : graph[now]) {
                if (dist[next] > d + cost) {
                    dist[next] = d + cost;
                    pq.push({dist[next], next});
                }
            }
        }

        int sum = 0;
        for (int i = 1; i <= n; ++i) {
            if (dist[i] <= m) {
                sum += items[i];
            }
        }

        answer = max(answer, sum);
    }

    cout << answer << '\n';
    return 0;
}
