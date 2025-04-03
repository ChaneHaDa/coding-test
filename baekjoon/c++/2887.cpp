#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

int n;
vector<tuple<int, int, int>> node;
vector<int> parent;

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void merge(int x, int y) {
    int px = find(x);
    int py = find(y);
    if (px != py) {
        parent[px] = py;
    }
}

bool is_same_tree(int x, int y) {
    return find(x) == find(y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    node.resize(n);
    parent.resize(n);
    for (int i = 0; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        node[i] = {x, y, z};
        parent[i] = i;
    }

    vector<tuple<int, int, int>> edges;

    // x, y, z 축 정렬하여 인접 노드들만 간선 추가
    for (int axis = 0; axis < 3; axis++) {
        // {좌표값, index}
        vector<pair<int, int>> axisNodes(n); 
        for (int i = 0; i < n; i++) {
            int val;
            if (axis == 0) val = get<0>(node[i]);
            else if (axis == 1) val = get<1>(node[i]);
            else val = get<2>(node[i]);
            axisNodes[i] = {val, i};
        }

        sort(axisNodes.begin(), axisNodes.end());

        for (int i = 0; i < n - 1; i++) {
            int u = axisNodes[i].second;
            int v = axisNodes[i + 1].second;
            int cost = abs(axisNodes[i].first - axisNodes[i + 1].first);
            edges.push_back({cost, u, v});
        }
    }

    sort(edges.begin(), edges.end());
    long long ans = 0;
    int cnt = 0;

    for (auto [cost, u, v] : edges) {
        if (!is_same_tree(u, v)) {
            merge(u, v);
            ans += cost;
            cnt++;
            if (cnt == n - 1) break;
        }
    }

    cout << ans << '\n';
    return 0;
}