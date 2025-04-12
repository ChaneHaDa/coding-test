#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool dfs(int x, int flag, vector<vector<int>>& g, vector<int>& visit) {
    visit[x] = flag;
    for (auto nx : g[x]) {
        if (visit[nx] == 0) {
            if (!dfs(nx, -flag, g, visit))
                return false;
        } else if (visit[nx] == flag) {
            return false;
        }
    }
    return true;
}

string solve() {
    int v, e;
    cin >> v >> e;

    vector<vector<int>> g(v + 1);
    while (e--) {
        int u, w;
        cin >> u >> w;
        g[u].push_back(w);
        g[w].push_back(u);
    }

    vector<int> visit(v + 1, 0);
    bool isBipartite = true;

    for (int i = 1; i <= v; i++) {
        if (visit[i] == 0) {
            if (!dfs(i, 1, g, visit)) {
                isBipartite = false;
                break;
            }
        }
    }

    return isBipartite ? "YES" : "NO";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int k;
    cin >> k;

    vector<string> ans;
    while (k--) {
        ans.push_back(solve());
    }

    for (auto s : ans) {
        cout << s << '\n';
    }

    return 0;
}
